#include "API.h"
#include "simpleSyntax.h"
#include "objectSyntax.h"
#include "applicationSyntax.h"
#include "varbind.h"
#include "varBindList.h"
#include "pdu.h"
#include "pdus.h"
#include "any.h"
#include "message.h"
#include "bulk.h"

void auxPri(int typeObject, void* objectValue, int pduType, long index, long status, unsigned long version, char* community, char** oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name;
	VarBind_t* var_bind;
	VarBindList_t* varlist = calloc(1, sizeof(VarBindList_t));
	void* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;

	object_syntax = createObjectSyntax(typeObject, objectValue);
	for(int i=0; strlen(oid[i])!= 0; i++){
		object_name = getOID(oid[i]);
		var_bind = createVarbind(object_syntax, object_name);
		int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	}
	switch(pduType){
		case 0:
			pdu = createPDU(pduType, 0, 0, varlist);
			break;
		case 1:
			pdu = createPDU(pduType, 0, 0, varlist);
			break;
		case 2:
			pdu = createBulk(2, index, status ,varlist);
			break;
		case 3:
			pdu = createPDU(pduType, index, status, varlist);
			break;
		case 4:
			pdu = createPDU(pduType, 0, 0, varlist);
			break;
		case 5:
			pdu = createPDU(pduType, index, status, varlist);
			break;
		case 6:
			pdu = createPDU(pduType, index, status, varlist);
			break;
		case 7:
			pdu = createPDU(pduType, index, status, varlist);
			break;
	}
	pdus = createPDUs(pdu, pduType);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		/*for(int i = 0; i < buffer_final_size; i++){
			printf("%d ", buffer_final[i]);
		}
		printf("\n%ld\n", buffer_final_size);*/
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 

}

void getRequestPri(unsigned long version, char* community, char** oid){
	
	auxPri(2, NULL, 0, 0, 0, version, community, oid);

}

void getNextRequestPri(unsigned long version, char* community, char** oid){
	auxPri(2, NULL, 1, 0, 0, version, community, oid);
}

void getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char** oid){
	
	auxPri(2, NULL, 2, non_r, max_r, version, community, oid);
	
}

void responsePri(long index, long status, unsigned long version, char* community, char** oid){
	
	auxPri(2, NULL, 3, index, status, version, community, oid);

}

void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char** oid){
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;

	if(flag >=0 && flag < 3){
		simple = createSimpleSyntax(flag, setValue);
		auxPri(0, simple, 4, 0, 0, version, community, oid);
	}
	else{
		application = createApplicationSyntax(flag-3, setValue);
		auxPri(1, application, 4, 0, 0, version, community, oid);
	}
}

void informRequestPri(long index, long status, unsigned long version, char* community, char** oid){

	auxPri(2, NULL, 5, index, status, version, community, oid);

}

void trapPri(long index, long status, unsigned long version, char* community, char** oid){
	
	auxPri(2, NULL, 6, index, status, version, community, oid);
	
}

void reportPri(long index, long status, char* mensagem, unsigned long version, char* community, char** oid){
	SimpleSyntax_t* simple;
	auxPri(0, simple, 7, index, status, version, community, oid);

}

OBJECT_IDENTIFIER_t* getOID(char* oid){
	OBJECT_IDENTIFIER_t* object_name;
	uint32_t buffer[1024];
	int init = 0, aux;
	size_t counter;
	object_name = calloc(1, sizeof(OBJECT_IDENTIFIER_t));
	counter = OBJECT_IDENTIFIER_parse_arcs(oid, strlen(oid), buffer, 1024, NULL); 
	OBJECT_IDENTIFIER_set_arcs(object_name, buffer, counter);
	return object_name;
}