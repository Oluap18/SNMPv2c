#ifndef	_message_H_
#define	_message_H_
#include "Message.h"
#include "ANY.h"

/*
 * Cria uma estrutura Message_t* alocando memória para esta, 
 * preenchendo a version com o int dado como argumento,
 * a community com um OCTET_STRING_t* criado com as informações do char* community dado
 * como argumento, e por fim, preenchendo data com a estrutura ANY_t* dada como argumento.
*/
Message_t* createMessage(ANY_t* data, int version, char* community);

#endif