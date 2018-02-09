#include "objectSyntax.h"
#include "SimpleSyntax.h"
#include "ApplicationSyntax.h"

ObjectSyntax_t* createObjectSyntax(int flag, void* value){
	ObjectSyntax_t* object;
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