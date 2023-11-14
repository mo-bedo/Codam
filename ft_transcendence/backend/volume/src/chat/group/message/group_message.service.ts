import { Injectable } from '@nestjs/common';
import { InjectRepository } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { UserService } from 'src/user/user.service';
import { User } from 'src/user/entities/user.entity';
import { GroupMessage } from './entities/group_message.entity';
import { CreateGroupMessageInput } from './dto/create_group_message.input';
import { GroupChatService } from '../chat/group_chat.service';
import { GroupChat } from '../chat/entities/group_chat.entity';

@Injectable()
export class GroupMessageService {
	constructor(
		@InjectRepository(GroupMessage)
		private readonly messageRepository: Repository<GroupMessage>,
		private readonly userService: UserService,
		private readonly channelService: GroupChatService,
	) {}

	async create(
		createMessageInput: CreateGroupMessageInput,
		author_id: string,
	): Promise<GroupMessage> {
		if (
			this.channelService.isMuted(
				author_id,
				createMessageInput.channel_id,
			)
		) {
			const author = await this.userService.getUserById(author_id);
			const channel = await this.channelService.getChannelById(
				createMessageInput.channel_id,
			);

			const message = this.messageRepository.create({
				author,
				channel,
				content: 'User is muted',
			});
			return await this.messageRepository.save(message);
		}
		const author = await this.userService.getUserById(author_id);
		const channel = await this.channelService.getChannelById(
			createMessageInput.channel_id,
		);

		const message = this.messageRepository.create({
			author,
			channel,
			content: createMessageInput.content,
		});
		return await this.messageRepository.save(message);
	}

	async getAuthor(message: GroupMessage): Promise<User> {
		const message_with_author = await this.messageRepository.findOne({
			relations: { author: true },
			where: { id: message.id },
		});
		return message_with_author.author;
	}

	async getChannel(message: GroupMessage): Promise<GroupChat> {
		const message_with_channel = await this.messageRepository.findOne({
			relations: { channel: true },
			where: { id: message.id },
		});
		return message_with_channel.channel;
	}
}
