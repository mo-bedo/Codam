import { Controller, Get } from '@nestjs/common';
import { AuthService, IntraToken } from './auth.service';
import { Res, Req } from '@nestjs/common';
import { Response, Request } from 'express';
import { TokenType } from './user-info.interface';
import { UserInfo } from 'src/auth/user-info.interface';

@Controller('callback')
export class AuthController {
	constructor(private readonly authService: AuthService) {}

	@Get()
	async callback(
		@Res({ passthrough: true }) response: Response,
		@Req() request: Request,
	) {
		let redirectPage: string, userInfo: UserInfo;
		const intraToken: IntraToken =
			await this.authService.exchangeCodeForToken(
				JSON.stringify(request.query),
			);
		const { user, userIsNew } = await this.authService.linkTokenToUser(
			intraToken,
		);

		if (!userIsNew) {
			if (user.twoFAEnabled == true) {
				redirectPage = '/2fa';
				userInfo = {
					userUid: user.id,
					intraId: user.intraId,
					type: TokenType.PARTIAL,
				};
			} else {
				redirectPage = '/home';
				userInfo = {
					userUid: user.id,
					intraId: user.intraId,
					type: TokenType.FULL,
				};
			}
		} else {
			redirectPage = '/new-user';
			userInfo = {
				userUid: user.id,
				intraId: user.intraId,
				type: TokenType.FULL,
			};
		}

		const jwtCookie = await this.authService.getJwtCookie(userInfo);
		response.setHeader('Set-Cookie', jwtCookie);
		response
			.status(200)
			.redirect(`https://${process.env['DOMAIN']}` + redirectPage);
	}
}
