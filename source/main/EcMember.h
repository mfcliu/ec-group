/*
 * EcMember.h
 *
 *  Created on: Jan 1, 2014
 *      Author: root
 */

#ifndef ECMEMBER_H_
#define ECMEMBER_H_

#include "pubdef.h"

class EcMember {
public:
	EcMember();
	virtual ~EcMember();
protected:
	char groupId[ID_BUFFER_LENGTH];
	char id[ID_BUFFER_LENGTH];
	char monitorIp[IP_ADDR_BUFFER_LENGTH];
	short monitorPort;
	int monitorFd;
	char dataIp[IP_ADDR_BUFFER_LENGTH];
	short dataPort;
	int dataFd;
	time_t lastHeartBeat;
public:
	int Connect();
	const char * getGroupid();
	void setGroupId(const char * groupId);
	const char * getId();
	void setId(const char * id);
	const char * getMonitorIp();
	void setMonitorIp(const char * monitorIp);
	short getMonitorPort();
	void setMonitorPort(short port);
	const char * getDataIp();
	void setDataIp(const char * dataIp);
	short getDataPort();
	void setDataPort(short port);
	int getDataFd();
	void setDataFd();
	void HeartBeat();
	bool isDead();

};

#endif /* ECMEMBER_H_ */
