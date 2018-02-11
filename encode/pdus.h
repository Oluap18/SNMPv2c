#ifndef	_pdus_H_
#define	_pdus_H_

#include "PDUs.h"

/*
 * Cria uma estrutura PDUs_t*, alocando memória para esta, e preenchendo os respetivos campos
 * com os valores dados como argumento, dependendo do valor da flag.
 * Caso a flag seja:
 * 0 assume que o pdu é respetivo a uma primitiva getRequest, atribui o o valor de PDUs_PR_get_request
 * ao campo "present" e preenche o campo "choice.get_request" com o value, assumindo que este é um GetRequest_PDU_t*.
 * 1 assume que o pdu é respetivo a uma primitiva getNextRequest, atribui o o valor de PDUs_PR_get_next_request
 * ao campo "present" e preenche o campo "choice.get_next_request" com o value, assumindo que este é um GetNextRequest_PDU_t*.
 * 2 assume que o pdu é respetivo a uma primitiva getBulkRequest, atribui o o valor de PDUs_PR_get_bulk_request
 * ao campo "present" e preenche o campo "choice.get_bulk_request" com o value, assumindo que este é um GetBulkRequest_PDU_t*.
 * 3 assume que o pdu é respetivo a uma primitiva response, atribui o o valor de PDUs_PR_response
 * ao campo "present" e preenche o campo "choice.response" com o value, assumindo que este é um Response_PDU_t*.
 * 4 assume que o pdu é respetivo a uma primitiva setRequest, atribui o o valor de PDUs_PR_set_request
 * ao campo "present" e preenche o campo "choice.set_request" com o value, assumindo que este é um SetRequest_PDU_t*.
 * 5 assume que o pdu é respetivo a uma primitiva informRequest, atribui o o valor de PDUs_PR_inform_request
 * ao campo "present" e preenche o campo "choice.inform_request" com o value, assumindo que este é um InformRequest_PDU_t*.
 * 6 assume que o pdu é respetivo a uma primitiva trap, atribui o o valor de PDUs_PR_snmpV2_trap
 * ao campo "present" e preenche o campo "choice.snmpV2_trap" com o value, assumindo que este é um SNMPv2_Trap_PDU_t*.
 * 7 assume que o pdu é respetivo a uma primitiva report, atribui o o valor de PDUs_PR_report
 * ao campo "present" e preenche o campo "choice.report" com o value, assumindo que este é um Report_PDU_t*.
*/
PDUs_t* createPDUs(void* pdu, int escolha);

#endif