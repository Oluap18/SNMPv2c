#include "pdus.h"
#include "PDU.h"

PDUs_t* createPDUs(void* pdu, int escolha){
	PDUs_t *pdus;
	pdus = calloc(1, sizeof(PDUs_t));
	switch(escolha){
		case 0:
			pdus->present = PDUs_PR_get_request;
			pdus->choice.get_request = *((GetRequest_PDU_t*)pdu); 
			break;
		case 1:
			pdus->present = PDUs_PR_get_next_request;
			pdus->choice.get_next_request = *((GetNextRequest_PDU_t*)pdu);
			break;
		case 2:
			pdus->present = PDUs_PR_get_bulk_request;
			pdus->choice.get_bulk_request = *((GetBulkRequest_PDU_t*)pdu);
			break;
		case 3:
			pdus->present = PDUs_PR_response;
			pdus->choice.response = *((Response_PDU_t*)pdu);
			break;
		case 4:
			pdus->present = PDUs_PR_set_request;
			pdus->choice.set_request = *((SetRequest_PDU_t*)pdu);
			break;
		case 5:
			pdus->present = PDUs_PR_inform_request;
			pdus->choice.inform_request = *((InformRequest_PDU_t*)pdu);
			break;
		case 6:
			pdus->present = PDUs_PR_snmpV2_trap;
			pdus->choice.snmpV2_trap = *((SNMPv2_Trap_PDU_t*)pdu);
			break;
		case 7:
			pdus->present = PDUs_PR_report;
			pdus->choice.report = *((Report_PDU_t*)pdu);
			break;
	}
	return pdus;
}