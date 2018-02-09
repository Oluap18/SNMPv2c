#include "simpleSyntax.h"
#include "API.h"
#include "applicationSyntax.h"

ObjectSyntax_t* setRequestPri(int flag, void* setValue){
	ObjectSyntax_t* object_syntax;
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;
	void* value;

	if(flag >=0 && flag < 4){
		simple = createSimpleSyntax(flag, setValue);
		value = simple;
		object_syntax = createObjectSyntax(0, simple);
	}
	else{
		application = createApplicationSyntax(flag-4, setValue);
		value = application;
		object_syntax = createObjectSyntax(1, application);
	}
	return object_syntax;
}