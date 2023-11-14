import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { User } from './entities/user.entity';
import { CreateUserInput } from './dto/create-user.input';
import { GroupChat } from 'src/chat/group/chat/entities/group_chat.entity';
import { PersonalChat } from 'src/chat/personal/chat/entities/personal_chat.entity';
import { Match } from 'src/pong/match/entities/match.entity';
import { pubSub } from 'src/app.module';

@Injectable()
export class UserService {
	constructor(
		@InjectRepository(User)
		private readonly userRepository: Repository<User>,
	) {}

	async getAllUsers(): Promise<Array<User>> {
		return this.userRepository.find();
	}

	async getUser(usernameParam: string): Promise<User> {
		return this.userRepository.findOne({
			where: { username: usernameParam },
		});
	}

	async getUserById(id: string, relations = {}): Promise<User> {
		return this.userRepository.findOne({
			relations,
			where: { id: id },
		});
	}

	async getUserByIntraId(intraId: string, relations = {}) {
		return this.userRepository.findOne({
			relations,
			where: { intraId: intraId },
		});
	}

	async create(createUserInput: CreateUserInput): Promise<User> {
		const user = this.userRepository.create(createUserInput);
		return await this.userRepository.save(user);
	}

	async setTwoFA(secret: string, user: User): Promise<User> {
		user.twoFASecret = secret;
		user.twoFAEnabled = true;
		return await this.userRepository.save(user);
	}

	async unsetTwoFA(user: User): Promise<User> {
		user.twoFASecret = null;
		user.twoFAEnabled = false;
		return await this.userRepository.save(user);
	}

	async getGroupChats(user: User): Promise<Array<GroupChat>> {
		const user_with_channels = await this.userRepository.findOne({
			relations: { group_chats: true },
			where: { id: user.id },
		});
		return user_with_channels.group_chats;
	}

	async getPersonalChats(user: User): Promise<Array<PersonalChat>> {
		const user_with_channels = await this.userRepository.findOne({
			relations: ['personal_chats', 'personal_chats.members'],
			where: { id: user.id },
		});
		return user_with_channels.personal_chats;
	}

	async getAvailablePersonalChats(id: string): Promise<Array<User>> {
		const user = await this.getUserById(id);
		const userChannels = await this.getPersonalChats(user);
		const currentChatUsersIds = userChannels.flatMap((channel) =>
			channel.members.map((member) => member.id),
		);
		const availableUsers = await this.getAllUsers();
		const availableChatUsers = availableUsers.filter(
			(user) => !currentChatUsersIds.includes(user.id) && user.id !== id,
		);
		return availableChatUsers;
	}

	async getMatchHistory(user: User): Promise<Array<Match>> {
		const userMatchHistory = await this.userRepository.findOne({
			relations: ['match_history', 'match_history.players'],
			where: { id: user.id },
		});
		return userMatchHistory.match_history;
	}

	async save(user: User): Promise<User> {
		return await this.userRepository.save(user);
	}

	async denyFriend(user_id: string, friend_id: string) {
		const user = await this.userRepository.findOne({
			relations: { incoming_friend_requests: true },
			where: { id: user_id },
		});
		for (let i = 0; i < user.incoming_friend_requests.length; i++) {
			if (user.incoming_friend_requests[i].id === friend_id) {
				user.incoming_friend_requests.splice(i, 1);
				break;
			}
		}
		const friend = await this.userRepository.findOne({
			relations: { outgoing_friend_requests: true },
			where: { id: friend_id },
		});
		for (let i = 0; i < friend.outgoing_friend_requests.length; i++) {
			if (friend.outgoing_friend_requests[i].id === user_id) {
				friend.outgoing_friend_requests.splice(i, 1);
				break;
			}
		}
		await this.userRepository.save([user, friend]);
		pubSub.publish('outgoingFriendRequestChanged', {
			outgoingFriendRequestChanged: friend,
		});
		pubSub.publish('incomingFriendRequestChanged', {
			incomingFriendRequestChanged: user,
		});
		return user;
	}

	async acceptFriend(user_id: string, friend_id: string): Promise<User> {
		const user = await this.userRepository.findOne({
			relations: { friends: true, incoming_friend_requests: true },
			where: { id: user_id },
		});
		const friend = await this.userRepository.findOne({
			relations: { friends: true, outgoing_friend_requests: true },
			where: { id: friend_id },
		});
		friend.friends.push(user);
		user.friends.push(friend);
		for (let i = 0; i < user.incoming_friend_requests.length; i++) {
			if (user.incoming_friend_requests[i].id === friend_id) {
				user.incoming_friend_requests.splice(i, 1);
			}
		}
		for (let i = 0; i < friend.outgoing_friend_requests.length; i++) {
			if (friend.outgoing_friend_requests[i].id === user_id) {
				friend.outgoing_friend_requests.splice(i, 1);
			}
		}
		await this.userRepository.save([user, friend]);
		pubSub.publish('outgoingFriendRequestChanged', {
			outgoingFriendRequestChanged: friend,
		});
		pubSub.publish('incomingFriendRequestChanged', {
			incomingFriendRequestChanged: user,
		});
		pubSub.publish('friendsChanged', {
			friendsChanged: user.friends,
			id: user.id,
		});
		pubSub.publish('friendsChanged', {
			friendsChanged: friend.friends,
			id: friend_id,
		});
		return user;
	}

