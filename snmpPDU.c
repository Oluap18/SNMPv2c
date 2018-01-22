#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 	Primitive Data Types		Identifier			Complex Data Types		Identifier
	
	Integer						0x02				Sequence				0x30

	Octet string				0x04				GetRequest PDU			0xA0

	Null						0x05				GetResponse PDU			0xA2

	Object Identifier			0x06				SetRequest PDU			0xA3
*/		
//int udp, char* primitiv, int version, char* communityS, int* oid
void encode(int version, char* communityS, char* primitiv){
	int messageSize = pduSize = varbindList = 0;
	int* varbind;
	/*Array que vai guardar as layers da mensagem
	1ª - SNMP Message
	2ª - SNMP PDU
	3ª - Varbind List
	4ª... - Sequencias de Layers de Varbind
	*/
	int** pdu = (int**) malloc(3*sizeof(int*));
	//Lengths das layers da mensagem
	int* size = (int*) malloc(3*sizeof(int));	
	pdu[0] = (int*) malloc(7*sizeof(int));

	//SNMP message
	pdu[0][size[0]++]=0x30;
	pdu[0][size[0]++]=44;

	//SNMP version
	pdu[0][size[0]++]=0x02;
	pdu[0][size[0]++]=1;
	pdu[0][size[0]++]=version-1;

	//SNMP Community String
	pdu[0][size[0]++]=0x04;
	pdu[0][size[0]++]=strlen(communityS);
	pdu[0] = (int*) realloc(pdu[0], (size[0]+strlen(communityS))*sizeof(int));
	for(int i=0; i < strlen(communityS); i++){
		pdu[0][size[0]++]=communityS[i];
	}

	//SNMP PDU
	switch(primitiv){
		case "GetRequest":
			pdu[1][size[1]++]=0xA0;
			break;
		case "GetResponse":
			pdu[1][size[1]++]=0xA2;
			break;
		case "SetRequest":
			pdu[1][size[1]++]=0xA3;
			break;
	}
	pdu[size[1]++];

	//Request ID?????
	pdu[1][size[1]++]=0x02;
	pdu[1][size[1]++]=1;
	pdu[1][size[1]++]=1;

	//Error
	pdu[1][size[1]++]=0x02;
	pdu[1][size[1]++]=1;
	pdu[1][size[1]++]=0;

	//Error Index
	pdu[1][size[1]++]=0x02;
	pdu[1][size[1]++]=1;
	pdu[1][size[1]++]=0;
	
=	for(int i=0; i < messageSize; i++){
		printf("%x ", pdu[i]);
	}
	printf("\n");
}

void main(){
	encode(1, "private", "GetRequest");
}