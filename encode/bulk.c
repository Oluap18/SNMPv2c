#include "bulk.h"

BulkPDU_t* createBulk(long requestID, long non_repeaters, long max_repeaters, VarBindList_t* var){
	BulkPDU_t* bulk;
	bulk = calloc(1, sizeof(BulkPDU_t));
	bulk->request_id = requestID;
	bulk->non_repeaters = non_repeaters;
	bulk->max_repetitions = max_repeaters;
	bulk->variable_bindings = *var;
	return bulk;
}