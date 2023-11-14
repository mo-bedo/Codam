import { Args, Mutation, Resolver, Subscription, Query } from '@nestjs/graphql';
import { QueueService } from './queue.service';
import { pubSub } from 'src/app.module';
import { QueuedMatch } from './queuedmatch.model';
import {
	JwtAuthGuard,
	JwtSubscriptionGuard,
} from 'src/auth/guards/jwt-auth.guard';
import { UseGuards } from '@nestjs/common';
import { AuthUser } from 'src/auth/decorators/auth-user.decorator';
import { UserInfo } from 'src/auth/user-info.interface';
import { Availability } from './queuestatus.model';
import { getSubscriptionUser } from 'src/utils/getSubscriptionUser';
import { User } from 'src/user/entities/user.entity';

@Resolver()
export class QueueResolver {
	constructor(private queueService: QueueService) {}

	@UseGuards(JwtAuthGuard)
	@Query(() => Availability)
	async getQueueAvailability(@AuthUser() user: UserInfo) {
		return await this.queueService.getQueueAvailability(user.userUid);
	}

	@Query(() => Availability)
	async getStatus(@Args('user_id') user_id: string) {
		return this.queueService.getStatus(user_id);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => Availability)
	async getOwnChallengeAvailability(@AuthUser() user: UserInfo) {
		return await this.queueService.getChallengeAvailability(user.userUid);
	}

	@Query(() => Availability)
	async getChallengeAvailability(@Args('friendId') friendId: string) {
		return await this.queueService.getChallengeAvailability(friendId);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => User, { nullable: true })
	async getIncomingChallenge(@AuthUser() user: UserInfo) {
		return await this.queueService.getIncomingChallenge(user.userUid);
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => User, {
		async filter(payload, variables, context) {
			const user = getSubscriptionUser(context);
			return payload.userId === user.userUid;
		},
		nullable: true,
	})
	incomingChallenge() {
		return pubSub.asyncIterator('incomingChallenge');
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => String, {
		async filter(payload, variables, context) {
			const user = getSubscriptionUser(context);
			return payload.userId === user.userUid;
		},
		nullable: true,
	})
	removedFromQueue() {
		return pubSub.asyncIterator('removedFromQueue');
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => String, {
		async filter(payload, variables, context) {
			const user = getSubscriptionUser(context);
			return payload.userId === user.userUid;
		},
		nullable: true,
	})
	removedMatch() {
		return pubSub.asyncIterator('removedMatch');
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean)
	async acceptChallenge(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.queueService.acceptChallenge(userInfo.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean, { nullable: true })
	async denyChallenge(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.queueService.denyChallenge(userInfo.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => User)
	async getChallenge(@AuthUser() user: UserInfo) {
		return await this.queueService.getChallengeAvailability(user.userUid);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean, { nullable: true })
	async challengeFriend(
		@AuthUser() user: UserInfo,
		@Args('friendId') friend_id: string,
	) {
		return this.queueService.challengeFriend(user.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean, { nullable: true })
	async joinQueue(@AuthUser() user: UserInfo) {
		return await this.queueService.joinQueue(user.userUid);
	}

	@Subscription(() => [QueuedMatch])
	queueChanged() {
		return pubSub.asyncIterator('queueChanged');
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => Availability, {
		async filter(payload, variables, context) {
			const user = getSubscriptionUser(context);
			return payload.userId === user.userUid;
		},
	})
	ownChallengeAvailabilityChanged() {
		return pubSub.asyncIterator('ownChallengeAvailabilityChanged');
	}

	@Subscription(() => Availability, {
		filter: async (payload, variables) => {
			return payload.userId === variables.friend_id;
		},
	})
	challengeAvailabilityChanged(@Args('friend_id') friend_id: string) {
		return pubSub.asyncIterator('challengeAvailabilityChanged');
	}

	@Subscription(() => Availability, {
		filter: async (payload, variables) => {
			return payload.userId === variables.userId;
		},
	})
	queueAvailabilityChanged(@Args('userId') userId: string) {
		return pubSub.asyncIterator('queueAvailabilityChanged');
	}

	@Query(() => [QueuedMatch])
	getWholeQueue() {
		return this.queueService.getWholeQueue();
	}
}
