#include "des_permutations.h"

unsigned char S_box[8][4][16] =
{
	{	// sBox[0]
		{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 },
		{ 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
		{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 },
		{ 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 }
	},
	{	// sBox[1]
		{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },
		{ 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
		{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 },
		{ 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 }
	},
	{	// sBox[2]
		{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 },
		{ 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
		{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 },
		{ 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 }
	},
	{	// sBox[3]
		{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },
		{ 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
		{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },
		{ 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }
	},
	{	// sBox[4]
		{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },
		{ 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
		{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },
		{ 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }
	},
	{	// sBox[5]
		{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 },
		{ 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
		{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 },
		{ 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 }
	},
	{	// sBox[6]
		{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 },
		{ 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
		{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 },
		{ 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 }
	},
	{	// sBox[7]
		{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 },
		{ 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
		{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 },
		{ 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 }
	}
};

void expansion(unsigned char bi[4], unsigned char bo[6]) {
	bo[0] |= ( bi[3] & 1 ) << 7;				// 32
	bo[0] |= ( ( bi[0] >> 7 ) & 1 ) << 6;		// 1
	bo[0] |= ( ( bi[0] >> 6 ) & 1 ) << 5;		// 2
	bo[0] |= ( ( bi[0] >> 5 ) & 1 ) << 4;		// 3
	bo[0] |= ( ( bi[0] >> 4 ) & 1 ) << 3;		// 4
	bo[0] |= ( ( bi[0] >> 3 ) & 1 ) << 2;		// 5
	bo[0] |= ( ( bi[0] >> 4 ) & 1 ) << 1;		// 4
	bo[0] |= ( ( bi[0] >> 3 ) & 1 );			// 5
	
	bo[1] |= ( ( bi[0] >> 2 ) & 1 ) << 7;		// 6
	bo[1] |= ( ( bi[0] >> 1 ) & 1 ) << 6;		// 7
	bo[1] |= ( bi[0] & 1 ) << 5;				// 8
	bo[1] |= ( ( bi[1] >> 7 ) & 1 ) << 4;		// 9
	bo[1] |= ( bi[0] & 1 ) << 3;				// 8
	bo[1] |= ( ( bi[1] >> 7 ) & 1 ) << 2;		// 9
	bo[1] |= ( ( bi[1] >> 6 ) & 1 ) << 1;		// 10
	bo[1] |= ( ( bi[1] >> 5 ) & 1 );			// 11
	
	bo[2] |= ( ( bi[1] >> 4 ) & 1 ) << 7;		// 12
	bo[2] |= ( ( bi[1] >> 3 ) & 1 ) << 6;		// 13
	bo[2] |= ( ( bi[1] >> 4 ) & 1 ) << 5;		// 12
	bo[2] |= ( ( bi[1] >> 3 ) & 1 ) << 4;		// 13
	bo[2] |= ( ( bi[1] >> 2 ) & 1 ) << 3;		// 14
	bo[2] |= ( ( bi[1] >> 1 ) & 1 ) << 2;		// 15
	bo[2] |= ( bi[1] & 1 ) << 1;				// 16
	bo[2] |= ( ( bi[2] >> 7 ) & 1 );			// 17
	
	bo[3] |= ( bi[1] & 1 ) << 7;				// 16
	bo[3] |= ( ( bi[2] >> 7 ) & 1 ) << 6;		// 17
	bo[3] |= ( ( bi[2] >> 6 ) & 1 ) << 5;		// 18
	bo[3] |= ( ( bi[2] >> 5 ) & 1 ) << 4;		// 19
	bo[3] |= ( ( bi[2] >> 4 ) & 1 ) << 3;		// 20
	bo[3] |= ( ( bi[2] >> 3 ) & 1 ) << 2;		// 21
	bo[3] |= ( ( bi[2] >> 4 ) & 1 ) << 1;		// 20
	bo[3] |= ( ( bi[2] >> 3 ) & 1 );			// 21
	
	bo[4] |= ( ( bi[2] >> 2 ) & 1 ) << 7;		// 22
	bo[4] |= ( ( bi[2] >> 1 ) & 1 ) << 6;		// 23
	bo[4] |= ( ( bi[2] & 1 ) ) << 5;			// 24
	bo[4] |= ( ( bi[3] >> 7 ) & 1 ) << 4;		// 25
	bo[4] |= ( ( bi[2] & 1 ) ) << 3;			// 24
	bo[4] |= ( ( bi[3] >> 7 ) & 1 ) << 2;		// 25
	bo[4] |= ( ( bi[3] >> 6 ) & 1 ) << 1;		// 26
	bo[4] |= ( ( bi[3] >> 5 ) & 1 );			// 27
	
	bo[5] |= ( ( bi[3] >> 4 ) & 1 ) << 7;		// 28
	bo[5] |= ( ( bi[3] >> 3 ) & 1 ) << 6;		// 29
	bo[5] |= ( ( bi[3] >> 4 ) & 1 ) << 5;		// 28
	bo[5] |= ( ( bi[3] >> 3 ) & 1 ) << 4;		// 29
	bo[5] |= ( ( bi[3] >> 2 ) & 1 ) << 3;		// 30
	bo[5] |= ( ( bi[3] >> 1 ) & 1 ) << 2;		// 31
	bo[5] |= ( ( bi[3] & 1 ) ) << 1;			// 32
	bo[5] |= ( ( bi[0] >> 7 ) & 1 );			// 1
}

void f(unsigned char bi[4], unsigned char rk[6], unsigned char bo[4])
{
	
	// check
//	printf("[des_round.c] [void f(bi, rk, bo)] bi : ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x ", bi[i]);
//	}
//	printf("\n");
	
	unsigned char expanded_block[6] = {'\x00', };
	expansion(bi, expanded_block);
	// block xor
	expanded_block[0] = ( expanded_block[0] ^ rk[0] );
	expanded_block[1] = ( expanded_block[1] ^ rk[1] );
	expanded_block[2] = ( expanded_block[2] ^ rk[2] );
	expanded_block[3] = ( expanded_block[3] ^ rk[3] );
	expanded_block[4] = ( expanded_block[4] ^ rk[4] );
	expanded_block[5] = ( expanded_block[5] ^ rk[5] );
	
//	printf("[des_round.c] expanded block : ");
//	for (int i = 0; i < 6; i++) {
//		printf("%x ", expanded_block[i]);
//	}
//	printf("\n");
	
	// sb[] is for substitution. ( only use 6-bit )
	unsigned char sb[8] = {'\x00', };
	unsigned char tmp = '\x00';
	
	sb[0] |= ( ( expanded_block[0] >> 7 ) & 1 ) << 5;	// 1
	sb[0] |= ( ( expanded_block[0] >> 6 ) & 1 ) << 4;	// 2
	sb[0] |= ( ( expanded_block[0] >> 5 ) & 1 ) << 3;	// 3
	sb[0] |= ( ( expanded_block[0] >> 4 ) & 1 ) << 2;	// 4
	sb[0] |= ( ( expanded_block[0] >> 3 ) & 1 ) << 1;	// 5
	sb[0] |= ( ( expanded_block[0] >> 2 ) & 1 );			// 6
	
	sb[1] |= ( ( expanded_block[0] >> 1 ) & 1 ) << 5;	// 7
	sb[1] |= ( ( expanded_block[0] & 1 ) ) << 4;			// 8
	sb[1] |= ( ( expanded_block[1] >> 7 ) & 1 ) << 3;	// 9
	sb[1] |= ( ( expanded_block[1] >> 6 ) & 1 ) << 2;	// 10
	sb[1] |= ( ( expanded_block[1] >> 5 ) & 1 ) << 1;	// 11
	sb[1] |= ( ( expanded_block[1] >> 4 ) & 1 );			// 12
	
	sb[2] |= ( ( expanded_block[1] >> 3 ) & 1 ) << 5;	// 13
	sb[2] |= ( ( expanded_block[1] >> 2 ) & 1 ) << 4;	// 14
	sb[2] |= ( ( expanded_block[1] >> 1 ) & 1 ) << 3;	// 15
	sb[2] |= ( ( expanded_block[1] & 1 ) ) << 2;			// 16
	sb[2] |= ( ( expanded_block[2] >> 7 ) & 1 ) << 1;	// 17
	sb[2] |= ( ( expanded_block[2] >> 6 ) & 1 );			// 18
	
	sb[3] |= ( ( expanded_block[2] >> 5 ) & 1 ) << 5;	// 19
	sb[3] |= ( ( expanded_block[2] >> 4 ) & 1 ) << 4;	// 20
	sb[3] |= ( ( expanded_block[2] >> 3 ) & 1 ) << 3;	// 21
	sb[3] |= ( ( expanded_block[2] >> 2 ) & 1 ) << 2;	// 22
	sb[3] |= ( ( expanded_block[2] >> 1 ) & 1 ) << 1;	// 23
	sb[3] |= ( ( expanded_block[2] & 1 ) );				// 24
	
	sb[4] |= ( ( expanded_block[3] >> 7 ) & 1 ) << 5;	// 25
	sb[4] |= ( ( expanded_block[3] >> 6 ) & 1 ) << 4;	// 26
	sb[4] |= ( ( expanded_block[3] >> 5 ) & 1 ) << 3;	// 27
	sb[4] |= ( ( expanded_block[3] >> 4 ) & 1 ) << 2;	// 28
	sb[4] |= ( ( expanded_block[3] >> 3 ) & 1 ) << 1;	// 29
	sb[4] |= ( ( expanded_block[3] >> 2 ) & 1 );			// 30
	
	sb[5] |= ( ( expanded_block[3] >> 1 ) & 1 ) << 5;	// 31
	sb[5] |= ( ( expanded_block[3] & 1 ) ) << 4;			// 32
	sb[5] |= ( ( expanded_block[4] >> 7 ) & 1 ) << 3;	// 33
	sb[5] |= ( ( expanded_block[4] >> 6 ) & 1 ) << 2;	// 34
	sb[5] |= ( ( expanded_block[4] >> 5 ) & 1 ) << 1;	// 35
	sb[5] |= ( ( expanded_block[4] >> 4 ) & 1 );			// 36
	
	sb[6] |= ( ( expanded_block[4] >> 3 ) & 1 ) << 5;	// 37
	sb[6] |= ( ( expanded_block[4] >> 2 ) & 1 ) << 4;	// 38
	sb[6] |= ( ( expanded_block[4] >> 1 ) & 1 ) << 3;	// 39
	sb[6] |= ( ( expanded_block[4] & 1 ) ) << 2;			// 40
	sb[6] |= ( ( expanded_block[5] >> 7 ) & 1 ) << 1;	// 41
	sb[6] |= ( ( expanded_block[5] >> 6 ) & 1 );			// 42
	
	sb[7] |= ( ( expanded_block[5] >> 5 ) & 1 ) << 5;	// 43
	sb[7] |= ( ( expanded_block[5] >> 4 ) & 1 ) << 4;	// 44
	sb[7] |= ( ( expanded_block[5] >> 3 ) & 1 ) << 3;	// 45
	sb[7] |= ( ( expanded_block[5] >> 2 ) & 1 ) << 2;	// 46
	sb[7] |= ( ( expanded_block[5] >> 1 ) & 1 ) << 1;	// 47
	sb[7] |= ( ( expanded_block[5] & 1 ) );				// 48
	
	// block[] is for permutation.
	// i intended to do permutate right after constructing block[]
	unsigned char block[4] = { '\x00', };
	
	
	for (int i = 0; i < 8; i++) {	// there are 8 s-boxes
		unsigned char r = '\x00';	// 00, 01, 10, 11
		unsigned char c = '\x00';	// 0x0, ..., 0xf
		
		r |= ( ( ((sb[i] >> 5) & 1) << 1 )  | ( sb[i] & 1 ) );
		c = ( ( sb[i] >> 1 ) & '\x0f' );						// only use last 4 bit
		
		unsigned char tmp = '\x00';
		tmp |= S_box[i][r][c];
		if ( i % 2 == 0 ) {
//			printf("(%d) : %d\n", i, tmp);
			block[ i / 2 ] |= ( tmp << 4 );
		}
		else {
//			printf("(%d) : %d\n", i, tmp);
			block[ i / 2 ] |= tmp;
		}		
//		printf("[***] blocks... \n");
//		for (int i = 0; i < 4; i++) {
//			printf("%x ||", block[i]);
//		}
//		printf("\n\n");
//		printf("[location] [f]--[substitution]\n");
//		printf("[*] substituted block : %d\n", sb[i]);
//		printf("[*] r : %d\n", r);
//		printf("[*] c : %d\n", c); 
	}
	
	f_permutation(block, bo);
}

void des_round(unsigned char bi[8], unsigned char rk[6], unsigned char bo[8])
{
	unsigned char bl[4];
	unsigned char br[4];
	unsigned char tmp[4] = {'\x00', };
	
	bl[0] = bi[0];
	bl[1] = bi[1];
	bl[2] = bi[2];
	bl[3] = bi[3];
	
	br[0] = bi[4];
	br[1] = bi[5];
	br[2] = bi[6];
	br[3] = bi[7];
	
	f(br, rk, tmp);
	
	bo[0] = br[0];
	bo[1] = br[1];
	bo[2] = br[2];
	bo[3] = br[3];
	// block_xor
	
//	printf("[des_round.c] check for TMP[] : ");
//	for (int i = 0; i < 4; i++) {
//		printf("%x ", tmp[i]);
//	}
//	printf("\n\n");
	
	bo[4] = (bl[0] ^ tmp[0]);
	bo[5] = (bl[1] ^ tmp[1]);
	bo[6] = (bl[2] ^ tmp[2]);
	bo[7] = (bl[3] ^ tmp[3]);
	
}

