import { useMutation } from "@apollo/client";
import { gql } from "@apollo/client";
import { useEffect } from "react";
import { useState } from "react";
import { convertEncodedImage } from "src/utils/convertEncodedImage";

const ACCEPT_FRIEND = gql`
	mutation AcceptFriend($friendId: String!) {
		acceptFriend(friend_id: $friendId) {
			id
		}
	}
`;

const DENY_FRIEND = gql`
	mutation DenyFriend($friendId: String!) {
		denyFriend(friend_id: $friendId) {
			id
		}
	}
`;

export default function FriendRequestAlert({ user }: { user: any }) {
	const [showModal, setShowModal] = useState(false);

	useEffect(() => {
		setShowModal(true);
	}, [user]);

	return (
		<>
			{showModal && (
				<div className="modal">
					<div className="modal-content">
						<div className="requestAlert">
							<div className="avatar_container">
								<img src={convertEncodedImage(user.avatar.file)} />
							</div>
							<div className="user_actions">
								<h1>{user.username}</h1>
								<p>New friend request from {user.username}</p>
							</div>
						</div>
						<FriendAccept friend_id={user.id} setShowModal={setShowModal} />
						<FriendDeny friend_id={user.id} setShowModal={setShowModal} />
					</div>
				</div>
			)}
		</>
	);
}

function FriendAccept({ friend_id, setShowModal }: { friend_id: string; setShowModal: any }) {
	const [accept_friend, { loading: accept_loading, error: accept_error }] =
		useMutation(ACCEPT_FRIEND);

	if (accept_loading) return <>Loading accept</>;
	if (accept_error) return <>Error accept</>;
	return (
		<div>
			<form
				onSubmit={(e) => {
					e.preventDefault();
					accept_friend({ variables: { friendId: friend_id } });
					setShowModal(false);
				}}
			>
				<button type="submit">Accept</button>
			</form>
		</div>
	);
}

function FriendDeny({ friend_id, setShowModal }: { friend_id: string; setShowModal: any }) {
	const [deny_friend, { loading: accept_loading, error: accept_error }] =
		useMutation(DENY_FRIEND);

	if (accept_loading) return <>Loading accept</>;
	if (accept_error) return <>Error accept</>;
	return (
		<div>
			<form
				onSubmit={(e) => {
					e.preventDefault();
					deny_friend({ variables: { friendId: friend_id } });
					setShowModal(false);
				}}
			>
				<button type="submit">Deny</button>
			</form>
		</div>
	);
}
