/*
 * ec-group.h
 *
 *  Created on: Dec 31, 2013
 *      Author: root
 */

#ifndef EC_GROUP_H_
#define EC_GROUP_H_

#include "config.h"
#include <vector>
using namespace std;

class EC_GROUP{
	vector<member> mebers;
	Config config;
	member * pMaster;
	int Start();
	void setParam();
};



#endif /* EC_GROUP_H_ */
