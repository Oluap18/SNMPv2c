#include "objectName.h"

ObjectName_t* createObjectName(char* oid){
	ObjectName_t* object_name;
	uint8_t* buffer;
	char subbuff[1024];
	buffer = (uint8_t*)malloc(sizeof(uint8_t)*1024);
	int init = 0;
	size_t counter=0;
	object_name = calloc(1, sizeof(ObjectName_t));
	for(int i = 0; oid[i] != '\0';i++){
		if(oid[i]=='.' || oid[i+1] == '\0'){
			memcpy( subbuff, &oid[init], i-init );
			subbuff[i-init] = '\0';
			buffer[counter++] = atoi(subbuff);
			init = i+1;
		}
	}
	object_name->buf = buffer;
	object_name->size = counter;
	return object_name;
}