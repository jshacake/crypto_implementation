#include <stdio.h>
#include "des_key_schedule.h"
#include "des_permutations.h"
#include "des_round.h"

void enc(unsigned char p[8], unsigned char k[8], unsigned char c[8])
{
	// block for input
	unsigned char bi[8] = {'\x00', };
	// block for output
	unsigned char bo[8] = {'\x00', };
	// round keys
	unsigned char rk[16][6] = { {'\x00'}, };
	
	
	
	key_schedule(k, rk);
		
	// initial permutation
	initial_permutation(p, bi);		// p---->bi
	
	// 16 round
	for (int i = 0; i < 16; i++) {
//		printf("[des.c] Round[%d] : ", i);
//		for (int j = 0; j < 8; j++) {
//			printf("%x ", bi[j]);
//		}
//		printf("\n");
		
		des_round(bi, rk[i], bo);
		
		for (int j = 0; j < 8; j++) {
			// bo ---> bi and initialize bo[]
			bi[j] = bo[j];
		}	
	}
	
	// 32-bit swap
	for (int i = 0; i < 8; i++) {
		bo[i] = bi[ ( i + 4 ) % 8 ];
	}
	// Now result is in unsigned char bo[8]
	
	// bi <----> bo one more time.
	for (int i = 0; i < 8; i++) {
		bi[i] = bo[i];
	}
	
	// inverse permutation
	final_permutation(bi, bo);
	
	// finish
	for (int i = 0; i < 8; i++) c[i] = bo[i];
	
}

void dec(unsigned char c[8], unsigned char k[8], unsigned char p[8])
{
	// block input
	unsigned char bi[8] = {'\x00', };
	// block output
	unsigned char bo[8] = {'\x00', };
	// round keys
	unsigned char rk[16][6] = { {'\x00', } };
	
	key_schedule(k, rk);
	
	// initial permutation
	initial_permutation(c, bi);
	
	// 16 round
	for (int i = 15; i >= 0; i--) {
		des_round(bi, rk[i], bo);
		for (int j = 0; j < 8; j++) {
			// bo ---> bi and initialize bo[]
			bi[j] = bo[j];
			bo[j] = '\x00';
		}
	}
	
	// 32-bit swap
	for (int i = 0; i < 8; i++) {
		bo[i] = bi[ ( i + 4 ) % 8 ];
	}
	// Now result is in unsigned char bo[8]
	
	// bi <----> bo one more time.
	for (int i = 0; i < 8; i++) {
		bi[i] = bo[i];
		bo[i] = '\x00';
	}
	
	// inverse permutation
	final_permutation(bi, bo);
	
	// finish
	for (int i = 0; i < 8; i++) p[i] = bo[i];
}
