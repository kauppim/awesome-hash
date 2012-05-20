#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "awesome-hash.h"

uint64_t hashGenerate(const char* input, size_t length) {
	assert(input);
	
	/*
	 * Having some major troubles converting the FNV offset basis into
	 * hexadecimal form. So here, for all to be clear, the correct number
	 * in basis 10:
	 * 
	 * 14695981039346656037
	 * 
	 * Ubuntu converted this to base 16 as following:
	 * 
	 * 0xCBF29CE484222325
	 * 
	 * Then, again, various online resources gave me the value
	 * 
	 * 0xCBF29CE484222000
	 * 
	 * And Windows value was something completely different.
	 * 
	 * So, which one of these is correct? At this point, I decide to 
	 * trust Ubuntu on this.
	 * 
	 */
	
	uint64_t FNV_Offset_Basis = 0xCBF29CE484222325;
	uint64_t FNV_Prime = 0x100000001B3;
	
	
	/* 
	 * Well apparently hash isn't a reserved word in C.
	 */
	
	uint64_t hash = FNV_Offset_Basis;

	for ( size_t i = 0; i < length; i++ ) {
		hash = hash * FNV_Prime;
		hash ^= input[i];
	}

	return hash;
}
