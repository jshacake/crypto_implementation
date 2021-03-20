#include <stdio.h>
#include "des_key_schedule.h"
#include "des_permutations.h"
#include "des_round.h"

void enc(unsigned char p[8], unsigned char k[8], unsigned char c[8])
{
	// block input
	unsigned char bi[8] = {'\x00', };
	// block output
	unsigned char bo[8] = {'\x00', };
	// round keys
	unsigned char rk[16][6] = { {'\x00'}, };
	
	key_schedule(k, rk);
	
	// initial permutation
	initial_permutation(p, bi);
	
	//=========================================DONE LINE=========================================
	
	// 16 round
	for (int i = 0; i < 16; i++) {
		des_round(bi, rk[i], bo);
		for (int j = 0; j < 8; j++) {
			// bo ---> bi and initialize bo[]
			bi[j] = bo[j];
			bo[j] = '\x00';
		}
	}
	
	// 32-bit swap
	for (int i = 0; i < 8; i++) {
		bi[i] = bo[ ( i + 4 ) % 8 ];
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
		bi[i] = bo[ ( i + 4 ) % 8 ];
	}
	// inverse permutation
	final_permutation(bi, bo);
	
	
	// finish
	for (int i = 0; i < 8; i++) p[i] = bo[i];
}

int main() {
	unsigned char p[8] = "jshack_!";
	unsigned char c[8] = {'\x00',};
	unsigned char k[8] = "loveyou";
	
	printf("[0] plaintext : 0x%x\n", p);
	printf("[0] ciphertext : 0x%x\n", c);
	printf("\n");
	
	enc(p, k, c);
	dec(c, k, p);
	
	return 0;
}
