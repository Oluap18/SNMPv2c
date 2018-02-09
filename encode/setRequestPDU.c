#include "setRequestPDU.h"

SetRequest_PDU_t* createSetRequestPDU(int requestID, VarBindList_t* varlist){
	SetRequest_PDU_t* setRequestPDU;
	setRequestPDU = calloc(1, sizeof(SetRequest_PDU_t));
	setRequestPDU->request_id = requestID;
	setRequestPDU->error_index = 0;
	setRequestPDU->error_status = 0;
	setRequestPDU->variable_bindings = *varlist; 
	return setRequestPDU;
}