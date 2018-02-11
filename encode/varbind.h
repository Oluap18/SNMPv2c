#ifndef	_var_bind_H_
#define	_var_bind_H_

#include "VarBind.h"
#include "ObjectSyntax.h"
#include "ObjectName.h"

/*
 * Cria uma estrutura VarBind_t*, alocando memória para esta, e preenchendo a estrutura 
 * dependendo dos valores do object_syntax dado como argumento.
 * Caso o valor present do object_syntax seja ObjectSyntax_PR_NOTHING, preenche o campo choice.present
 * da estrutura VarBind_t* com choice_PR_unSpecified, caso contrário preenche com choice_PR_value.
 * Preenche também os campos name e choice.value com o object_name e object_syntax, respetivamente (caso o valor
 * de present seja choice_PR_unSpecified, ele ignora o valor de object_syntax).
*/

VarBind_t* createVarbind(ObjectSyntax_t* object_syntax, ObjectName_t* object_name);

#endif