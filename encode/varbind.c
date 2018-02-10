#include "varbind.h"

VarBind_t* createVarbind(ObjectSyntax_t* object_syntax, ObjectName_t* object_name){
	VarBind_t* var_bind;
	var_bind = calloc(1, sizeof(VarBind_t));
	var_bind->name = *object_name;
	if(object_syntax->present==ObjectSyntax_PR_NOTHING){
		var_bind->choice.present = choice_PR_unSpecified;
	}
	else{
		var_bind->choice.present = choice_PR_value;
	}
	var_bind->choice.choice.value = *object_syntax;

	return var_bind;
}