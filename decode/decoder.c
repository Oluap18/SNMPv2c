#include "API.h"



/*
	*A função menu interpola o utilizador sobre a possibilidade de receber um buffer ou através do 
	*terminal, de um ficheiro, ou porta UDP.
	*Nesta são alocadas todas as estruturas necessárias para o decode de um buffer assim como
	*a chamada de todas as funções auxiliares ncessárias.
*/

int menu(){
	FILE * f;
	uint8_t* buffer_final = (uint8_t*)malloc(sizeof(uint8_t)*1024);
	uint8_t y;
	int i,x=0;
	int size, porta;
	char nome[128];
	PDU_t* t_pdu = calloc(1,sizeof(PDU_t));
	PDUs_t* t_pdus = calloc(1,sizeof(PDUs_t));
	VarBind_t ** vb = (VarBind_t**) malloc(sizeof(struct VarBind*));
	printf("Pretende descodificar:\n");
	printf("1- Apartir de UDP.\n");
	printf("2- Apartir de um Ficheiro.\n");
	printf("3- Apartir do Terminal\n");
	scanf(" %i",&i);
	if(i==1){
		printf("Insira a porta\n");
		scanf("%d", &porta);
		buffer_final = leUDP(porta, buffer_final);
	}
	if(i==2){
		printf("Nome do ficheiro\n");
		scanf(" %[^\n]s",nome);
		f = fopen(nome,"r");
		while(!feof(f)){ 
			fscanf(f,"%hhi",&y);
			buffer_final[x] = y;
			x++;
		}
	}
	if(i==3){
		printf("Insira o buffer\n");
		while(!feof(stdout)){
			scanf("%hhi",&y);
			buffer_final[x] = y;
			x++;
		}
	}
	else{
		printf("Número inválido\n");
	}
		
	buffer2pdus(buffer_final,1024,t_pdus);
	Pdus2Pdu(t_pdus,t_pdu);
	size = t_pdu->variable_bindings.list.count;
	for(i=0;i<size;i++){
		vb[i] = (VarBind_t *) malloc(sizeof(struct VarBind));
	}
	varBindList2VarBind(&(t_pdu->variable_bindings),vb);
	for(i=0;i<size;i++){
		ParseObjSyntax(&(vb[i]->choice.choice.value));
	}

	xer_fprint(stdout,&asn_DEF_PDU,t_pdu);
}


int main(){
	menu();
	return 0;
}