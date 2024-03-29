#ifndef	_pdu_H_
#define	_pdu_H_

#include "PDU.h"
#include "VarBindList.h"

/*
 * Cria uma estrutura PDU_t*, alocando memória para esta, os campos request_id, error_index,
 * error_status e variable_bindings com os valores dados como argumentos requestID, index, status 
 * e varlist, respetivamente.
 * O processo de descodificação assume os respetivos valores:
 * requestID = 0 -> primitiva getRequest
 * requestID = 1 -> primitiva getNextRequest
 * requestID = 2 -> primitiva getBulkRequest
 * requestID = 3 -> primitiva response
 * requestID = 4 -> primitiva setRequest
 * requestID = 5 -> primitiva informRequest
 * requestID = 6 -> primitiva trap
 * requestID = 7 -> primitiva report
*/
PDU_t* createPDU(int requestID, long index, long status, VarBindList_t* varlist);

#endif