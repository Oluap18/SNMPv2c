#ifndef	_Object_Syntax_H_
#define	_Object_Syntax_H_

#include "ObjectSyntax.h"

/*
 * Cria uma estrutura ObjectSyntax_t*, alocando memória para esta
 * e preenchendo com o valor "value", dependendo da flag. 
 * Caso a flag seja 0 assume que o value é do tipo SimpleSyntax_t*, preenchendo o 
 * object com os valores adequados. 
 * Caso a flag seja 1, assume que o value é do tipo ApplicationSyntax_t*.
 * Caso a flag seja 2, assume que não tem nenhum value.
*/
ObjectSyntax_t* createObjectSyntax(int flag, void* value);

#endif