#include <Message.h>
#include <PDUs.h>
#include "VarBind.h"
#include "VarBindList.h"



uint8_t* leUDP(int port, uint8_t* buffer){
	size_t buffer_size = 1024;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	socklen_t udp_socket_size = sizeof(addr);
	bind(sock, (struct sockaddr *)&addr, udp_socket_size); 
	int recv = recvfrom(sock, buffer, buffer_size, 0, (struct sockaddr *)&addr, &udp_socket_size); 
	return buffer;

}

int buffer2pdus (uint8_t* buffer_final,size_t size,PDUs_t* pdus){
	Message_t *message = 0;
	asn_dec_rval_t rval1 = asn_decode(0, ATS_BER, &asn_DEF_Message,
	(void **)&message, buffer_final,size);


	asn_dec_rval_t rval2 = asn_decode(0, ATS_BER, &asn_DEF_PDUs,
	(void **)&pdus, message->data.buf, message->data.size);

	printf("version:%li\n",message->version);
	printf("community:%s",message->community.buf);

}

int Pdus2Pdu (PDUs_t* pdu,void* pdu_t){

	PDU_t* t_pdu = (PDU_t *) pdu_t;
	BulkPDU_t * b_pdu = (BulkPDU_t *) pdu_t;

	VarBindList_t* variable_bindings = calloc(1, sizeof(VarBindList_t));
	int i=0;
	switch(pdu->present){
		case PDUs_PR_NOTHING:
			break;
		case PDUs_PR_get_request:
			t_pdu->request_id = pdu->choice.get_request.request_id;
			t_pdu->error_status = pdu->choice.get_request.error_status;
			t_pdu->error_index = pdu->choice.get_request.error_index;
			t_pdu->variable_bindings = pdu->choice.get_request.variable_bindings;
			printf("PDU: Get_request\n");
			break;
		case PDUs_PR_get_next_request:
			t_pdu->request_id = pdu->choice.get_next_request.request_id;
			t_pdu->error_status = pdu->choice.get_next_request.error_status;
			t_pdu->error_index = pdu->choice.get_next_request.error_index;
			t_pdu->variable_bindings = pdu->choice.get_next_request.variable_bindings;
			printf("PDU: Get_next_request\n");
			break;
		case PDUs_PR_get_bulk_request:
			i=1;
			b_pdu->request_id = pdu->choice.get_bulk_request.request_id;
			b_pdu->non_repeaters = pdu->choice.get_bulk_request.non_repeaters;
			b_pdu->max_repetitions = pdu->choice.get_bulk_request.max_repetitions;
			b_pdu->variable_bindings = pdu->choice.get_bulk_request.variable_bindings;
			printf("PDU: Get_bulk_request\n");
			printf("Request_id: %li\n", b_pdu->request_id);
			printf("Non_repeators: %li\n", b_pdu->non_repeaters);
			printf("Max_repetitions: %li\n",b_pdu->max_repetitions);
			break;
		case PDUs_PR_response:
			t_pdu->request_id = pdu->choice.response.request_id;
			t_pdu->error_status = pdu->choice.response.error_status;
			t_pdu->error_index = pdu->choice.response.error_index;
			t_pdu->variable_bindings = pdu->choice.response.variable_bindings;
			printf("PDU: Response\n");
			break;
		case PDUs_PR_set_request:
			t_pdu->request_id = pdu->choice.set_request.request_id;
			t_pdu->error_status = pdu->choice.set_request.error_status;
			t_pdu->error_index = pdu->choice.set_request.error_index;
			t_pdu->variable_bindings = pdu->choice.set_request.variable_bindings;
			printf("PDU: Set_request\n");
			break;
		case PDUs_PR_inform_request:
			t_pdu->request_id = pdu->choice.inform_request.request_id;
			t_pdu->error_status = pdu->choice.inform_request.error_status;
			t_pdu->error_index = pdu->choice.inform_request.error_index;
			t_pdu->variable_bindings = pdu->choice.inform_request.variable_bindings;
			printf("PDU: Inform_request\n");
			break;
		case PDUs_PR_snmpV2_trap:
			t_pdu->request_id = pdu->choice.snmpV2_trap.request_id;
			t_pdu->error_status = pdu->choice.snmpV2_trap.error_status;
			t_pdu->error_index = pdu->choice.snmpV2_trap.error_index;
			t_pdu->variable_bindings = pdu->choice.snmpV2_trap.variable_bindings;
			printf("PDU: Trap\n");
			break;
		case PDUs_PR_report:
			t_pdu->request_id = pdu->choice.report.request_id;
			t_pdu->error_status = pdu->choice.report.error_status;
			t_pdu->error_index = pdu->choice.report.error_index;
			t_pdu->variable_bindings = pdu->choice.report.variable_bindings;
			printf("PDU: Report\n");
			break;
		default:
			break;

	}
	if(i==0){ 
		printf("Request_id: %li\n",t_pdu->request_id);
		printf("Error_status: %li\n",t_pdu->error_status);
		printf("Error_index: %li\n",t_pdu->error_index);
	}
	return 0;

}

