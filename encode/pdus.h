#ifndef	_pdus_H_
#define	_pdus_H_

#include "PDUs.h"
#include "SetRequest-PDU.h"

PDUs_t* createPDU(SetRequest_PDU_t* setRequestPDU, int escolha);

#endif