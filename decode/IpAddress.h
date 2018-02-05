/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SNMPv2-PDU"
 * 	found in "SNMPv2-PDU.asn1"
 */

#ifndef	_IpAddress_H_
#define	_IpAddress_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* IpAddress */
typedef OCTET_STRING_t	 IpAddress_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_IpAddress_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_IpAddress;
asn_struct_free_f IpAddress_free;
asn_struct_print_f IpAddress_print;
asn_constr_check_f IpAddress_constraint;
ber_type_decoder_f IpAddress_decode_ber;
der_type_encoder_f IpAddress_encode_der;
xer_type_decoder_f IpAddress_decode_xer;
xer_type_encoder_f IpAddress_encode_xer;
oer_type_decoder_f IpAddress_decode_oer;
oer_type_encoder_f IpAddress_encode_oer;
per_type_decoder_f IpAddress_decode_uper;
per_type_encoder_f IpAddress_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _IpAddress_H_ */
#include <asn_internal.h>
