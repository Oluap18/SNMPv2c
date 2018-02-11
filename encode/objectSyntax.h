#ifndef	_Object_Syntax_H_
#define	_Object_Syntax_H_

#include "ObjectSyntax.h"

/*
 * Esta função cria uma estrutura ObjectSyntax_t*, alocando memória para esta e 
 * preenchendo com o valor "value", dependendo da flag.
 * Caso a flag seja 0, assume que o campo "present" toma como valor ObjectSyntax_PR_simple
 * e preenche a "choice" simple  com value assumindo que este é do tipo SimpleSyntax_t*.
 * Caso a flag seja 1, assume que o campo "present" toma como valor ObjectSyntax_application_wide
 * e preenche a "choice" application_wide com value assumindo que este é do tipo ApplicationSyntax_t*.
 * Caso a flag seja 2, assume que o campo "present" toma como valor ObjectSyntax_PR_NOTHING 
 * e ignora o valor de value.
*/
ObjectSyntax_t* createObjectSyntax(int flag, void* value);

#endif