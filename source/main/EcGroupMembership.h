/*
 * EcGroupMembership.h
 *
 *  Created on: Jan 1, 2014
 *      Author: root
 */

#ifndef ECGROUPMEMBERSHIP_H_
#define ECGROUPMEMBERSHIP_H_

#include "EcMember.h"
#include <ext/hash_map>
#include <string>
using namespace std;
using namespace __gnu_cxx;


class EcGroupMembership {
public:
	EcGroupMembership();
	virtual ~EcGroupMembership();
public:
	static void * memberShipThreadFunc(void * arg);

	const EcMember* getMe() const ;

	void setMe(const EcMember* me) ;

	const hash_map<string, EcMember*>& getMembers() const ;

	void setMembers(const hash_map<string, EcMember*>& members) ;

	void addMember(const string,const EcMember *);

	bool startNetwork();

private:
	EcMember * me;
	hash_map<string,EcMember *> members;
	struct sockaddr_in sendAddr;
	int sendFd;
	struct ip_mreq sendMreq;
};

#endif /* ECGROUPMEMBERSHIP_H_ */
