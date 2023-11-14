import {
	Args,
	Mutation,
	Parent,
	Query,
	ResolveField,
	Resolver,
	Subscription,
} from '@nestjs/graphql';
import { UserService } from './user.service';
import { User } from './entities/user.entity';
import { Avatar } from './entities/avatar.entity';
import { CreateUserInput } from './dto/create-user.input';
import { UseGuards } from '@nestjs/common';
import {
	JwtAuthGuard,
	JwtSubscriptionGuard,
} from 'src/auth/guards/jwt-auth.guard';
import { AuthUser } from 'src/auth/decorators/auth-user.decorator';
import { UserInfo } from 'src/auth/user-info.interface';
import { UserAvatarService } from './user-avatar.service';
import { ChangeUserDataInput } from './dto/change-user-data-input';
import { pubSub } from 'src/app.module';
import { getSubscriptionUser } from 'src/utils/getSubscriptionUser';
import {
	MultiBlockStateChange,
	MultiBlockStateChangeInput,
} from './dto/multi-block-state-change.dto';
import { GraphQLError } from 'graphql';
import { MessageReceivedSubscription } from './dto/message-received-subscrption.dto';

@Resolver(() => User)
export class UserResolver {
	constructor(
		private userService: UserService,
		private userAvatarService: UserAvatarService,
	) {}

	@Query(() => [User])
	async allUsersQuery() {
		return this.userService.getAllUsers();
	}

	@Query(() => User)
	async userQuery(@Args('userId', { type: () => String }) userId: string) {
		const user = await this.userService.getUserById(userId);
		if (user) return user;
		return null;
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => User)
	async currentUserQuery(@AuthUser() user: UserInfo) {
		return this.userService.getUserById(user.userUid);
	}

	@Query(() => User)
	async queryUserByName(
		@Args('username', { type: () => String }) username: string,
	) {
		const user = await this.userService.getUser(username);
		if (!user) throw new Error('User not found');
		return user;
	}

	@Mutation(() => User)
	async createUser(
		@Args('createUserInput') createUserInput: CreateUserInput,
	) {
		return this.userService.create(createUserInput);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => User)
	async changeUserData(
		@AuthUser() userInfo: UserInfo,
		@Args('changeUserData') changeUserData: ChangeUserDataInput,
	) {
		const user = await this.userService.getUserById(userInfo.userUid);
		if (changeUserData.avatar) {
			changeUserData.avatar.parentUserUid = userInfo.userUid;
			user.avatar = await this.userAvatarService.createOrUpdate(
				changeUserData.avatar,
			);
		}
		if (changeUserData.username) {
			const otherUser = await this.userService.getUser(
				changeUserData.username,
			);
			if (otherUser && otherUser.id != user.id) {
				throw new GraphQLError('A user already has this name', {
					extensions: {
						code: 'PREEXISTING_USERNAME',
					},
				});
			}
			user.username = changeUserData.username;
		}
		await this.userService.save(user);
		return await this.userService.getUserById(userInfo.userUid);
	}

	@ResolveField('avatar', () => Avatar)
	async getAvatar(@Parent() user: User) {
		return this.userAvatarService.getAvatar(user.id);
	}

	@ResolveField()
	async group_chats(@Parent() user: User) {
		return this.userService.getGroupChats(user);
	}

	@ResolveField()
	async personal_chats(@Parent() user: User) {
		return this.userService.getPersonalChats(user);
	}

	@Query(() => [User])
	@UseGuards(JwtAuthGuard)
	async all_available_personal_chats(@AuthUser() userInfo: UserInfo) {
		return this.userService.getAvailablePersonalChats(userInfo.userUid);
	}

