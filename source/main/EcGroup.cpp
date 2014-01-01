/*
 * EcGroup.cpp
 *
 *  Created on: Jan 1, 2014
 *      Author: root
 */

#include "EcGroup.h"


EcGroup::EcGroup() {
	// TODO Auto-generated constructor stub

}

EcGroup::~EcGroup() {
	// TODO Auto-generated destructor stub
}

const string& EcGroup::getGroupId() const {
	return groupId;
}

void EcGroup::setGroupId(const string& groupId) {
	this->groupId = groupId;
}

const map<string, EcMember>& EcGroup::getMembers() const {
	return members;
}

short EcGroup::getMemberShipPort() const {
	return memberShipPort;
}

void EcGroup::setMemberShipPort(short memberShipPort) {
	this->memberShipPort = memberShipPort;
}

const string& EcGroup::getMulticastIp() const {
	return multicastIp;
}

void EcGroup::setMulticastIp(const string& multicastIp) {
	this->multicastIp = multicastIp;
}

void EcGroup::setCallBack(void(*call_back)(int,int,void *)){
	this->call_back = call_back;
}

void (*EcGroup::getCallBack())(int,int,void *){
	return this->call_back;
}

int EcGroup::Start(){
	groupMembership.setMe(this);
	groupMembership.startNetwork();
return -1;
}
