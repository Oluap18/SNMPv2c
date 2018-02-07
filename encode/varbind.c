#include "varbind.h"

void createVarbind(VarBind_t* var_bind, ObjectSyntax_t* object_syntax, ObjectName_t* object_name){
	var_bind = calloc(1, sizeof(VarBind_t));
	var_bind->name = *object_name;
	var_bind->choice.present = choice_PR_value;
	var_bind->choice.choice.value = *object_syntax;
}