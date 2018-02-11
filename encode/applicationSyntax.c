#include "applicationSyntax.h"

ApplicationSyntax_t* createApplicationSyntax(int flag, void* value){
	ApplicationSyntax_t* application;
	application = calloc(1, sizeof(ApplicationSyntax_t));
	OCTET_STRING_t* octet;
	INTEGER_t* i;
	switch(flag){
		case 0:
			application->present = ApplicationSyntax_PR_ipAddress_value;
			octet = calloc(1, sizeof(OCTET_STRING_t));
			if(OCTET_STRING_fromBuf(octet, value, -1) == -1){
				printf("Erro na conversão para OCTET_STRING.\n");
			}
			application->choice.ipAddress_value = *((IpAddress_t*)octet);
			break;
		case 1:
			application->present = ApplicationSyntax_PR_counter_value;
			application->choice.counter_value = *((Counter32_t*)value);
			break;
		case 2:
			application->present = ApplicationSyntax_PR_timeticks_value;
			application->choice.timeticks_value = *((TimeTicks_t*)value);
			break;
		case 3:
			application->present = ApplicationSyntax_PR_arbitrary_value;
			octet = calloc(1, sizeof(OCTET_STRING_t));
			if(OCTET_STRING_fromBuf(octet, (char*) value, -1) == -1){
				printf("Erro na conversão para OCTET_STRING.\n");
			}
			application->choice.arbitrary_value = *((Opaque_t*)octet);
			break;
		case 4:
			application->present = ApplicationSyntax_PR_big_counter_value;
			i = calloc(1, sizeof(INTEGER_t));
			asn_long2INTEGER(i, *((long*)value));
			application->choice.big_counter_value = *i;

			break;
		case 5:
			application->present = ApplicationSyntax_PR_unsigned_integer_value;
			application->choice.unsigned_integer_value = *((Unsigned32_t*)value);
			break;
	}
	return application;
}