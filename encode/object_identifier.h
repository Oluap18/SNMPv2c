#ifndef	_objectidentifier_H_
#define	_objectidentifier_H_

#include "OBJECT_IDENTIFIER.h"

/*
 * This function clears the previous value of the OBJECT IDENTIFIER (if any)
 * and then allocates a new memory with the specified content (str/size).
 * If size = -1, the size of the original string will be determined
 * using strlen(str).
 * If str equals to NULL, the function will silently clear the
 * current contents of the OBJECT IDENTIFIER.
 * Returns 0 if it was possible to perform operation, -1 otherwise.
 */
int object_identifier_fromBuf(OBJECT_IDENTIFIER_t *s, const char *str, int size);

#endif