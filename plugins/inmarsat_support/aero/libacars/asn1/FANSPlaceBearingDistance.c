/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "FANSACTwoWayDataLinkCommunications"
 * 	found in "../../../libacars.asn1/fans-cpdlc.asn1"
 * 	`asn1c -fcompound-names -fincludes-quoted -gen-PER`
 */

#include "FANSPlaceBearingDistance.h"

static asn_TYPE_member_t asn_MBR_FANSPlaceBearingDistance_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct FANSPlaceBearingDistance, fixName),
		(ASN_TAG_CLASS_UNIVERSAL | (22 << 2)),
		0,
		&asn_DEF_FANSFixName,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"fixName"
		},
	{ ATF_POINTER, 1, offsetof(struct FANSPlaceBearingDistance, latitudeLongitude),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_FANSLatitudeLongitude,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"latitudeLongitude"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct FANSPlaceBearingDistance, degrees),
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_FANSDegrees,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"degrees"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct FANSPlaceBearingDistance, distance),
		-1 /* Ambiguous tag (CHOICE?) */,
		0,
		&asn_DEF_FANSDistance,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"distance"
		},
};
static const int asn_MAP_FANSPlaceBearingDistance_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_FANSPlaceBearingDistance_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_FANSPlaceBearingDistance_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* latitudeLongitude */
    { (ASN_TAG_CLASS_UNIVERSAL | (22 << 2)), 0, 0, 0 }, /* fixName */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 1 }, /* degreesMagnetic */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 3, -1, 0 }, /* distanceNm */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 2, 0, 1 }, /* degreesTrue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 3, -1, 0 } /* distanceKm */
};
static asn_SEQUENCE_specifics_t asn_SPC_FANSPlaceBearingDistance_specs_1 = {
	sizeof(struct FANSPlaceBearingDistance),
	offsetof(struct FANSPlaceBearingDistance, _asn_ctx),
	asn_MAP_FANSPlaceBearingDistance_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_FANSPlaceBearingDistance_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_FANSPlaceBearingDistance = {
	"FANSPlaceBearingDistance",
	"FANSPlaceBearingDistance",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_FANSPlaceBearingDistance_tags_1,
	sizeof(asn_DEF_FANSPlaceBearingDistance_tags_1)
		/sizeof(asn_DEF_FANSPlaceBearingDistance_tags_1[0]), /* 1 */
	asn_DEF_FANSPlaceBearingDistance_tags_1,	/* Same as above */
	sizeof(asn_DEF_FANSPlaceBearingDistance_tags_1)
		/sizeof(asn_DEF_FANSPlaceBearingDistance_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_FANSPlaceBearingDistance_1,
	4,	/* Elements count */
	&asn_SPC_FANSPlaceBearingDistance_specs_1	/* Additional specs */
};

