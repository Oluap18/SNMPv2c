#ifndef ANY_H
#define ANY_H

#include "ANY.h"
#include "PDUs.h"

/*
 * Codifica a estrutura PDUs_t utilizando o esquema ASN.1/BER, colocando em data->buf o buffer resultante da operação e
 * em data->size o tamanho do buffer. É necessário a estrutura ANY_t já vir com memória alocada.
*/
void createANY(ANY_t* data, PDUs_t* pdu);

#endif