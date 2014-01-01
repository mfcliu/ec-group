/*
 * EcGroup.h
 *
 *  Created on: Jan 1, 2014
 *      Author: root
 */

#ifndef ECGROUP_H_
#define ECGROUP_H_

#include "pubdef.h"
#include "EcMember.h"
#include "EcGroupMembership.h"
#include <string>

using namespace std;

class EcGroup : public EcMember{
public:
	EcGroup();
	virtual ~EcGroup();
	int Start();

	const string& getGroupId() const ;
	void setGroupId(const string& groupId);
	const map<string, EcMember>& getMembers() const;
	//void setMembers(const map<string, EcMember>& members);
	short getMemberShipPort() const;
	void setMemberShipPort(short memberShipPort);
	const string& getMulticastIp() const;
	void setMulticastIp(const string& multicastIp);
	bool electMaster();
	void setCallBack(void(*call_back)(int,int,void *));
	void (*getCallBack())(int,int,void *);

	void OnEvent();

private:
	string groupId;
	string multicastIp;
	short memberShipPort;
	map<string,EcMember> members;
	EcGroupMembership groupMembership;
	void(*call_back)(int,int,void *);
};

#endif /* ECGROUP_H_ */
