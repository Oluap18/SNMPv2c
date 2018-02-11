#include "API.h"
#include "simpleSyntax.h"
#include "objectSyntax.h"
#include "applicationSyntax.h"
#include "varbind.h"
#include "pdu.h"
#include "pdus.h"
#include "any.h"
#include "bulk.h"
#include "message.h"
#include "objectName.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

uint8_t* auxPri(int typeObject, void* objectValue, int pduType, long index, long status, unsigned long version, char* community, char** oid){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name;
	VarBind_t* var_bind;
	VarBindList_t* varlist = calloc(1, sizeof(VarBindList_t));
	void* pdu;
	PDUs_t *pdus;
	ANY_t* data = calloc(1, sizeof(ANY_t));
	Message_t* message;
	uint8_t* buffer_final = (uint8_t*) malloc(sizeof(uint8_t)*1024);
	size_t buffer_final_size = 1024;

	object_syntax = createObjectSyntax(typeObject, objectValue);
	for(int i=0; strlen(oid[i])!= 0; i++){
		object_name = createObjectName(oid[i]);
		var_bind = createVarbind(object_syntax, object_name);
		int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	}
	if(pduType != 2){
		pdu = createPDU(pduType, index, status, varlist);
	}
	else{
		pdu = createBulk(pduType, index, status, varlist);
	}
	pdus = createPDUs(pdu, pduType);
	createANY(data, pdus);
	message = createMessage(data, version, community);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);
	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	return buffer_final;
}

void escreveFicheiro(char* file, uint8_t* buffer){
	char name[80];
	name[0]='\0';
	strcat(name, file);
	name[strlen(name)-1]='\0';
	strcat(name, ".txt");
	int fp = open(name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	char str[10];
	for(int i = 0; i < 1024; i++){
		sprintf(str, "%d ", buffer[i]);
		write(fp, str,strlen(str));
	}
}

void escreveUDP(int port, char* ip, uint8_t* buffer){
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(ip);
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	socklen_t udp_socket_size = sizeof(addr); 
	int sent = sendto(sock, buffer, 1024, 0, (struct sockaddr *)&addr,udp_socket_size); 
}

uint8_t* getRequestPri(unsigned long version, char* community, char** oid){
	uint8_t* buffer = auxPri(2, NULL, 0, 0, 0, version, community, oid);

}

uint8_t* getNextRequestPri(unsigned long version, char* community, char** oid){
	uint8_t* buffer = auxPri(2, NULL, 1, 0, 0, version, community, oid);
}

uint8_t* getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char** oid){
	
	uint8_t* buffer = auxPri(2, NULL, 2, non_r, max_r, version, community, oid);
	
}

uint8_t* responsePri(long index, long status, unsigned long version, char* community, char** oid){
	
	uint8_t* buffer = auxPri(2, NULL, 3, index, status, version, community, oid);

}

uint8_t* setRequestPri(int flag, void* setValue, unsigned long version, char* community, char** oid){
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;
	uint8_t* buffer;

	if(flag >=0 && flag < 3){
		simple = createSimpleSyntax(flag, setValue);
		buffer = auxPri(0, simple, 4, 0, 0, version, community, oid);
	}
	else{
		application = createApplicationSyntax(flag-3, setValue);
		buffer = auxPri(1, application, 4, 0, 0, version, community, oid);
	}
}

uint8_t* informRequestPri(long index, long status, unsigned long version, char* community, char** oid){

	uint8_t* buffer = auxPri(2, NULL, 5, index, status, version, community, oid);

}

uint8_t* trapPri(long index, long status, unsigned long version, char* community, char** oid){
	
	uint8_t* buffer = auxPri(2, NULL, 6, index, status, version, community, oid);
	
}

uint8_t* reportPri(long index, long status, char* mensagem, unsigned long version, char* community, char** oid){
	SimpleSyntax_t* simple = createSimpleSyntax(1, mensagem);
	uint8_t* buffer = auxPri(0, simple, 7, index, status, version, community, oid);
	return buffer;

}