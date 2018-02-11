#ifndef	_Application_Syntax_H_
#define	_Application_Syntax_H_

#include "ApplicationSyntax.h"

/*Função que cria uma estrutura ApplicationSyntax_t*, alocando memória para esta 
 * e preenchendo com o valor "value", dependendo da flag.
 * Caso a flag seja 0, assume que o campo "present" é um ApplicationSyntax_PR_ipAddress_value
 * e preenche a "choice" ipAddress_value com um OCTET_STRING_t, criado a partir do char* dado como value.
 * Caso a flag seja 1, assume que o campo "present" é um ApplicationSyntax_PR_counter_value 
 * e preenche a "choice" counter_value com o value assumindo que este é um Counter32_t*.
 * Caso a flag seja 2, assume que o campo "present" é um ApplicationSyntax_PR_timeticks_value e 
 * preenche a "choice" timeticks_value com o value assumindo que este é um TimeTicks_t*.
 * Caso a flag seja 3, assume que o campo "present" é um ApplicationSyntax_PR_arbitrary_value e 
 * preenche a "choice" arbitrary_value com um OCTET_STRING_t, criado a partir do char* dado como value.
 * Caso a flag seja 4, assume que o campo "present" é um ApplicationSyntax_PR_big_counter_value e 
 * preenche a "choice" big_counter_value com o value assumindo que este é um INTEGER_t*.
 * Caso a flag seja 5, assume que o campo "present" é um ApplicationSyntax_PR_unsigned_integer_value 
 * e preenche a "choice" unsigned_integer_value com o value assumindo que este é um Unsigned32_t*.
*/
ApplicationSyntax_t* createApplicationSyntax(int flag, void* value);

#endif