	@Query(() => [User])
	async getFriends(@Args('user_id') user_id: string) {
		return this.userService.getFriends(user_id);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => [User])
	async getIncomingFriendRequest(@AuthUser() userInfo: UserInfo) {
		return this.userService.getIncomingFriendRequest(userInfo.userUid);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => [User])
	async getOutgoingFriendRequest(@AuthUser() userInfo: UserInfo) {
		return this.userService.getOutgoingFriendRequest(userInfo.userUid);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean)
	async inviteFriend(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.userService.inviteFriend(userInfo.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => User)
	async acceptFriend(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.userService.acceptFriend(userInfo.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean)
	async removeFriend(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.userService.removeFriend(userInfo.userUid, friend_id);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => User)
	async denyFriend(
		@AuthUser() userInfo: UserInfo,
		@Args('friend_id') friend_id: string,
	) {
		return this.userService.denyFriend(userInfo.userUid, friend_id);
	}

	@Subscription(() => User, {
		filter: async (payload, variables) => {
			return (
				(await variables.user_id) ===
				payload.outgoingFriendRequestChanged.id
			);
		},
	})
	async outgoingFriendRequestChanged(@Args('user_id') user_id: string) {
		return pubSub.asyncIterator('outgoingFriendRequestChanged');
	}

	@Subscription(() => User, {
		filter: async (payload, variables) => {
			return (
				(await variables.user_id) ===
				payload.incomingFriendRequestChanged.id
			);
		},
	})
	async incomingFriendRequestChanged(@Args('user_id') user_id: string) {
		return pubSub.asyncIterator('incomingFriendRequestChanged');
	}

	@Subscription(() => [User], {
		filter: async (payload, variables) => {
			return (await variables.user_id) === payload.id;
		},
	})
	async friendsChanged(@Args('user_id') user_id: string) {
		return pubSub.asyncIterator('friendsChanged');
	}

	@UseGuards(JwtAuthGuard)
	@ResolveField()
	async blocked_users(@Parent() user: User, @AuthUser() user_info: UserInfo) {
		if (user.id !== user_info.userUid) {
			throw 'Cannot only access your own blocked_users';
		}
		return this.userService.getBlockedUsers(user);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean)
	async block_user(
		@AuthUser() user: UserInfo,
		@Args('username') username: string,
	) {
		return this.userService.blockUser(user.userUid, username);
	}

	@UseGuards(JwtAuthGuard)
	@Mutation(() => Boolean)
	async unblock_user(
		@AuthUser() user: UserInfo,
		@Args('username') username: string,
	) {
		return this.userService.unblockUser(user.userUid, username);
	}

	@UseGuards(JwtAuthGuard)
	@ResolveField()
	async blocked_by_me(@AuthUser() me: UserInfo, @Parent() user: User) {
		const user_with_block = await this.userService.getUserById(user.id, {
			blocked_by: true,
		});
		return user_with_block.blocked_by.some(
			(blocker) => blocker.id === me.userUid,
		);
	}

	@UseGuards(JwtAuthGuard)
	@Query(() => Boolean)
	async is_user_blocked(
		@AuthUser() me: UserInfo,
		@Args('user_id') user_id: string,
	) {
		const user = await this.userService.getUserById(user_id, {
			blocked_by: true,
		});
		return user.blocked_by.some((blocker) => blocker.id === me.userUid);
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => Boolean, {
		filter: (payload, variables, context) => {
			const user = getSubscriptionUser(context);
			return (
				payload.blocked_id === variables.user_id &&
				payload.by_user_id === user.userUid
			);
		},
	})
	async block_state_changed(@Args('user_id') _user_id: string) {
		return pubSub.asyncIterator('block_state_changed');
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => MultiBlockStateChange, {
		filter: (payload, variables, context) => {
			const user = getSubscriptionUser(context);
			return (
				variables.user_ids.includes(payload.blocked_id) &&
				payload.by_user_id === user.userUid
			);
		},
		resolve(payload) {
			return {
				user_id: payload.blocked_id,
				blocked: payload.block_state_changed,
			};
		},
	})
	async multi_block_state_changed(
		@Args() _input: MultiBlockStateChangeInput,
	) {
		return pubSub.asyncIterator('block_state_changed');
	}

	@UseGuards(JwtSubscriptionGuard)
	@Subscription(() => MessageReceivedSubscription, {
		filter: (payload, _, context) => {
			const user = getSubscriptionUser(context);
			return payload.user_id === user.userUid;
		},
	})
	async message_received() {
		return pubSub.asyncIterator('message_received');
	}
}
