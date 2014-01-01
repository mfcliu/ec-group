/*
 * EcGroupMembership.cpp
 *
 *  Created on: Jan 1, 2014
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include "EcGroupMembership.h"
#include "EcMessages.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

EcGroupMembership::EcGroupMembership() {
	// TODO Auto-generated constructor stub

}

EcGroupMembership::~EcGroupMembership() {
	// TODO Auto-generated destructor stub
}

void * EcGroupMembership::memberShipThreadFunc(void * arg) {
	if (NULL == arg) {
		return NULL;
	}
	EcGroupMembership * pGroupMembership = (EcGroupMembership *) arg;
	return NULL;
}
const EcMember* EcGroupMembership::getMe() const {
	return me;
}

void EcGroupMembership::setMe(const EcMember* me) {
	this->me = me;
}

void EcGroupMembership::addMember(const string, const EcMember *) {

}

const hash_map<string, EcMember*>& EcGroupMembership::getMembers() const {
	return members;
}

void EcGroupMembership::setMembers(const hash_map<string, EcMember*>& members) {
	this->members = members;
}

bool EcGroupMembership::startNetwork() {
	if ((sendFd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket error");
		return false;
	}
	memset(&sendAddr, 0, sizeof(sendAddr));
	sendAddr.sin_family = AF_INET;
	sendAddr.sin_addr.s_addr = inet_addr(me->getMonitorIp());
	sendAddr.sin_port = htons(me->getDataPort());
	EcHeartBeat heartBeat;
	if (sendto(sendFd, &heartBeat, sizeof(EcHeartBeat), 0, (struct sockaddr *) &sendAddr,
			sizeof(sendAddr)) < 0) {
		perror("sendto error");
		return false;
	}
	return true;
}
