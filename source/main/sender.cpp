//============================================================================
// Name        : testmulticast.cpp
// Author      : mfcliu
// Version     :
// Copyright   : mfcliu 2013-2016
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define HELLO_PORT 12345
#define HELLO_GROUP "225.0.0.37"

int main(void) {
	struct sockaddr_in addr;
	int fd,cnt;
	struct ip_mreq mreq;
	char * message = "Hello World!!!";
	if((fd=socket(AF_INET,SOCK_DGRAM,0))<0){
		perror("socket error");
		exit(1);
	}
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(HELLO_GROUP);
	addr.sin_port = htons(HELLO_PORT);

	while(1){
		if(sendto(fd,message,strlen(message),0,(struct sockaddr *)&addr,sizeof(addr))<0){
			perror("sendto error");
			exit(1);
		}
		sleep(1);
	}

	return EXIT_SUCCESS;
}
