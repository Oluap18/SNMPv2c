#ifndef	_message_H_
#define	_message_H_
#include "Message.h"
#include "ANY.h"

Message_t* createMessage(ANY_t* data, int version, char* community);

#endif