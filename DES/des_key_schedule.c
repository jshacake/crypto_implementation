#include <stdio.h>

void pc_1(unsigned char k[8], unsigned char kbl[4], unsigned char kbr[4]);
void pc_2(unsigned char kbl[4], unsigned char kbr[4], unsigned char rk[6]);
void bit_rotate_1(unsigned char kbl[4], unsigned char kbr[4]);
void bit_rotate_2(unsigned char kbl[4], unsigned char kbr[4]);

void key_schedule(unsigned char k[8], unsigned char rks[16][6])
{
	// pc-1
	// key block (56-bit)
	// kbl == key block left, kbr == key block right
	// they only need 7-bit for one byte..
	unsigned char kbl[4] = { '\x00', };
	unsigned char kbr[4] = { '\x00', }; 
	
	pc_1(k, kbl, kbr);

	
	// pc-2
	
	// 1
	bit_rotate_1(kbl, kbr);
	pc_2(kbl, kbr, rks[0]);
	
	// 2
	bit_rotate_1(kbl, kbr);
	pc_2(kbl, kbr, rks[1]);
	
	// 3
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[2]);
	
	// 4
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[3]);
	
	// 5
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[4]);
	
	// 6
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[5]);
	
	// 7
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[6]);
	
	// 8
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[7]);
	
	//9
	bit_rotate_1(kbl, kbr);
	pc_2(kbl, kbr, rks[8]);
	
	// 10
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[9]);
	
	// 11
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[10]);
	
	// 12
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[11]);
	
	// 13
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[12]);
	
	// 14
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[13]);
	
	// 15
	bit_rotate_2(kbl, kbr);
	pc_2(kbl, kbr, rks[14]);
	
	// 16
	bit_rotate_1(kbl, kbr);
	pc_2(kbl, kbr, rks[15]);
	
//	printf("[*] DONE\n");
}



void bit_rotate_1(unsigned char kbl[4], unsigned char kbr[4]) {
	
//	printf("[*] bit rotate 1\n");
//	printf("[(BEFORE)bit rotate 1] kbl == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbl[i]);
//	}
//	printf(",  bkr == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbr[i]);
//	}
//	printf("\n");
	
	kbl[0]  =   kbl[0] << 1;
	kbl[0] |= ( kbl[1] >> 6 ) & 1;
	kbl[1]  =   kbl[1] << 1;
	kbl[1] |= ( kbl[2] >> 6 ) & 1;
	kbl[2]  =   kbl[2] << 1;
	kbl[2] |= ( kbl[3] >> 6 ) & 1;
	kbl[3]  =   kbl[3] << 1;
	kbl[3] |= ( kbl[0] >> 7 ) & 1;
	
	
	kbr[0]  =   kbr[0] << 1;
	kbr[0] |= ( kbr[1] >> 6 ) & 1;
	kbr[1]  =   kbr[1] << 1;
	kbr[1] |= ( kbr[2] >> 6 ) & 1;
	kbr[2]  =   kbr[2] << 1;
	kbr[2] |= ( kbr[3] >> 6 ) & 1;
	kbr[3]  =   kbr[3] << 1;
	kbr[3] |= ( kbr[0] >> 7 ) & 1;
	
	for (int i = 0; i < 4; i++) {
		kbl[i] = kbl[i] & '\x7f';
	}
		
//	printf("[(AFTER)bit rotate 1] kbl == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbl[i]);
//	}
//	printf(",  bkr == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbr[i]);
//	}
//	printf("\n");

}

