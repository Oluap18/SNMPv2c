/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "COMMUNITY-BASED-SNMPv2"
 * 	found in "COMMUNITY-BASED-SNMPv2.asn1"
 */

#include "Message.h"

static asn_TYPE_member_t asn_MBR_Message_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Message, version),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_NativeInteger,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"version"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Message, community),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"community"
		},
	{ ATF_ANY_TYPE | ATF_NOFLAGS, 0, offsetof(struct Message, data),
		-1 /* Ambiguous tag (ANY?) */,
		0,
		&asn_DEF_ANY,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"data"
		},
};
static const ber_tlv_tag_t asn_DEF_Message_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Message_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 0 } /* community */
};
static asn_SEQUENCE_specifics_t asn_SPC_Message_specs_1 = {
	sizeof(struct Message),
	offsetof(struct Message, _asn_ctx),
	asn_MAP_Message_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Message = {
	"Message",
	"Message",
	&asn_OP_SEQUENCE,
	asn_DEF_Message_tags_1,
	sizeof(asn_DEF_Message_tags_1)
		/sizeof(asn_DEF_Message_tags_1[0]), /* 1 */
	asn_DEF_Message_tags_1,	/* Same as above */
	sizeof(asn_DEF_Message_tags_1)
		/sizeof(asn_DEF_Message_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Message_1,
	3,	/* Elements count */
	&asn_SPC_Message_specs_1	/* Additional specs */
};

