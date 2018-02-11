#ifndef	_Bulk_H_
#define	_Bulk_H_

#include "BulkPDU.h"
#include "VarBindList.h"

BulkPDU_t* createBulk(long requestID, long non_repeaters, long max_repeaters, VarBindList_t* var);

#endif