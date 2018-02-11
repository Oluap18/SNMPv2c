#include "API.h"
#include "simpleSyntax.h"
#include "objectSyntax.h"
#include "applicationSyntax.h"
#include "varbind.h"
#include "pdu.h"
#include "pdus.h"
#include "any.h"
#include "message.h"
#include "bulk.h"
#include <arpa/inet.h>

void leUDP(){
	uint8_t buffer[1024];
	size_t buffer_size = 1024;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	socklen_t udp_socket_size = sizeof(addr);
	bind(sock, (struct sockaddr *)&addr, udp_socket_size); 
	int recv = recvfrom(sock, buffer, buffer_size, 0, (struct sockaddr *)&addr, &udp_socket_size); 

    Message_t *message = calloc(1, sizeof(Message_t));
    ANY_t* data = calloc(1, sizeof(ANY_t));
    PDUs_t* pdus = calloc(1, sizeof(PDUs_t));
    
    
	asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_Message,(void **)&message, buffer, buffer_size); 
	
	rval = asn_decode(0, ATS_BER, &asn_DEF_PDUs, (void **)&pdus, message->data.buf, message->data.size);
	xer_fprint(stdout, &asn_DEF_PDUs, pdus);

	/*VarBindList_t var_bindings = pdu->choice.set_request.variable_bindings;
	int var_list_size = var_bindings.list.count;
	VarBind_t* var_bind = var_bindings.list.array[0]; */


}

void main(){
	leUDP();
}