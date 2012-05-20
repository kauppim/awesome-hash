#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "awesome-hash.h"

int main(void) {
	
	printf("Plain English keywords and their FNV hash representations, in base 16.\n");
	
	const char *jadajada = "Helsinki, Finland";
	const char *jadajada2 = "KauppinenMikael";
	const char *jadajada3 = "Kauppinen, Mikael";
	
	printf("%s:\t%llX\n", jadajada, hashGenerate(jadajada, 17));
	printf("%s:\t%llX\n", jadajada2, hashGenerate(jadajada2, strlen(jadajada2)));
	printf("%s:\t%llX\n", jadajada3, hashGenerate(jadajada3, strlen(jadajada3)));
	
	return 0;
}
