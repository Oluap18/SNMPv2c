#include "setRequestPDU.h"

void createSetRequestPDU(SetRequest_PDU_t* setRequestPDU, int requestID, VarBindList_t* varlist){
	setRequestPDU = calloc(1, sizeof(SetRequest_PDU_t));
	setRequestPDU->request_id = requestID;
	setRequestPDU->error_index = 0;
	setRequestPDU->error_status = 0;
	setRequestPDU->variable_bindings = *varlist; 
}