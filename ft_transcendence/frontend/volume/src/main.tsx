import React from "react";
import ReactDOM from "react-dom/client";
import { ApolloClient, ApolloProvider, HttpLink, InMemoryCache, split, from } from "@apollo/client";
import { onError } from "@apollo/client/link/error";
import { GraphQLWsLink } from "@apollo/client/link/subscriptions";
import { createClient } from "graphql-ws";
import { BrowserRouter } from "react-router-dom";
import App from "./App";
import "./styles/style.css";
import { getMainDefinition } from "@apollo/client/utilities";

const httpLink = new HttpLink({
	uri: `https://${import.meta.env["VITE_DOMAIN"]}/api/graphql`,
	credentials: "include",
	fetchOptions: {
		mode: "cors",
	},
});

const wsLink = new GraphQLWsLink(
	createClient({ url: `wss://${import.meta.env["VITE_DOMAIN"]}/api/graphql` })
);

const errorLink = onError(({ networkError }) => {
	if (networkError) {
		console.log("ERROR: network error");
	}
});

const splitLink = split(
	({ query }) => {
		const definition = getMainDefinition(query);
		return definition.kind === "OperationDefinition" && definition.operation === "subscription";
	},
	wsLink,
	httpLink
);

const client = new ApolloClient({
	link: from([errorLink, splitLink]),
	cache: new InMemoryCache(),
});

const root = ReactDOM.createRoot(document.getElementById("root") as HTMLElement);
root.render(
	<React.StrictMode>
		<ApolloProvider client={client}>
			<BrowserRouter>
				<App />
			</BrowserRouter>
		</ApolloProvider>
	</React.StrictMode>
);
