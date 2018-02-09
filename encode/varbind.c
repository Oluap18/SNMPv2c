#include "varbind.h"

VarBind_t* createVarbind(ObjectSyntax_t* object_syntax, ObjectName_t* object_name){
	VarBind_t* var_bind;
	var_bind = calloc(1, sizeof(VarBind_t));
	var_bind->name = *object_name;
	var_bind->choice.present = choice_PR_value;
	var_bind->choice.choice.value = *object_syntax;
}