/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SNMPv2-PDU"
 * 	found in "SNMPv2-PDU.asn1"
 */

#ifndef	_Opaque_H_
#define	_Opaque_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Opaque */
typedef OCTET_STRING_t	 Opaque_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Opaque;
asn_struct_free_f Opaque_free;
asn_struct_print_f Opaque_print;
asn_constr_check_f Opaque_constraint;
ber_type_decoder_f Opaque_decode_ber;
der_type_encoder_f Opaque_encode_der;
xer_type_decoder_f Opaque_decode_xer;
xer_type_encoder_f Opaque_encode_xer;
oer_type_decoder_f Opaque_decode_oer;
oer_type_encoder_f Opaque_encode_oer;
per_type_decoder_f Opaque_decode_uper;
per_type_encoder_f Opaque_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _Opaque_H_ */
#include <asn_internal.h>