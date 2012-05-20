#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "awesome-hash.h"

int main(void) {
	
	const char *jadajada = "Helsinki, Finland";
	const char *jadajada2 = "KauppinenMikael";
	const char *jadajada3 = "Kauppinen, Mikael";
	
	printf("%llu\n", hashGenerate(jadajada, 17));
	printf("%llu\n", hashGenerate(jadajada2, strlen(jadajada2)));
	printf("%llu\n", hashGenerate(jadajada3, strlen(jadajada3)));
	
	return 0;
}
