#include <stdio.h>
#include "des.h"

int main() {
	unsigned char p[8] = "c0np4nn4";
	unsigned char c[8] = {0x0,};
	unsigned char k[8] = {0x0,};
	
	printf("[0] plaintext : 0x%x%x%x%x%x%x%x%x\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
	printf("[0] ciphertext : 0x%x%x%x%x%x%x%x%x\n", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
	printf("\n");
	
	enc(p, k, c);

	printf("[+]AFTER ENCRYPTION\n ciphertext : 0x%x%x%x%x%x%x%x%x\n", c[0], c[1], c[2], c[3], c[4], c[5], c[6], c[7]);
	printf("\n");
	
	dec(c, k, p);
	printf("[+]AFTER DECRYPTION\n plaintext : 0x%s\n", p);
	printf("\n");
	
	return 0;
}
