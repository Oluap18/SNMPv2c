#include "object_identifier.h"
#include <errno.h>
#include <asn_internal.h>

/*
 * Conversion routines.
 */
int object_identifier_fromBuf(OBJECT_IDENTIFIER_t *st, const char *str, int len){
    void *buf;

    if(st == 0 || (str == 0 && len)) {
        errno = EINVAL;
        return -1;
    }

    /*
     * Clear the OCTET STRING.
     */
    if(str == NULL) {
        FREEMEM(st->buf);
        st->buf = 0;
        st->size = 0;
        return 0;
    }

    /* Determine the original string size, if not explicitly given */
    if(len < 0)
        len = strlen(str);

    /* Allocate and fill the memory */
    buf = MALLOC(len + 1);
    if(buf == NULL)
        return -1;

    memcpy(buf, str, len);
    ((uint8_t *)buf)[len] = '\0';   /* Couldn't use memcpy(len+1)! */
    FREEMEM(st->buf);
    st->buf = (uint8_t *)buf;
    st->size = len;

    return 0;
}