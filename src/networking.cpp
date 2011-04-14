#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <iostream>

#include "networking.h"
using namespace std;
int init_server() {
	struct sockaddr_in serveraddr;
	int request_sd;
	//int yes = 1;
	if ((request_sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket()");
		return -1;
	}

	cerr << "debug";
	/*
	if (setsockopt(request_sd, SOL_SOCKET, SO_REUSEADDR, &yes,
		sizeof(int)) < 1) { 
		perror("setsockopt()");
		return -1;
	}*/

	cerr << "debug";

	bzero(&serveraddr, sizeof(sockaddr_in));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = HOSTPORT;


	cerr << "debug";
	if (bind(request_sd, (struct sockaddr *) &serveraddr, 
		sizeof (struct sockaddr_in)) < 0) { 
		perror("bind()");
		return -1;
	}
	cerr << "debug";

	if (listen(request_sd, SOMAXCONN) < 0) {
		perror("listen()");
		return -1;
	}

	cerr << "debug";
	return request_sd;
}

int accept_or_die(int request_sd) {
	return 0;
}

int init_client(char *hostname) {
	int sd;
	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in serveraddr;
	bzero(&serveraddr, sizeof(struct sockaddr_in));
	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET, hostname, &serveraddr.sin_addr);
	serveraddr.sin_port = htons(HOSTPORT);
	if (connect(sd, (struct sockaddr *) &serveraddr, sizeof(struct sockaddr_in)) < 0) {
		perror("connect()");
		return -1;
	}
	return sd;
}
