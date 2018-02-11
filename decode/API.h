#include <Message.h>
#include <PDUs.h>
#include "VarBind.h"
#include "VarBindList.h"

uint8_t* leUDP(int port, uint8_t* buffer);
int buffer2pdus (uint8_t* buffer_final,size_t size,PDUs_t* pdus);
int Pdus2Pdu (PDUs_t* pdu,void* pdu_t);
int varBindList2VarBind(VarBindList_t *vbl,VarBind_t** vn);
int ParseObjSyntax(ObjectSyntax_t* obj);