int varBindList2VarBind(VarBindList_t *vbl,VarBind_t** vn){
	
	int j=0;
	int size = vbl->list.count;
	for(int i=0;i<size;i++){
		vn[i] = vbl->list.array[i];
		switch(vn[i]->choice.present){
			case choice_PR_NOTHING:
				break;
			case choice_PR_value:
				printf("OID: ");
				for(j=0;j<vn[i]->name.size-1;j++)
					printf("%i.",vn[i]->name.buf[j]);
				printf("%i\n",vn[i]->name.buf[j]);
				vn[i]->choice.choice.value = vbl->list.array[i]->choice.choice.value;

				break;
			case choice_PR_unSpecified:
				printf("OID: ");
				for(j=0;j<vn[i]->name.size;j++)
					printf("%i.",vn[i]->name.buf[j]);
				printf("%i\n",vn[i]->name.buf[j]);
				break;
			case choice_PR_noSuchObject:
				printf("OID: ");
				for(j=0;j<vn[i]->name.size-1;j++)
					printf("%i.",vn[i]->name.buf[j]);
				printf("%i\n",vn[i]->name.buf[j]);
				break;
			case choice_PR_noSuchInstance:
				printf("OID: ");
				for(j=0;j<vn[i]->name.size-1;j++)
					printf("%i.",vn[i]->name.buf[j]);
				printf("%i\n",vn[i]->name.buf[j]);
				break;
			case choice_PR_endOfMibView:
				printf("OID: ");
				for(j=0;j<vn[i]->name.size-1;j++)
					printf("%i.",vn[i]->name.buf[j]);
				printf("%i\n",vn[i]->name.buf[j]);
				break;
			default:
				break;
		}
	}
	return 0;
}
int varBind2ObjSyntax(ObjectSyntax_t* obj){

		int size;
		int i;
		if(obj->present == ObjectSyntax_PR_simple){
			switch(obj->choice.simple.present){ 
				case SimpleSyntax_PR_NOTHING:
					break;
				case SimpleSyntax_PR_integer_value:
					printf("integer_value: %li\n",obj->choice.simple.choice.integer_value);
					break;
				case SimpleSyntax_PR_string_value:
					printf("String_value: %s\n",obj->choice.simple.choice.string_value.buf);
					break;
				case SimpleSyntax_PR_objectID_value:
					size = obj->choice.simple.choice.objectID_value.size;
					printf("objectID_value: ");
					for(i=0;i<size;i++)
						printf("%i.",obj->choice.simple.choice.objectID_value.buf[i]);
					printf("%i",obj->choice.simple.choice.objectID_value.buf[i]);	
					break;
				default:
					break;
			}
		}
		if(obj->present == ObjectSyntax_PR_application_wide){
			switch(obj->choice.application_wide.present){
				case ApplicationSyntax_PR_NOTHING:
					break;
				case ApplicationSyntax_PR_ipAddress_value:
					size = obj->choice.application_wide.choice.ipAddress_value.size;
					printf("IpAddress_value: ");
					for(i=0;i<size;i++)
						printf("%i.",obj->choice.application_wide.choice.ipAddress_value.buf[i]);
					printf("%i",obj->choice.application_wide.choice.ipAddress_value.buf[i]);
					break;
				case ApplicationSyntax_PR_counter_value:
					printf("Counter_value :%li\n",obj->choice.application_wide.choice.counter_value);
					break;
				case ApplicationSyntax_PR_timeticks_value:
					printf("TimeTicks: %li\n",obj->choice.application_wide.choice.timeticks_value);
					break;
				case ApplicationSyntax_PR_arbitrary_value:
					printf("Arbitrary_value: %s\n",obj->choice.application_wide.choice.arbitrary_value.buf);
					break;
				case ApplicationSyntax_PR_big_counter_value:
					printf("Big_Counter_Value %s\n",obj->choice.application_wide.choice.big_counter_value.buf);
					break;
				case ApplicationSyntax_PR_unsigned_integer_value:
					printf("Counter_value :%li\n",obj->choice.application_wide.choice.unsigned_integer_value);
					break;
				default:
					break;
		
			}
		
		}
	return 0;
}

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
	printf("2- Apartir de um ficheiro.\n");
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
		varBind2ObjSyntax(&(vb[i]->choice.choice.value));
	}

	xer_fprint(stdout,&asn_DEF_PDU,t_pdu);
}


int main(){
	menu();
	return 0;
}