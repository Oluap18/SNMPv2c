#include "applicationSyntax.h"

ApplicationSyntax_t* createApplicationSyntax(int flag, void* value){
	ApplicationSyntax_t* application;
	application = calloc(1, sizeof(ApplicationSyntax_t));
	OCTET_STRING_t* octet;
	Counter32_t* counter;
	TimeTicks_t* timeTick;
	INTEGER_t* integer;
	Unsigned32_t* unsig32;
	switch(flag){
		case 0:
			application->present = ApplicationSyntax_PR_ipAddress_value;
			if(OCTET_STRING_fromBuf(octet, (char*) value, -1) == -1){
				printf("Erro na conversão para OCTET_STRING.\n");
			}
			application->choice.ipAddress_value = *octet;
			break;
		case 1:
			application->present = ApplicationSyntax_PR_counter_value;
			counter = (unsigned long*) value;
			application->choice.counter_value = *counter;
			break;
		case 2:
			application->present = ApplicationSyntax_PR_timeticks_value;
			timeTick = (unsigned long*) value;
			application->choice.timeticks_value = *timeTick;
			break;
		case 3:
			application->present = ApplicationSyntax_PR_arbitrary_value;
			if(OCTET_STRING_fromBuf(octet, (char*) value, -1) == -1){
				printf("Erro na conversão para OCTET_STRING.\n");
			}
			application->choice.arbitrary_value = *octet;
			break;
		case 4:
			application->present = ApplicationSyntax_PR_big_counter_value;
			integer = (INTEGER_t*) value;
			application->choice.big_counter_value = *integer;
			break;
		case 5:
			application->present = ApplicationSyntax_PR_unsigned_integer_value;
			unsig32 = (unsigned long*) value;
			application->choice.unsigned_integer_value = *unsig32;
			break;
	}
}