#ifndef	_API_H_
#define	_API_H_

#include "ObjectName.h"

/*
 * Cria um pdu com a primitiva PDUs_PR_get_request, com request_id de 0, contendo um objectSyntax nulo.
 * Preenche a primitiva com a versão, a community string e os vários OIDs, com os valores
 * dados como argumentos.
*/
void getRequestPri(unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_get_next_request, com request_id de 1, contendo um objectSyntax nulo.
 * Preenche a primitiva com a versão, a community string e os vários OIDs, com os valores
 * dados como argumentos.
*/
void getNextRequestPri(unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_get_bulk_request, com request_id de 2, contendo um objectSyntax nulo.
 * Preenche a primitiva os valores de non_repeaters e max_repeaters com os valores dados como argumentos
 * non_r e max_r respetivamente, preenchendo os campos de error_index e error_status com esses valores.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_response, com request_id de 3, contendo um objectSyntax nulo.
 * Preenche a primitiva os valores de error_index e error_status com os valores dados como argumentos
 * index e statuts respetivamente.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void responsePri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_set_request, com request_id de 4, 
 * contendo um objectSyntax de acordo com a flag.
 * Caso a flag seja 0, cria uma estrutura SimpleSyntax com o valor de Integer.
 * Caso a flag seja 1, cria uma estrutura SimpleSyntax com o valor de String.
 * Caso a flag seja 2, cria uma estrutura SimpleSyntax com o valor de ObjectID.
 * Caso a flag seja 3, cria uma estrutura ApplicationSyntax com o valor de IpAddress.
 * Caso a flag seja 4, cria uma estrutura ApplicationSyntax com o valor de Counter.
 * Caso a flag seja 5, cria uma estrutura ApplicationSyntax com o valor de TimeTicks.
 * Caso a flag seja 6, cria uma estrutura ApplicationSyntax com o valor de Arbitrário.
 * Caso a flag seja 7, cria uma estrutura ApplicationSyntax com o valor de BigCounter.
 * Caso a flag seja 8, cria uma estrutura ApplicationSyntax com o valor de UnsignedInteger.
 * Preenche a primitiva os valores de error_index e error_status a 0.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void setRequestPri(int flag, void* setValue, unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_inform_request, com request_id de 5, contendo um objectSyntax nulo.
 * Preenche a primitiva os valores de error_index e error_status com os valores dados como argumentos
 * index e statuts respetivamente.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void informRequestPri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_snmpV2_trap, com request_id de 6, contendo um objectSyntax nulo.
 * Preenche a primitiva os valores de error_index e error_status com os valores dados como argumentos
 * index e statuts respetivamente.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void trapPri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Cria um pdu com a primitiva PDUs_PR_report, com request_id de 7, contendo um SimpleSyntax.
 * Preenche a primitiva os valores de error_index e error_status com os valores dados como argumentos
 * index e statuts respetivamente e guarda a mensagem de erro dada como argumento na estrutura SimpleSyntax
 * criada, guardando como valor de string.
 * Preenche também a versão, a community string e os vários OIDs, com os valores dados como argumentos.
*/
void reportPri(long index, long status, char* mensagem, unsigned long version, char* community, char** oid);

#endif