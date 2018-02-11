#ifndef	_Application_Syntax_H_
#define	_Application_Syntax_H_

#include "ApplicationSyntax.h"

/*
 * Assume que a estrutura ApplicationSyntax está vazia, alocando memória para esta
 * e preenchendo com o valor "value", dependendo da flag. 
 * Caso a flag seja 0, assume que o value é um IpAddress_t* e preenche a estrutura 
 * ApplicationSyntax esse value. 
 * Caso a flag seja 1, assume que o value é um Counter32_t*, preenchendo
 * a estrutura com esse value. 
 * caso a flag seja 2, assume que o value é um TimeTicks_t* e preenche a estrutura com esse value.
 * caso a flag seja 3, assume que o value é um char* e preenche a estrutura com a estrutura Opaque_t*
 * contendo as informações desse char*.
 * caso a flag seja 4, assume que o value é um INTEGER_t* e preenche a estrutura com esse value.
 * caso a flag seja 5, assume que o value é um Unsigned32_t* e preenche a estrutura com esse value.
*/
ApplicationSyntax_t* createApplicationSyntax(int flag, void* value);

#endif