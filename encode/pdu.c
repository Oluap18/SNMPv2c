#include "pdu.h"

PDU_t* createPDU(int requestID, long index, long status, VarBindList_t* varlist){
	PDU_t* pdu;
	pdu = calloc(1, sizeof(PDU_t));
	pdu->request_id = requestID;
	pdu->error_index = index;
	pdu->error_status = status;
	pdu->variable_bindings = *varlist; 
	return pdu;
}