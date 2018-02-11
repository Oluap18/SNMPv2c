#ifndef	_message_H_
#define	_message_H_
#include "Message.h"
#include "ANY.h"

/*
 * Cria uma estrutura Message_t* alocando memória para esta, 
 * preenchendo o campo "version" com o int dado como argumento, preenche também o campo
 * "community" com um OCTET_STRING_t* criado com as informações do char* dado
 * como argumento, e por fim, preenchendo o campo "data" com a estrutura ANY_t* dada como argumento.
*/
Message_t* createMessage(ANY_t* data, int version, char* community);

#endif