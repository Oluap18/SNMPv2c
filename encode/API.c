#include "API.h"
#include "simpleSyntax.h"
#include "objectSyntax.h"
#include "applicationSyntax.h"
#include "varbind.h"
#include "pdu.h"
#include "pdus.h"
#include "any.h"
#include "message.h"
#include "bulk.h"
#include <arpa/inet.h>

ObjectName_t* getOID(char* oid){
	ObjectName_t* object_name;
	uint8_t* buffer;
	char subbuff[1024];
	buffer = (uint8_t*)malloc(sizeof(uint8_t)*1024);
	int init = 0;
	size_t counter=0;
	object_name = calloc(1, sizeof(ObjectName_t));
	for(int i = 0; oid[i] != '\0';i++){
		if(oid[i]=='.' || oid[i+1] == '\0'){
			memcpy( subbuff, &oid[init], i-init );
			subbuff[i-init] = '\0';
			buffer[counter++] = atoi(subbuff);
			init = i+1;
		}
	}
	object_name->buf = buffer;
	object_name->size = counter;
	return object_name;
}

void auxPri(int typeObject, void* objectValue, int pduType, long index, long status, unsigned long version, char* community, char** oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name;
	VarBind_t* var_bind;
	VarBindList_t* varlist = calloc(1, sizeof(VarBindList_t));
	void* pdu;
	PDUs_t *pdus;
	ANY_t* data = calloc(1, sizeof(ANY_t));
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;

	object_syntax = createObjectSyntax(typeObject, objectValue);
	for(int i=0; strlen(oid[i])!= 0; i++){
		object_name = getOID(oid[i]);
		xer_fprint(stdout, &asn_DEF_ObjectName, object_name);
		var_bind = createVarbind(object_syntax, object_name);
		xer_fprint(stdout, &asn_DEF_VarBind, var_bind);
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
	createANY(data, pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);


	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(9999);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		int sock = socket(AF_INET, SOCK_DGRAM, 0);
		socklen_t udp_socket_size = sizeof(addr); 
		int sent = sendto(sock, buffer_final, buffer_final_size, 0, (struct sockaddr *)&addr,udp_socket_size); 
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