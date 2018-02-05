/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "SNMPv2-PDU"
 * 	found in "SNMPv2-PDU.asn1"
 */

#include "VarBind.h"

static asn_oer_constraints_t asn_OER_type_choice_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_choice_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  4 }	/* (0..4) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_choice_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct choice, choice.value),
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_ObjectSyntax,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"value"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct choice, choice.unSpecified),
		(ASN_TAG_CLASS_UNIVERSAL | (5 << 2)),
		0,
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"unSpecified"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct choice, choice.noSuchObject),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"noSuchObject"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct choice, choice.noSuchInstance),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"noSuchInstance"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct choice, choice.endOfMibView),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"endOfMibView"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_choice_tag2el_3[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* integer-value */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 0, 0, 0 }, /* string-value */
    { (ASN_TAG_CLASS_UNIVERSAL | (5 << 2)), 1, 0, 0 }, /* unSpecified */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* objectID-value */
    { (ASN_TAG_CLASS_APPLICATION | (0 << 2)), 0, 0, 0 }, /* ipAddress-value */
    { (ASN_TAG_CLASS_APPLICATION | (1 << 2)), 0, 0, 0 }, /* counter-value */
    { (ASN_TAG_CLASS_APPLICATION | (2 << 2)), 0, 0, 0 }, /* unsigned-integer-value */
    { (ASN_TAG_CLASS_APPLICATION | (3 << 2)), 0, 0, 0 }, /* timeticks-value */
    { (ASN_TAG_CLASS_APPLICATION | (4 << 2)), 0, 0, 0 }, /* arbitrary-value */
    { (ASN_TAG_CLASS_APPLICATION | (6 << 2)), 0, 0, 0 }, /* big-counter-value */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 0 }, /* noSuchObject */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 3, 0, 0 }, /* noSuchInstance */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 4, 0, 0 } /* endOfMibView */
};
static asn_CHOICE_specifics_t asn_SPC_choice_specs_3 = {
	sizeof(struct choice),
	offsetof(struct choice, _asn_ctx),
	offsetof(struct choice, present),
	sizeof(((struct choice *)0)->present),
	asn_MAP_choice_tag2el_3,
	13,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_choice_3 = {
	"choice",
	"choice",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_choice_constr_3, &asn_PER_type_choice_constr_3, CHOICE_constraint },
	asn_MBR_choice_3,
	5,	/* Elements count */
	&asn_SPC_choice_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_VarBind_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct VarBind, name),
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_ObjectName,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"name"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct VarBind, choice),
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_choice_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"choice"
		},
};
static const ber_tlv_tag_t asn_DEF_VarBind_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_VarBind_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, 0, 0 }, /* integer-value */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 0 }, /* string-value */
    { (ASN_TAG_CLASS_UNIVERSAL | (5 << 2)), 1, 0, 0 }, /* unSpecified */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 1 }, /* name */
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 1, -1, 0 }, /* objectID-value */
    { (ASN_TAG_CLASS_APPLICATION | (0 << 2)), 1, 0, 0 }, /* ipAddress-value */
    { (ASN_TAG_CLASS_APPLICATION | (1 << 2)), 1, 0, 0 }, /* counter-value */
    { (ASN_TAG_CLASS_APPLICATION | (2 << 2)), 1, 0, 0 }, /* unsigned-integer-value */
    { (ASN_TAG_CLASS_APPLICATION | (3 << 2)), 1, 0, 0 }, /* timeticks-value */
    { (ASN_TAG_CLASS_APPLICATION | (4 << 2)), 1, 0, 0 }, /* arbitrary-value */
    { (ASN_TAG_CLASS_APPLICATION | (6 << 2)), 1, 0, 0 }, /* big-counter-value */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 1, 0, 0 }, /* noSuchObject */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* noSuchInstance */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 1, 0, 0 } /* endOfMibView */
};
asn_SEQUENCE_specifics_t asn_SPC_VarBind_specs_1 = {
	sizeof(struct VarBind),
	offsetof(struct VarBind, _asn_ctx),
	asn_MAP_VarBind_tag2el_1,
	14,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_VarBind = {
	"VarBind",
	"VarBind",
	&asn_OP_SEQUENCE,
	asn_DEF_VarBind_tags_1,
	sizeof(asn_DEF_VarBind_tags_1)
		/sizeof(asn_DEF_VarBind_tags_1[0]), /* 1 */
	asn_DEF_VarBind_tags_1,	/* Same as above */
	sizeof(asn_DEF_VarBind_tags_1)
		/sizeof(asn_DEF_VarBind_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_VarBind_1,
	2,	/* Elements count */
	&asn_SPC_VarBind_specs_1	/* Additional specs */
};
