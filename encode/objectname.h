#ifndef	_object_name_H_
#define	_object_name_H_

#include "ObjectName.h"


/*
 * This function clears the previous value of the ObjectName (if any)
 * and then allocates a new memory with the specified content (str/size).
 * If size = -1, the size of the original string will be determined
 * using strlen(str).
 * If str equals to NULL, the function will silently clear the
 * current contents of the ObjectName.
 * Returns 0 if it was possible to perform operation, -1 otherwise.
 */
int object_Name_fromBuf(ObjectName_t *st, const char *str, int len);

#endif