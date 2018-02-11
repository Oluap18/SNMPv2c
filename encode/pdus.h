#ifndef	_pdus_H_
#define	_pdus_H_

#include "PDUs.h"

/*
 * Cria uma estrutura PDUs_t*, alocando memória para esta, e preenchendo os respetivos campos
 * com os valores dados como argumento, dependendo do valor da flag.
 * Caso a flag seja:
 * 0 assume que o pdu é respetivo a uma primitiva getRequest, preenchendo a estrutura com os valores adequeados.
 * 1 assume que o pdu é respetivo a uma primitiva getNextRequest, preenchendo a estrutura com os valores adequeados.
 * 2 assume que o pdu é respetivo a uma primitiva getBulkRequest, preenchendo a estrutura com os valores adequeados.
 * 3 assume que o pdu é respetivo a uma primitiva response, preenchendo a estrutura com os valores adequeados.
 * 4 assume que o pdu é respetivo a uma primitiva setRequest, preenchendo a estrutura com os valores adequeados.
 * 5 assume que o pdu é respetivo a uma primitiva informRequest, preenchendo a estrutura com os valores adequeados.
 * 6 assume que o pdu é respetivo a uma primitiva trap, preenchendo a estrutura com os valores adequeados.
 * 7 assume que o pdu é respetivo a uma primitiva report, preenchendo a estrutura com os valores adequeados.
*/

PDUs_t* createPDUs(void* pdu, int escolha);

#endif