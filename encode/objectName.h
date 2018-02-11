#ifndef	_objectName_H_
#define	_objectName_H_

#include "ObjectName.h"

/*
 * Dada uma string relativa a um OID (ex: 0.1.1.1.0), faz parse dos números
 * e cria uma estrutura ObjectName_t*, alocando memória e preenchendo o campo
 * buf com uint8_t* relativo ao OID, e preenche o campo size com o tamanho do buf.
*/
ObjectName_t* createObjectName(char* oid);

#endif