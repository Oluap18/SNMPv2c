#include "API.h"
#include <stdio.h>
#include "objectname.h"
#include "varbind.h"
#include "varBindList.h"
#include "setRequestPDU.h"
#include "pdus.h"
#include "any.h"
#include "message.h"

//Para limpar o buffer
char c;

int menuPri(){
	int escolha;
	printf("Escolha a Primitiva\n");
	printf("0. get_request\n");
	printf("1. get_next_request\n");
	printf("2. get_bulk_request\n");
	printf("3. response\n");
	printf("4. set_request\n");
	printf("5. inform_request\n");
	printf("6. snmpV2_trap\n");
	printf("7. report\n");
	scanf("%d", &escolha);
	return escolha;
}

ObjectSyntax_t* setRequest(){
	ObjectSyntax_t* object_syntax;
	int escolha;
	char string[1024];
	long integer;
	int inteiro;
	void* value;
	unsigned long lu;

	printf("Tipo do valor a colocar:\n");
	printf("0. Integer\n");
	printf("1. String\n");
	printf("2. ObjectID\n");
	printf("3. IpAddress\n");
	printf("4. Counter\n");
	printf("5. TimeTicks\n");
	printf("6. Arbitrário\n");
	printf("7. BigCounter\n");
	printf("8. UnsignedInteger\n");
	scanf("%d", &escolha);
	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }

	switch(escolha){
		case 0:
			printf("Insira o Integer a colocar:\n");
			scanf("%ld", &integer);
			value = &integer;
			break;
		case 1:
			printf("Insira a String a colocar:\n");
			fgets(string, 1024, stdin);
			value = string;
			break;
		case 2:
			printf("Insira o OID a colocar:\n");
			fgets(string, 1024, stdin);
			value = string;
			break;
		case 3:
			printf("Insira o IpAddress:\n");
			fgets(string, 1024, stdin);
			value = string;
		case 4:
			printf("Insira o Counter a colocar:\n");
			scanf("%lu", &lu);
			value = &lu;
		case 5:
			printf("Insira o TimeTicks a colocar\n");
			scanf("%lu", &lu);
			value = &lu;
		case 6:
			printf("Insira algo arbitrário a colocar\n");
			fgets(string, 1024, stdin);
			value = string;
		case 7:
			printf("Insira o BigCounter a colocar\n");
			scanf("%d", &inteiro);
			value = &inteiro;
		case 8:
			printf("Insira o UnsignedInteger a colocar\n");
			scanf("%lu", &lu);
			value = &lu;
	}
	object_syntax = setRequestPri(escolha, value);
	return object_syntax;
}

ObjectSyntax_t* priInput(int escolha){
	ObjectSyntax_t* object_syntax;

	switch(escolha){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			object_syntax = setRequest();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
	}
	return object_syntax;
}

ObjectName_t* getOID(){
	ObjectName_t* object_name;
	char oid[1024];
	object_name = calloc(1, sizeof(ObjectName_t)); 
	printf("Insira o OID:\n");
	fgets(oid, 1024, stdin);
	if(objectNameFromBuf(object_name, oid, -1)==-1){
		printf("Erro na conversão para OCTET_STRING.\n");
	}

	return object_name;
}

Message_t* mensagem(ANY_t* data){
	Message_t* message;
	long lu;
	char comm[1024];
	printf("Qual a versão do snmp?\n");
	scanf("%ld", &lu);
	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);
	message = createMessage(data, lu, comm);
	return message;
}

void main(){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	SetRequest_PDU_t* setRequestPDU;
	PDUs_t *pdu;
	ANY_t* data;
	Message_t* message;
	uint8_t buffer_final[1024];
	size_t buffer_final_size = 1024;
	int pri;

	varlist = calloc(1, sizeof(VarBindList_t)); 

	pri = menuPri();
	object_syntax = priInput(pri);
	object_name = getOID();
	var_bind = createVarbind(object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	setRequestPDU = createSetRequestPDU(pri, varlist);
	pdu = createPDU(setRequestPDU, pri);
	data = createANY(pdu);
	message = mensagem(data);

	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_Message, message, buffer_final, buffer_final_size);

	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	else{
		printf("All good\n");
	} 
	
}