void bit_rotate_2(unsigned char kbl[4], unsigned char kbr[4]) {

//	printf("[*] bit rotate 2\n");
//	printf("[(BEFORE)bit rotate 2] kbl == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbl[i]);
//	}
//	printf(",  bkr == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbr[i]);
//	}
//	printf("\n");
	
	
	unsigned char bit = '\x00';
	
	bit |= ( kbl[0] >> 6 ) & 1;
	kbl[0]  = kbl[0] << 2;
	kbl[0] |= ( ( kbl[1] >> 6 ) & 1 ) << 1;
	kbl[0] |= ( ( kbl[1] >> 5 ) & 1 );
	kbl[1]  = kbl[1] << 2;
	kbl[1] |= ( ( kbl[2] >> 6 ) & 1 ) << 1;
	kbl[1] |= ( ( kbl[2] >> 5 ) & 1 );
	kbl[2]  = kbl[2] << 2;
	kbl[2] |= ( ( kbl[3] >> 6 ) & 1 ) << 1;
	kbl[2] |= ( ( kbl[3] >> 5 ) & 1 );
	kbl[3]  = kbl[3] << 2;
	kbl[3] |= bit << 1;
	kbl[3] |= ( ( kbl[0] >> 7 ) & 1 );
	for (int i = 0; i < 4; i++) {
		kbl[i] = kbl[i] & '\x7f';
	}
	
	
	bit |= ( kbr[0] >> 6 ) & 1;
	kbr[0]  = kbr[0] << 2;
	kbr[0] |= ( ( kbr[1] >> 6 ) & 1 ) << 1;
	kbr[0] |= ( ( kbr[1] >> 5 ) & 1 );
	kbr[1]  = kbr[1] << 2;
	kbr[1] |= ( ( kbr[2] >> 6 ) & 1 ) << 1;
	kbr[1] |= ( ( kbr[2] >> 5 ) & 1 );
	kbr[2]  = kbr[2] << 2;
	kbr[2] |= ( ( kbr[3] >> 6 ) & 1 ) << 1;
	kbr[2] |= ( ( kbr[3] >> 5 ) & 1 );
	kbr[3]  = kbr[3] << 2;
	kbr[3] |= bit << 1;
	kbr[3] |= ( ( kbr[0] >> 7 ) & 1 );
	for (int i = 0; i < 4; i++) {
		kbr[i] = kbr[i] & '\x7f';
	}
	
//	printf("[(AFTER)bit rotate 2] kbl == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbl[i]);
//	}
//	printf(",  r == ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x", kbr[i]);
//	}
//	printf("\n");
		
}

