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
	
	unsigned char rk[6][16] = { {'\x00', }, };
	
	key_schedule(k, rk);
	initial_permutation(p, bi);
	for (int i = 0; i < 8; i++) {
		des_round(bi, rk, bo);
		des_round(bo, rk, bi);
	}
	
}

void dec(unsigned char c[8], unsigned char k[8], unsigned char p[8])
{
}

int main() {
	unsigned char p[8] = "jshack_!";
	unsigned char c[8] = {'\x00',};
	unsigned char k[8] = "loveyou";
	enc(p, k, c);
	return 0;
}
