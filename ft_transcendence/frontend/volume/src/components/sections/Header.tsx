import "src/styles/style.css";
import * as i from "src/types/Interfaces";
import { convertEncodedImage } from "src/utils/convertEncodedImage";
import { useQueryUser } from "src/utils/useQueryUser";

function Header(props: i.PongProps) {
	if (!props.playersAvailable) return <header></header>;

	const [p1Score, p2Score] = props.score;

	return (
		<header>
			<Player className="player_left" user={props.players[0]} />
			<div className="score">
				<div className="player_one">{p1Score}</div>
				<div className="player_two">{p2Score}</div>
			</div>
			<Player className="player_right" user={props.players[1]} />
		</header>
	);
}

function Player({ user, className }: { user: any; className: string }) {
	const { user: player, loading: loading, error: error } = useQueryUser(user.id);

	if (!player) return <></>;
	if (loading) return <>Loading</>;
	if (error) return <></>;

	if (className === "player_left")
		return (
			<div className={["player", className].join(" ")}>
				<div className="avatar_container">
					<img src={convertEncodedImage(player.avatar.file)}></img>
				</div>
				<h3 className="name">{player.username}</h3>
			</div>
		);
	return (
		<div className={["player", className].join(" ")}>
			<h3 className="name">{player.username}</h3>
			<div className="avatar_container">
				<img src={convertEncodedImage(player.avatar.file)}></img>
			</div>
		</div>
	);
}

export default Header;
