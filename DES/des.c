#include <stdio.h>
#include "des_key_schedule.h"
#include "des_permutations.h"
#include "des_round.h"

void enc(unsigned char p[8], unsigned char k[8], unsigned char c[8])
{
	// round block
	unsigned char r[8] = {'\x00', };
	// block... just in case
	unsigned char b[8] = {'\x00', };
	
	unsigned char rk[6][16] = { {'\x00', }, };
	
	key_schedule(k, rk);
	initial_permutation(p, r);
	
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
