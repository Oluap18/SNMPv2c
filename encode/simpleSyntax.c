#include "simpleSyntax.h"

OBJECT_IDENTIFIER_t* parseOID(char* oid){
	OBJECT_IDENTIFIER_t* object;
	uint32_t buffer[1024];
	int init = 0, aux;
	size_t counter;
	object = calloc(1, sizeof(OBJECT_IDENTIFIER_t));

	counter = OBJECT_IDENTIFIER_parse_arcs(oid, strlen(oid), buffer, 1024, NULL); 
	OBJECT_IDENTIFIER_set_arcs(object, buffer, counter);
	return object;
}

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
			oid = parseOID((char*)value);
			simple->choice.objectID_value = *oid;
			break;
	}
	return simple;
}