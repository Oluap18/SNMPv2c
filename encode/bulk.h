#ifndef	_Bulk_H_
#define	_Bulk_H_

#include "BulkPDU.h"
#include "VarBindList.h"

/*
 * Cria um BulkPDU_t*, alocando memória para este, e preenchendo o request_id, index, status e 
 * variable_bindings, com o requestID, non_repeaters, max_repeaters e var, respetivamente.
*/
BulkPDU_t* createBulk(long requestID, long non_repeaters, long max_repeaters, VarBindList_t* var);

#endif