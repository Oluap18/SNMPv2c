#include "API.h"
#include <stdio.h>

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
	int setType;
	char string[1024], oid[1024], comm[1024], **oids;
	long integer;
	int inteiro, counter = 0, init=0;
	void* value;
	unsigned long lu, version;
	oids = (char**)malloc(sizeof(char*));

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
	scanf("%d", &setType);
	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }

	switch(setType){
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

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	setRequestPri(setType, value, version, comm, oids);
}

void getRequest(){
	unsigned long version;
	char comm[1024], oid[1024], **oids;
	int counter=0, init=0;

	oids = (char**)malloc(sizeof(char*));

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	getRequestPri(version, comm, oids);
}

void getNextRequest(){
	unsigned long version;
	char comm[1024], oid[1024], **oids;
	int counter=0, init=0;
	oids = (char**)malloc(sizeof(char*));


	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	getNextRequestPri(version, comm, oids);
}

void getBulkRequest(){
	unsigned long version, non_r, max_r;
	char comm[1024], oid[1024], **oids;
	int counter=0, init=0;
	oids = (char**)malloc(sizeof(char*));

	printf("Qual o número de non_repeaters?\n");
	scanf("%ld", &non_r);


	printf("Qual o número de max_repeaters?\n");
	scanf("%ld", &max_r);

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	getBulkRequestPri(non_r, max_r, version, comm, oids);
}

void response(){
	unsigned long version, index, status;
	char comm[1024], oid[1024], **oids;
	int counter=0, init=0;
	oids = (char**)malloc(sizeof(char*));

	printf("Qual o erro de index?\n");
	scanf("%ld", &index);


	printf("Qual o erro de status?\n");
	scanf("%ld", &status);

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	responsePri(index, status, version, comm, oids);
}

void informRequest(){
	unsigned long version, index, status;
	char comm[1024], oid[1024], **oids;
	int counter=0, init=0;
	oids = (char**)malloc(sizeof(char*));

	printf("Qual o valor de sysUpTime.0?\n");
	scanf("%ld", &index);


	printf("Qual o valor de snmpTrapOID.0?\n");
	scanf("%ld", &status);

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	informRequestPri(index, status, version, comm, oids);
}

void trap(){
	unsigned long version, index, status;
	char comm[1024], oid[1024], **oids;
	int init=0, counter=0;
	oids = (char**)malloc(sizeof(char*));

	printf("Qual o valor de sysUpTime.0?\n");
	scanf("%ld", &index);


	printf("Qual o valor de snmpTrapOID.0?\n");
	scanf("%ld", &status);

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	trapPri(index, status, version, comm, oids);
}

void report(){
	unsigned long version, index, status;
	char comm[1024], oid[1024], mensagem[1024], **oids;
	int init=0, counter=0;
	oids = (char**)malloc(sizeof(char*));

	printf("Qual o valor de erro index?\n");
	scanf("%ld", &index);

	printf("Qual o valor de erro status?\n");
	scanf("%ld", &status);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a mensagem que deseja enviar?\n");
	fgets(mensagem, 1024, stdin);

	printf("Qual a versão do snmp?\n");
	scanf("%ld", &version);

	//Clear input buffer
	while ((c = getchar()) != '\n' && c != EOF) { }
	printf("Qual a community string?\n");
	fgets(comm, 1024, stdin);

	printf("Insira os OIDs separados por um espaço:\n");
	fgets(oid, 1024, stdin);
	for(int i = 0; oid[i] != '\0'; i++){
		if(oid[i]==' ' || oid[i+1] == '\0' || oid[i+1] == '\n'){
			if( oid[i+1] == '\0' || oid[i+1] == '\n'){
				i++;
			}
			oids = (char**) realloc(oids, sizeof(char*)*(counter+1));
			oids[counter] = (char*) malloc(sizeof(char)*(i-init));
			memcpy( oids[counter], &oid[init], i-init );
			oids[counter++][i-init] = '\0';
			init = i+1;
			if( oid[i] == '\0' || oid[i] == '\n'){
				i--;
			}
		}
	}

	reportPri(index, status, mensagem, version, comm, oids);
}

void priInput(int escolha){

	switch(escolha){
		case 0:
			getRequest();
			break;
		case 1:
			getNextRequest();
			break;
		case 2:
			getBulkRequest();
			break;
		case 3:
			response();
			break;
		case 4:
			setRequest();
			break;
		case 5:
			informRequest();
			break;
		case 6:
			trap();
			break;
		case 7:
			report();
			break;
	}
}

void main(){
	int pri;
	pri = menuPri();
	priInput(pri);
}