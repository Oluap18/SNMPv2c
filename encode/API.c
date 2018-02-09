#include "API.h"
#include "simpleSyntax.h"
#include "objectSyntax.h"
#include "applicationSyntax.h"
#include "objectname.h"
#include "varbind.h"
#include "varBindList.h"
#include "setRequestPDU.h"
#include "pdus.h"
#include "any.h"
#include "message.h"

void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char* oid){
	ObjectSyntax_t* object_syntax;
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	SetRequest_PDU_t* setRequestPDU;
	PDUs_t *pdu;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	void* value;

	varlist = calloc(1, sizeof(VarBindList_t));

	if(flag >=0 && flag < 4){
		simple = createSimpleSyntax(flag, setValue);
		value = simple;
		object_syntax = createObjectSyntax(0, simple);
	}
	else{
		application = createApplicationSyntax(flag-4, setValue);
		value = application;
		object_syntax = createObjectSyntax(1, application);
	}

	object_name = getOID(oid);
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	setRequestPDU = createSetRequestPDU(flag, varlist);
	pdu = createPDU(setRequestPDU, flag);
	data = createANY(pdu);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		xer_fprint(stdout, &asn_DEF_Message, message);
	} 

}

ObjectName_t* getOID(char* oid){
	ObjectName_t* object_name;
	object_name = calloc(1, sizeof(ObjectName_t)); 
	if(objectNameFromBuf(object_name, oid, -1)==-1){
		printf("Erro na conversão para OCTET_STRING.\n");
	}
	return object_name;
}