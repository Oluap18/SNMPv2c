#include "any.h"

ANY_t* createANY(PDUs_t* pdu){
	uint8_t buffer[1024];
	size_t buffer_size = 1024;
	ANY_t* data;
	asn_enc_rval_t ret = asn_encode_to_buffer(0, ATS_BER, &asn_DEF_PDUs, pdu, buffer, buffer_size);
	if(ret.encoded == -1){
		printf("Erro a codificar o %s\n", ret.failed_type->name);
	}
	data = calloc(1, sizeof(ANY_t));
	data->buf = buffer;
	data->size = ret.encoded;

	return data;
}