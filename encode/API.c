#include "simpleSyntax.h"
#include "API.h"
#include "applicationSyntax.h"

void setRequestPri(ObjectSyntax_t* object_syntax, int flag, void* setValue){
	SimpleSyntax_t* simple;
	ApplicationSyntax_t* application;

	if(flag >=0 && flag < 4){
		create_SimpleSyntax(simple, flag, setValue);
		create_ObjectSyntax(object_syntax, 0, simple);
	}
	else{
		createApplicationSyntax(application, flag-4, setValue);
		createObjectSyntax(object_syntax, 1, application);
	}
}

void setVarbin()