#ifndef	_var_bind_H_
#define	_var_bind_H_

#include "VarBind.h"
#include "ObjectSyntax.h"
#include "ObjectName.h"

VarBind_t* createVarbind(ObjectSyntax_t* object_syntax, ObjectName_t* object_name);

#endif