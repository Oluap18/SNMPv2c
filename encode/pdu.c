#include "pdu.h"

PDU_t* createPDU(int requestID, VarBindList_t* varlist){
	PDU_t* pdu;
	pdu = calloc(1, sizeof(PDU_t));
	pdu->request_id = requestID;
	pdu->error_index = 0;
	pdu->error_status = 0;
	pdu->variable_bindings = *varlist; 
	return pdu;
}