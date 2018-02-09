#include "message.h"
#include "OCTET_STRING.h"

Message_t* createMessage(ANY_t* data, int version, char* community){
	Message_t* message;
	OCTET_STRING_t* octet = calloc(1, sizeof(OCTET_STRING_t));
	message = calloc(1, sizeof(Message_t));
	message->version = version;
	if(OCTET_STRING_fromBuf(octet, community, -1)==-1){
		printf("Erro na conversão para OCTET_STRING.\n");
	}
	message->community = *octet;
	message->data = *data; 
	return message;
}