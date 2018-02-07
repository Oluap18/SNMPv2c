#ifndef	_set_Request_PDU_H_
#define	_set_Request_PDU_H_

#include "SetRequest-PDU.h"
#include "VarBindList.h"

/*
 *
 *
*/
void createSetRequestPDU(SetRequest_PDU_t* setRequestPDU, int requestID, VarBindList_t* varlist);

#endif