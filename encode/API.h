#ifndef	_API_H_
#define	_API_H_

#include "ObjectName.h"

ObjectName_t* getOID(char* oid);
void getRequestPri(unsigned long version, char* community, char** oid);
void getNextRequestPri(unsigned long version, char* community, char** oid);
void getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char** oid);
void responsePri(long index, long status, unsigned long version, char* community, char** oid);
void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char** oid);
void informRequestPri(long index, long status, unsigned long version, char* community, char** oid);
void trapPri(long index, long status, unsigned long version, char* community, char** oid);
void reportPri(long index, long status, char* mensagem, unsigned long version, char* community, char** oid);

#endif