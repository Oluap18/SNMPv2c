#ifndef	_simpleSyntax_H_
#define	_simpleSyntax_H_

#include "SimpleSyntax.h"

/*
 * Assume que a estrutura SimpleSyntax_t está vazia, alocando memória para esta
 * e preenchendo com o valor "value", dependendo da flag. Caso a flag seja 0,
 * assume que o value é um long* e preenche a estrutura SimpleSyntax_t com o
 * integer_value. 
 * caso a flag seja 1, assume que o value é um char* e preenche a estrutura com string_value
 * caso a flag seja 2, assume que o value é um char* e preenche a estrutura com objectID_value.
*/
void createSimpleSyntax(SimpleSyntax_t* simple, int flag, void* value);

#endif