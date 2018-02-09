#ifndef	_set_Request_PDU_H_
#define	_set_Request_PDU_H_

#include "SetRequest-PDU.h"
#include "VarBindList.h"

/*
 *
 *
*/
SetRequest_PDU_t* createSetRequestPDU(int requestID, VarBindList_t* varlist);

#endif