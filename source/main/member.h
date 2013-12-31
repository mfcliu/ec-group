/*
 * member.h
 *
 *  Created on: Dec 31, 2013
 *      Author: root
 */

#ifndef MEMBER_H_
#define MEMBER_H

#include "pubdef.h"

class member{
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



#endif /* MEMBER_H_ */
