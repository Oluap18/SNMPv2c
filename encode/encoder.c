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

void setRequest(){
	int escolha;
	char string[1024], oid[1024], comm[1024];
	long integer;
	int inteiro;
	void* value;
	unsigned long lu, version;

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
			printf("Insira o ObjectID a colocar:\n");
			fgets(string, 1024, stdin);
			value = string;
			break;
		case 3:
			printf("Insira o IpAddress:\n");
			fgets(string, 1024, stdin);
			value = string;
			break;
		case 4:
			printf("Insira o Counter a colocar:\n");
			scanf("%lu", &lu);
			value = &lu;
			break;
		case 5:
			printf("Insira o TimeTicks a colocar\n");
			scanf("%lu", &lu);
			value = &lu;
			break;
		case 6:
			printf("Insira algo arbitrário a colocar\n");
			fgets(string, 1024, stdin);
			value = string;
			break;
		case 7:
			printf("Insira o BigCounter a colocar\n");
			scanf("%d", &inteiro);
			value = &inteiro;
			break;
		case 8:
			printf("Insira o UnsignedInteger a colocar\n");
			scanf("%lu", &lu);
			value = &lu;
			break;
	}

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira o OID:\n");
	fgets(oid, 1024, stdin);

	setRequestPri(escolha, value, version, comm, oid);
}

void priInput(int escolha){

	switch(escolha){
		case 0:
			//getRequest();
			break;
		case 1:
			//getNextRequest();
			break;
		case 2:
			//getBulkRequest();
			break;
		case 3:
			//response();
			break;
		case 4:
			setRequest();
			break;
		case 5:
			//informRequest();
			break;
		case 6:
			//trap();
			break;
		case 7:
			//report();
			break;
	}
}

void main(){
	int pri;
	pri = menuPri();
	priInput(pri);
}