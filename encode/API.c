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

void getRequestPri(unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(0, 0, 0, varlist);
	pdus = createPDUs(pdu, 0);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 
}

void getNextRequestPri(unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(1, 0, 0, varlist);
	pdus = createPDUs(pdu, 1);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 
}

void getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	BulkPDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createBulk(2, non_r, max_r ,varlist);
	pdus = createPDUs(pdu, 2);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 
}

void responsePri(long index, long status, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	void* value;

	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(3, index, status, varlist);
	pdus = createPDUs(pdu, 3);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 

}

void informRequestPri(long index, long status, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	void* value;

	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(5, index, status, varlist);
	pdus = createPDUs(pdu, 5);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 
}

void trapPri(long index, long status, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	void* value;

	varlist = calloc(1, sizeof(VarBindList_t));

	object_syntax = createObjectSyntax(2, NULL);
	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(6, index, status, varlist);
	pdus = createPDUs(pdu, 6);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 
}

void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	PDU_t* pdu;
	PDUs_t *pdus;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	void* value;

	varlist = calloc(1, sizeof(VarBindList_t));

	if(flag >=0 && flag < 3){
		simple = createSimpleSyntax(flag, setValue);
		value = simple;
		object_syntax = createObjectSyntax(0, simple);
	}
	else{
		application = createApplicationSyntax(flag-3, setValue);
		value = application;
		object_syntax = createObjectSyntax(1, application);
	}

	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	pdu = createPDU(4, 0, 0, varlist);
	pdus = createPDUs(pdu, 4);
	data = createANY(pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
		xer_fprint(stdout, &asn_DEF_PDUs, pdus);
	} 

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