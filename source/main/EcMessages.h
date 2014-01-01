/*
 * EcMessages.h
 *
 *  Created on: Jan 2, 2014
 *      Author: root
 */

#ifndef ECMESSAGES_H_
#define ECMESSAGES_H_
#include "pubdef.h"

#pragma pack(push)
#pragma pack(1)
typedef struct{
	char id[ID_BUFFER_LENGTH];
}EcHeartBeat;
#pragma pack(pop)


class EcMessages {
public:
	EcMessages();
	virtual ~EcMessages();
};

#endif /* ECMESSAGES_H_ */
