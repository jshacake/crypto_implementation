// 64-bit --> unsigned char[8]
// 48-bit --> unsigned char[6]

void enc(unsigned char p[8], unsigned char k[8], unsigned char c[8]);	//	result is stored in c(ciphertext)
void dec(unsigned char c[8], unsigned char k[8], unsigned char p[8]);	//	result is stored in p(plaintext)
