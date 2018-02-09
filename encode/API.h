#ifndef	_API_H_
#define	_API_H_

#include "ObjectName.h"

ObjectName_t* getOID(char* oid);
void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char* oid);

#endif