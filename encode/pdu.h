#ifndef	_pdu_H_
#define	_pdu_H_

#include "PDU.h"
#include "VarBindList.h"

PDU_t* createPDU(int requestID, long index, long status, VarBindList_t* varlist);

#endif