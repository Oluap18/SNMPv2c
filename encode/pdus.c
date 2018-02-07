#include "pdus.h"

void createPDU(PDUs_t *pdus, SetRequest_PDU_t* setRequestPDU, int escolha){
	pdus = calloc(1, sizeof(PDUs_t));
	switch(escolha){
		case 0:
			pdus->present = PDUs_PR_get_request;
			break;
		case 1:
			pdus->present = PDUs_PR_get_next_request;
			break;
		case 2:
			pdus->present = PDUs_PR_get_bulk_request;
			break;
		case 3:
			pdus->present = PDUs_PR_response;
			break;
		case 4:
			pdus->present = PDUs_PR_set_request;
			break;
		case 5:
			pdus->present = PDUs_PR_inform_request;
			break;
		case 6:
			pdus->present = PDUs_PR_snmpV2_trap;
			break;
		case 7:
			pdus->present = PDUs_PR_report;
			break;
		case 8:
			pdus->present = PDUs_PR_set_request;
			break;
	}
	pdus->choice.set_request = *setRequestPDU; 
}