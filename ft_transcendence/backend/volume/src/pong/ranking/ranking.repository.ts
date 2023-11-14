import { Injectable } from '@nestjs/common';
import { Repository } from 'typeorm';
import { InjectRepository } from '@nestjs/typeorm';
import { Ranking } from './entities/ranking.entity';
import { UserService } from '../../user/user.service';

@Injectable()
export class RankingRepository {
	constructor(
		@InjectRepository(Ranking)
		private readonly rankingRepo: Repository<Ranking>,
		private readonly userService: UserService,
	) {}

	public async findAll(): Promise<Ranking[]> {
		const ranking = await this.rankingRepo.find({
			relations: { user: true },
		});
		ranking.sort((a, b) => b.score - a.score);
		return ranking;
	}

	public async getRankingByUser(userId: string): Promise<Ranking> {
		const user = await this.userService.getUserById(userId);
		if (!user) throw new Error('User not found');
		return await this.rankingRepo.findOne({ where: { user: { id: user.id } } });
	}

	public async saveRanking(ranking: Ranking): Promise<Ranking> {
		if (!ranking) throw new Error('No ranking received');
		return this.rankingRepo.save(ranking);
	}
}
