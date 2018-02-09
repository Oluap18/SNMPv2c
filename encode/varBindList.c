#include "varBindList.h"

void addVarBind(VarBindList_t* varlist, VarBind_t* var_bind){
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
}