#ifndef ANY_H
#define ANY_H

#include "ANY.h"
#include "PDUs.h"

/*
 * Codifica as informações do pdu, em ATS_BER, colocando em data->buf o resultado da operação,
 * em data->size o tamanho do buffer. É necessário a estrutura ANY_t já vir com memória alocada.
*/
void createANY(ANY_t* data, PDUs_t* pdu);

#endif