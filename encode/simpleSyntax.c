#include "simpleSyntax.h"
#include "object_identifier.h"

SimpleSyntax_t* createSimpleSyntax(int flag, void* value){
	SimpleSyntax_t* simple;
	simple = calloc(1, sizeof(SimpleSyntax_t));
	OCTET_STRING_t* octet;
	OBJECT_IDENTIFIER_t* oid;
	switch(flag){
		case 0:
			simple->present = SimpleSyntax_PR_integer_value;
			simple->choice.integer_value = *((long*) value);
			break;
		case 1:
			simple->present = SimpleSyntax_PR_string_value;
			octet = calloc(1, sizeof(OCTET_STRING_t));
			if(OCTET_STRING_fromBuf(octet, (char*) value, -1) == -1){
				printf("Erro na conversão para OCTET_STRING.\n");
			}
			simple->choice.string_value = *octet;
			break;
		case 2:
			simple->present = SimpleSyntax_PR_objectID_value;
			oid = calloc(1, sizeof(OBJECT_IDENTIFIER_t));
			if(object_identifier_fromBuf(oid, (char*) value, -1) == -1){
				printf("Erro na conversão para OBJECT_IDENTIFIER.\n");
			}
			simple->choice.objectID_value = *oid;
			break;
	}
	return simple;
}