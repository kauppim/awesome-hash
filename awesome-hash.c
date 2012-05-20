#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "awesome-hash.h"

uint64_t hashGenerate(const char* input, size_t length) {
	assert(input);
	
	uint64_t FNV_Offset_Basis = 0x14650FB0739D0383;
	uint64_t FNV_Prime = 0x100000001B3;

	uint64_t hash = FNV_Offset_Basis; // Well apparently hash isn't a reserved word in C

	for ( size_t i = 0; i < length; i++ ) {
		hash = hash * FNV_Prime;
		hash ^= input[i];
	}

	return hash;
}
