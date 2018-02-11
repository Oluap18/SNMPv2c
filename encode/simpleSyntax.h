#ifndef	_simpleSyntax_H_
#define	_simpleSyntax_H_

#include "SimpleSyntax.h"

/*
 *Função que cria uma estrutura SimpleSyntax_t*, alocando memória para esta e 
 * preenchendo com o valor "value", dependendo da flag. 
 * Caso a flag seja 0, assume que o campo "present" é um SimpleSyntax_PR_integer_value
 * e preenche a "choice" integer_value com o value assumindo que este é um long*.
 * Caso a flag seja 1, assume que o campo "present" é um SimpleSyntax_PR_string_value 
 * e preenche a "choice" string_value com um OCTET_STRING_t, criado a partir do char* dado como value.
 * Caso a flag seja 2, assume que o campo "present" é um SimpleSyntax_PR_objectID_value e 
 * preenche a "choice" objectID_value com um OBJECT_IDENTIFIER_t, criado a partir do char* dado como value.
*/
SimpleSyntax_t* createSimpleSyntax(int flag, void* value);

#endif