	async removeFriend(user_id: string, friend_id: string) {
		const user = await this.userRepository.findOne({
			relations: { friends: true },
			where: { id: user_id },
		});
		for (let i = 0; i < user.friends.length; i++) {
			if (user.friends[i].id === friend_id) {
				user.friends.splice(i, 1);
			}
		}
		const friend = await this.userRepository.findOne({
			relations: { friends: true },
			where: { id: friend_id },
		});
		for (let i = 0; i < friend.friends.length; i++) {
			if (friend.friends[i].id === user_id) {
				friend.friends.splice(i, 1);
			}
		}
		await this.userRepository.save([user, friend]);
		pubSub.publish('friendsChanged', {
			friendsChanged: user.friends,
			id: user.id,
		});
		pubSub.publish('friendsChanged', {
			friendsChanged: friend.friends,
			id: friend.id,
		});
		return true;
	}

	async getFriends(user_id: string): Promise<User[]> {
		const user = await this.userRepository.findOne({
			relations: { friends: true },
			where: { id: user_id },
		});
		return user.friends;
	}

	cannotInviteFriend(user: User, friend_id: string): boolean {
		for (let i = 0; i < user.friends.length; i++) {
			if (user.friends[i].id === friend_id) {
				return true;
			}
		}
		for (let i = 0; i < user.outgoing_friend_requests.length; i++) {
			if (user.outgoing_friend_requests[i].id === friend_id) {
				return true;
			}
		}
		for (let i = 0; i < user.incoming_friend_requests.length; i++) {
			if (user.incoming_friend_requests[i].id === friend_id) {
				return true;
			}
		}
		return false;
	}

	async inviteFriend(user_id: string, friend_id: string): Promise<boolean> {
		const user = await this.userRepository.findOne({
			relations: {
				friends: true,
				outgoing_friend_requests: true,
				incoming_friend_requests: true,
			},
			where: { id: user_id },
		});
		const friend = await this.userRepository.findOne({
			relations: { friends: true, incoming_friend_requests: true },
			where: { id: friend_id },
		});
		if (this.cannotInviteFriend(user, friend_id)) {
			return false;
		}
		user.outgoing_friend_requests.push(friend);
		friend.incoming_friend_requests.push(user);
		await this.userRepository.save([friend, user]);
		pubSub.publish('outgoingFriendRequestChanged', {
			outgoingFriendRequestChanged: user,
		});
		pubSub.publish('incomingFriendRequestChanged', {
			incomingFriendRequestChanged: friend,
		});
		return true;
	}

	async getOutgoingFriendRequest(user_id: string): Promise<User[]> {
		const user = await this.userRepository.findOne({
			relations: { outgoing_friend_requests: true },
			where: { id: user_id },
		});
		return user.outgoing_friend_requests;
	}

	async getIncomingFriendRequest(user_id: string): Promise<User[]> {
		const user = await this.userRepository.findOne({
			relations: { incoming_friend_requests: true },
			where: { id: user_id },
		});
		return user.incoming_friend_requests;
	}

	async getBlockedUsers(user: User) {
		const user_with_blocked = await this.userRepository.findOne({
			relations: { blocked_users: true },
			where: { id: user.id },
		});
		return user_with_blocked.blocked_users;
	}

	async blockUser(current_user_id: string, username_to_block: string) {
		const current_user = await this.userRepository.findOne({
			relations: {
				blocked_users: true,
			},
			where: { id: current_user_id },
		});
		const user_to_block = await this.userRepository.findOne({
			where: { username: username_to_block },
		});

		if (
			current_user.blocked_users.some(
				(user) => user.id === user_to_block.id,
			)
		) {
			return false;
		}

		current_user.blocked_users.push(user_to_block);
		await this.userRepository.save([current_user]);

		pubSub.publish('block_state_changed', {
			block_state_changed: true,
			blocked_id: user_to_block.id,
			by_user_id: current_user.id,
		});

		return true;
	}

	async unblockUser(current_user_id: string, username_to_unblock: string) {
		const current_user = await this.userRepository.findOne({
			relations: {
				blocked_users: true,
			},
			where: { id: current_user_id },
		});
		const user_to_unblock = await this.userRepository.findOne({
			where: { username: username_to_unblock },
		});

		const index = current_user.blocked_users.findIndex(
			(user) => user.id === user_to_unblock.id,
		);
		if (index < 0) {
			return false;
		}

		current_user.blocked_users.splice(index, 1);
		await this.userRepository.save([current_user]);

		pubSub.publish('block_state_changed', {
			block_state_changed: false,
			blocked_id: user_to_unblock.id,
			by_user_id: current_user.id,
		});

		return true;
	}
}