void pc_1(unsigned char k[8], unsigned char kbl[4], unsigned char kbr[4]) {
	{	// kbl
		kbl[0] |= ( ( k[7] >> 7 ) & 1 ) << 6;	// 57
		kbl[0] |= ( ( k[6] >> 7 ) & 1 ) << 5;	// 49
		kbl[0] |= ( ( k[5] >> 7 ) & 1 ) << 4;	// 41
		kbl[0] |= ( ( k[4] >> 7 ) & 1 ) << 3;	// 33
		kbl[0] |= ( ( k[3] >> 7 ) & 1 ) << 2;	// 25
		kbl[0] |= ( ( k[2] >> 7 ) & 1 ) << 1;	// 17
		kbl[0] |= ( ( k[1] >> 7 ) & 1 );		// 9
		
		
		kbl[1] |= ( ( k[0] >> 7 ) & 1 ) << 6;	// 1
		kbl[1] |= ( ( k[0] >> 7 ) & 1 ) << 5;	// 58
		kbl[1] |= ( ( k[7] >> 6 ) & 1 ) << 4;	// 50
		kbl[1] |= ( ( k[6] >> 6 ) & 1 ) << 3;	// 42
		kbl[1] |= ( ( k[5] >> 6 ) & 1 ) << 2;	// 34
		kbl[1] |= ( ( k[4] >> 6 ) & 1 ) << 1;	// 26
		kbl[1] |= ( ( k[3] >> 6 ) & 1 );		// 18
		
		kbl[2] |= ( ( k[2] >> 6 ) & 1 ) << 6;	// 10
		kbl[2] |= ( ( k[1] >> 6 ) & 1 ) << 5;	// 2
		kbl[2] |= ( ( k[7] >> 5 ) & 1 ) << 4;	// 59
		kbl[2] |= ( ( k[6] >> 5 ) & 1 ) << 3;	// 51
		kbl[2] |= ( ( k[5] >> 5 ) & 1 ) << 2;	// 43
		kbl[2] |= ( ( k[4] >> 5 ) & 1 ) << 1;	// 35
		kbl[2] |= ( ( k[3] >> 5 ) & 1 );		// 27
		
		kbl[3] |= ( ( k[2] >> 5 ) & 1 ) << 6;	// 19
		kbl[3] |= ( ( k[1] >> 5 ) & 1 ) << 5;	// 11
		kbl[3] |= ( ( k[0] >> 5 ) & 1 ) << 4;	// 3
		kbl[3] |= ( ( k[7] >> 4 ) & 1 ) << 3;	// 60
		kbl[3] |= ( ( k[6] >> 4 ) & 1 ) << 2;	// 52
		kbl[3] |= ( ( k[5] >> 4 ) & 1 ) << 1;	// 44
		kbl[3] |= ( ( k[4] >> 4 ) & 1 );		// 36
	}
	
	{// kbr
		kbr[0] |= ( ( k[7] >> 1 ) & 1 ) << 6;	// 63
		kbr[0] |= ( ( k[6] >> 1 ) & 1 ) << 5;	// 55
		kbr[0] |= ( ( k[5] >> 1 ) & 1 ) << 4;	// 47
		kbr[0] |= ( ( k[4] >> 1 ) & 1 ) << 3;	// 39
		kbr[0] |= ( ( k[3] >> 1 ) & 1 ) << 2;	// 31
		kbr[0] |= ( ( k[2] >> 1 ) & 1 ) << 1;	// 23
		kbr[0] |= ( ( k[1] >> 1 ) & 1 );		// 15
		
		kbr[1] |= ( ( k[0] >> 1 ) & 1 ) << 6;	// 7
		kbr[1] |= ( ( k[7] >> 2 ) & 1 ) << 5;	// 62
		kbr[1] |= ( ( k[6] >> 2 ) & 1 ) << 4;	// 54
		kbr[1] |= ( ( k[5] >> 2 ) & 1 ) << 3;	// 46
		kbr[1] |= ( ( k[4] >> 2 ) & 1 ) << 2;	// 38
		kbr[1] |= ( ( k[3] >> 2 ) & 1 ) << 1;	// 30
		kbr[1] |= ( ( k[2] >> 2 ) & 1 );		// 22
		
		kbr[2] |= ( ( k[1] >> 2 ) & 1 ) << 6;	// 14
		kbr[2] |= ( ( k[0] >> 2 ) & 1 ) << 5;	// 6
		kbr[2] |= ( ( k[7] >> 3 ) & 1 ) << 4;	// 61
		kbr[2] |= ( ( k[6] >> 3 ) & 1 ) << 3;	// 53
		kbr[2] |= ( ( k[5] >> 3 ) & 1 ) << 2;	// 45
		kbr[2] |= ( ( k[4] >> 3 ) & 1 ) << 1;	// 37
		kbr[2] |= ( ( k[3] >> 3 ) & 1 );		// 29
		
		kbr[3] |= ( ( k[2] >> 3 ) & 1 ) << 6;	// 21
		kbr[3] |= ( ( k[1] >> 3 ) & 1 ) << 5;	// 3
		kbr[3] |= ( ( k[0] >> 3 ) & 1 ) << 4;	// 5
		kbr[3] |= ( ( k[3] >> 4 ) & 1 ) << 3;	// 28
		kbr[3] |= ( ( k[2] >> 4 ) & 1 ) << 2;	// 20
		kbr[3] |= ( ( k[1] >> 4 ) & 1 ) << 1;	// 12
		kbr[3] |= ( ( k[0] >> 4 ) & 1 );		// 4
	}
}

