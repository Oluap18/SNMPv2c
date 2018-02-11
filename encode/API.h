#ifndef	_API_H_
#define	_API_H_

#include "ObjectName.h"

/*
 * Envia o que está no buffer, pela porta "port" para o ip "ip".
*/
void escreveUDP(int port, char* ip, uint8_t* buffer);


/*
 * Escreve o que está no buffer para um ficheiro com o nome de "file".txt. Separa cada elemento do buffer
 * com um espaço.
*/
void escreveFicheiro(char* file, uint8_t* buffer);

/*
 * Função auxiliar que cria a primitiva codificida utilizando o esquema ASN.1/BER para um buffer.
 * Inicialmente, cria uma estrutura ObjectSyntax_t* dependendo do valor de "typeObject" e "objectValue":
 * typeObject = 0 -> objectValue é um SimpleSyntax
 * typeObject = 1 -> objectValue é um ApplicationSyntax
 * typeObject = 2 -> objectValue é descartado
 * De seguida, para cada OID no array de OIDs "oid", recebido como argumento, cria uma estrutura 
 * VarBind_t* com o ObjectName_t* relativo ao OID e ObjectSyntax_t* criado anteriormente. É criada
 * uma estrutura VarBindList_t* possuindo toas as VarBind_t*.
 * É criado o PDU relativa à primitiva em questão.
 * Após criada a estrutura do PDU, é criada a estrutura que identifica para a descodificação, o tipo de PDU
 * que foi codificado, através do campo present. A estrutura PDUs_t* é criada dependendo do pduType, sendo que:
 * pduType = 0 -> primitiva getRequest
 * pduType = 1 -> primitiva getNextRequest
 * pduType = 2 -> primitiva getBulkRequest
 * pduType = 3 -> primitiva response
 * pduType = 4 -> primitiva setRequest
 * pduType = 5 -> primitiva informRequest
 * pduType = 6 -> primitiva trap
 * pduType = 7 -> primitiva report
 * Após codificado o PDU e guardado em ANY_t*, é criada a última estrutura, Message_t* que guarda 
 * todos os dados criados anteriormente, assim como a versão do SNMP, e a community string.
 * Por fim, é codificada a estrutura Message_t* para um array de uint8_t, que é devolvido como return.
*/
uint8_t* auxPri(int typeObject, void* objectValue, int pduType, long index, long status, unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva getRequest codificada, com auxilio da função auxPri.
*/
uint8_t* getRequestPri(unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva getNextRequest codificada, com auxilio da função auxPri.
*/
uint8_t* getNextRequestPri(unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva getBulkRequest codificada, com auxilio da função auxPri.
*/
uint8_t* getBulkRequestPri(long non_r, long max_r, unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva response codificada, com auxilio da função auxPri.
*/
uint8_t* responsePri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Dependendo do valor da flag, cria diferentes estruturas:
 * flag >=0 e < 3, cria um SimpleSyntax_t*, e retorna um buffer com a 
 * primitiva setRequest codificada, com auxilio da função auxPri, dando como objectValue 
 * a estrutura criada.
 * flag >=4 , cria um ApplicationSyntax_t*, e retorna um buffer com a 
 * primitiva setRequest codificada, com auxilio da função auxPri, dando como objectValue 
 * a estrutura criada.
*/
uint8_t* setRequestPri(int flag, void* setValue, unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva informRequest codificada, com auxilio da função auxPri.
*/
uint8_t* informRequestPri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Retorna um buffer com a primitiva trap codificada, com auxilio da função auxPri.
*/
uint8_t* trapPri(long index, long status, unsigned long version, char* community, char** oid);

/*
 * Primitiva que permite guardar o index_error e o status_error, assim como uma mensagem a explicar
 * o porque do report.
 * Retorna um buffer com a primitiva report codificada, com auxilio da função auxPri.
*/
uint8_t* reportPri(long index, long status, char* mensagem, unsigned long version, char* community, char** oid);

#endif