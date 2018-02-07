#include "API.h"
#include <stdio.h>
#include "objectname.h"
#include "varbind.h"
#include "varBindList.h"
#include "setRequestPDU.h"
#include "pdus.h"

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
	printf("%d\n", escolha);
	return escolha;
}

void setRequest(ObjectSyntax_t* object_syntax){
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
	printf("%d\n", escolha);

	switch(escolha){
		case 0:
			printf("Insira o Integer a colocar:\n");
			scanf("%ld", &integer);
			value = &integer;
			break;
		case 1:
			printf("Insira a String a colocar:\n");
			scanf("%s", string);
			value = string;
			break;
		case 2:
			printf("Insira o OID a colocar:\n");
			scanf("%s", string);
			value = string;
			break;
		case 3:
			printf("Insira o IpAddress:\n");
			scanf("%s", string);
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
			scanf("%s", string);
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
	setRequestPri(object_syntax, escolha, value);
}

void priInput(ObjectSyntax_t* object_syntax, int escolha){

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
			setRequest(object_syntax);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
	}
}

void getOID(ObjectName_t* object_name){
	char oid[1024];
	object_name = calloc(1, sizeof(ObjectName_t)); 
	printf("Insira o OID:\n");
	scanf("%s", oid);
	if(Object_Name_fromBuf(object_name, oid, -1)==-1){
		printf("Erro na conversão para OCTET_STRING.\n");
	}

}

void main(){
	ObjectSyntax_t* object_syntax;
	ObjectName_t* object_name; 
	VarBind_t* var_bind; 
	VarBindList_t* varlist;
	SetRequest_PDU_t* setRequestPDU;
	PDUs_t *pdu;
	int pri;
	uint8_t buffer[1024];
	size_t buffer_size = 1024;

	varlist = calloc(1, sizeof(VarBindList_t)); 

	pri = menuPri();
	priInput(object_syntax, pri);
	getOID(object_name);
	createVarbind(var_bind, object_syntax, object_name);
	int r = ASN_SEQUENCE_ADD(&varlist->list, var_bind);
	createSetRequestPDU(setRequestPDU, pri, varlist);
	createPDU(pdu, setRequestPDU, pri);
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu, buffer, buffer_size); 
}