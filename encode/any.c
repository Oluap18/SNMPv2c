#include "any.h"

void createANY(ANY_t* data, PDUs_t* pdu){
	uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t)*1024);
	size_t buffer_size = 1024;
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu, buffer, buffer_size);
	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	PDUs_t* aux = calloc(1, sizeof(PDUs_t));
	asn_dec_rval_t rval = asn_decode(0, ATS_BER, &asn_DEF_ANY,(void **)&aux, buffer, ret.encoded);
	data->buf = buffer;
	data->size = ret.encoded;

}