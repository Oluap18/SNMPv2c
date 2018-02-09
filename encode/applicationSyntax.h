#ifndef	_Application_Syntax_H_
#define	_Application_Syntax_H_

#include "ApplicationSyntax.h"

/*
 * Assume que a estrutura ApplicationSyntax está vazia, alocando memória para esta
 * e preenchendo com o valor "value", dependendo da flag. Caso a flag seja 0,
 * assume que o value é um ipAddress_value e preenche a estrutura ApplicationSyntax esse value. 
 * Caso a flag seja 1, assume que o value é um counter_value, preenchendo
 * a estrutura com os valores adequados 
 * caso a flag seja 2, assume que o value é um unsigned long* e preenche a estrutura com o timeticks_value.
 * caso a flag seja 3, assume que o value é um char* e preenche a estrutura com o arbitrary_value
 * caso a flag seja 4, assume que o value é um int* e preenche a estrutura com o big_counter_value
 * caso a flag seja 5, assume que o value é um unsigned long* e preenche a estrutura com o unsigned_integer_value
*/
ApplicationSyntax_t* createApplicationSyntax(int flag, void* value);

#endif