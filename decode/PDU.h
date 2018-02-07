/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SNMPv2-PDU"
 * 	found in "snmp.asn1c"
 */

#ifndef	_PDU_H_
#define	_PDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "VarBindList.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum error_status {
	error_status_noError	= 0,
	error_status_tooBig	= 1,
	error_status_noSuchName	= 2,
	error_status_badValue	= 3,
	error_status_readOnly	= 4,
	error_status_genErr	= 5,
	error_status_noAccess	= 6,
	error_status_wrongType	= 7,
	error_status_wrongLength	= 8,
	error_status_wrongEncoding	= 9,
	error_status_wrongValue	= 10,
	error_status_noCreation	= 11,
	error_status_inconsistentValue	= 12,
	error_status_resourceUnavailable	= 13,
	error_status_commitFailed	= 14,
	error_status_undoFailed	= 15,
	error_status_authorizationError	= 16,
	error_status_notWritable	= 17,
	error_status_inconsistentName	= 18
} e_error_status;

/* PDU */
typedef struct PDU {
	long	 request_id;
	long	 error_status;
	long	 error_index;
	VarBindList_t	 variable_bindings;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDU;
extern asn_SEQUENCE_specifics_t asn_SPC_PDU_specs_1;
extern asn_TYPE_member_t asn_MBR_PDU_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _PDU_H_ */
#include <asn_internal.h>
