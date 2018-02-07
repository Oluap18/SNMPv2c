#include "objectSyntax.h"
#include "SimpleSyntax.h"
#include "ApplicationSyntax.h"

void create_Object_Syntax(ObjectSyntax_t* object, int flag, void* value){
	object = calloc(1, sizeof(ObjectSyntax_t)); 
	if(flag==0){
		object->present = ObjectSyntax_PR_simple;
		object->choice.simple = *((SimpleSyntax_t*) value);
	}
	else{
		object->present = ObjectSyntax_PR_application_wide;
		object->choice.application_wide = (*(ApplicationSyntax_t*) value);
	}
}