#ifdef _WIN32
#include <Ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

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

	memset(&serveraddr, 0, sizeof(sockaddr_in));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = htons(HOSTPORT);


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
	struct sockaddr_in addr;
	socklen_t addrsize = sizeof (sockaddr_in);
	int res = accept (request_sd, (struct sockaddr*) &addr, &addrsize);
	if (res < 0) {
		perror ("accept");
		exit (EXIT_FAILURE);
	}
	return res;
}

int init_client(char *hostname) {
	int sd;
	sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in serveraddr;
	
	memset(&serveraddr, 0, sizeof(struct sockaddr_in));
	serveraddr.sin_family = AF_INET;
	inet_pton(AF_INET, hostname, &serveraddr.sin_addr);
	serveraddr.sin_port = htons(HOSTPORT);
	
	if (connect(sd, (struct sockaddr *) &serveraddr, sizeof(struct sockaddr_in)) < 0) {
		perror("connect()");
		return -1;
	}
	return sd;
}

void get_command(int sfd, sPlayerAction *action) {
	char buf[1024];
	int res = recv(sfd, buf, sizeof (buf), MSG_DONTWAIT);
	if (res > 0){
		printf("%d\n", res);
		action->command = (Command) ntohl(*(int*)&buf[0]);
		action->x = ntohl(*(int*)&buf[4]);
		action->y = ntohl(*(int*)&buf[8]);
	} else {
		action->command = CmdNothing;
	}
}

void send_command(int sfd, const sPlayerAction& action){
	char buf[1024];
	*(int*)&buf[0] = htonl((int)action.command);
	*(int*)&buf[4] = htonl(action.x);
	*(int*)&buf[8] = htonl(action.y);
	int res = send(sfd, buf, sizeof (buf), 0);
	
	printf("AA %d\n", res);
}