void pc_2(unsigned char kbl[4], unsigned char kbr[4], unsigned char rk[6]) {
	// initialize just in case
	for (int i = 0; i < 6; i++) rk[0] = '\x00';
	
	
	rk[0] |= ( ( kbl[1] ) & 1 ) << 7;
	rk[0] |= ( ( kbl[2] >> 4 ) & 1 ) << 6;
	rk[0] |= ( ( kbl[1] >> 3 ) & 1 ) << 5;
	rk[0] |= ( ( kbl[3] >> 4 ) & 1 ) << 4;
	rk[0] |= ( ( kbl[0] >> 6 ) & 1 ) << 3;
	rk[0] |= ( ( kbl[0] >> 2 ) & 1 ) << 2;
	rk[0] |= ( ( kbl[0] >> 4 ) & 1 ) << 1;
	rk[0] |= ( ( kbl[3] ) & 1 );
	
	rk[1] |= ( ( kbl[2] >> 6 ) & 1 ) << 7;
	rk[1] |= ( ( kbl[0] >> 1 ) & 1 ) << 6;
	rk[1] |= ( ( kbl[2] ) & 1 ) << 5;
	rk[1] |= ( ( kbl[1] >> 4 ) & 1 ) << 4;
	rk[1] |= ( ( kbl[3] >> 5 ) & 1 ) << 3;
	rk[1] |= ( ( kbl[2] >> 2 ) & 1 ) << 2;
	rk[1] |= ( ( kbl[1] >> 2 ) & 1 ) << 1;
	rk[1] |= ( ( kbl[0] >> 3 ) & 1 );
	
	rk[2] |= ( ( kbl[3] >> 2 ) & 1 ) << 7;
	rk[2] |= ( ( kbl[1] >> 6 ) & 1 ) << 6;
	rk[2] |= ( ( kbl[2] >> 5 ) & 1 ) << 5;
	rk[2] |= ( ( kbl[0] ) & 1 ) << 4;
	rk[2] |= ( ( kbl[3] >> 1 ) & 1 ) << 3;
	rk[2] |= ( ( kbl[2] >> 1 ) & 1 ) << 2;
	rk[2] |= ( ( kbl[1] >> 1 ) & 1 ) << 1;
	rk[2] |= ( ( kbl[0] >> 5 ) & 1 );
	//===============================================
	rk[3] |= ( ( kbr[1] >> 1 ) & 1 ) << 7;
	rk[3] |= ( ( kbr[3] >> 4 ) & 1 ) << 6;
	rk[3] |= ( ( kbr[0] >> 4 ) & 1 ) << 5;
	rk[3] |= ( ( kbr[1] >> 5 ) & 1 ) << 4;
	rk[3] |= ( ( kbr[2] >> 2 ) & 1 ) << 3;
	rk[3] |= ( ( kbr[3] >> 1 ) & 1 ) << 2;
	rk[3] |= ( ( kbr[0] >> 5 ) & 1 ) << 1;
	rk[3] |= ( ( kbr[1] >> 2 ) & 1 );
	
	rk[4] |= ( ( kbr[3] >> 5 ) & 1 ) << 7;
	rk[4] |= ( ( kbr[2] >> 4 ) & 1 ) << 6;
	rk[4] |= ( ( kbr[0] >> 2 ) & 1 ) << 5;
	rk[4] |= ( ( kbr[2] >> 1 ) & 1 ) << 4;
	rk[4] |= ( ( kbr[2] >> 5 ) & 1 ) << 3;
	rk[4] |= ( ( kbr[2] ) & 1 ) << 2;
	rk[4] |= ( ( kbr[1] >> 3 ) & 1 ) << 1;
	rk[4] |= ( ( kbr[3] ) & 1 );
	
	rk[5] |= ( ( kbr[0] >> 1 ) & 1 ) << 7;
	rk[5] |= ( ( kbr[3] >> 3 ) & 1 ) << 6;
	rk[5] |= ( ( kbr[2] >> 3 ) & 1 ) << 5;
	rk[5] |= ( ( kbr[1] ) & 1 ) << 4;
	rk[5] |= ( ( kbr[3] >> 6 ) & 1 ) << 3;
	rk[5] |= ( ( kbr[1] >> 6 ) & 1 ) << 2;
	rk[5] |= ( ( kbr[0] >> 6 ) & 1 ) << 1;
	rk[5] |= ( ( kbr[0] >> 3 ) & 1 );
}
