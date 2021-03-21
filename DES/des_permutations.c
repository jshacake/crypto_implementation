void initial_permutation(unsigned char i[8], unsigned char o[8])
{
	// initialize
	for (int i = 0; i < 8; i++) o[i] = '\x00';
	
	o[0] |= ( ( i[7] >> 6 ) & 1 ) << 7;
	o[0] |= ( ( i[6] >> 6 ) & 1 ) << 6;
	o[0] |= ( ( i[5] >> 6 ) & 1 ) << 5;
	o[0] |= ( ( i[4] >> 6 ) & 1 ) << 4;
	o[0] |= ( ( i[3] >> 6 ) & 1 ) << 3;
	o[0] |= ( ( i[2] >> 6 ) & 1 ) << 2;
	o[0] |= ( ( i[1] >> 6 ) & 1 ) << 1;
	o[0] |= ( ( i[0] >> 6 ) & 1 );
	
	o[1] |= ( ( i[7] >> 4 ) & 1 ) << 7;
	o[1] |= ( ( i[6] >> 4 ) & 1 ) << 6;
	o[1] |= ( ( i[5] >> 4 ) & 1 ) << 5;
	o[1] |= ( ( i[4] >> 4 ) & 1 ) << 4;
	o[1] |= ( ( i[3] >> 4 ) & 1 ) << 3;
	o[1] |= ( ( i[2] >> 4 ) & 1 ) << 2;
	o[1] |= ( ( i[1] >> 4 ) & 1 ) << 1;
	o[1] |= ( ( i[0] >> 4 ) & 1 );
	
	o[2] |= ( ( i[7] >> 2 ) & 1 ) << 7;
	o[2] |= ( ( i[6] >> 2 ) & 1 ) << 6;
	o[2] |= ( ( i[5] >> 2 ) & 1 ) << 5;
	o[2] |= ( ( i[4] >> 2 ) & 1 ) << 4;
	o[2] |= ( ( i[3] >> 2 ) & 1 ) << 3;
	o[2] |= ( ( i[2] >> 2 ) & 1 ) << 2;
	o[2] |= ( ( i[1] >> 2 ) & 1 ) << 1;
	o[2] |= ( ( i[0] >> 2 ) & 1 );
	
	o[3] |= ( ( i[7] >> 0 ) & 1 ) << 7;
	o[3] |= ( ( i[6] >> 0 ) & 1 ) << 6;
	o[3] |= ( ( i[5] >> 0 ) & 1 ) << 5;
	o[3] |= ( ( i[4] >> 0 ) & 1 ) << 4;
	o[3] |= ( ( i[3] >> 0 ) & 1 ) << 3;
	o[3] |= ( ( i[2] >> 0 ) & 1 ) << 2;
	o[3] |= ( ( i[1] >> 0 ) & 1 ) << 1;
	o[3] |= ( ( i[0] >> 0 ) & 1 );
	
	o[4] |= ( ( i[7] >> 7 ) & 1 ) << 7;
	o[4] |= ( ( i[6] >> 7 ) & 1 ) << 6;
	o[4] |= ( ( i[5] >> 7 ) & 1 ) << 5;
	o[4] |= ( ( i[4] >> 7 ) & 1 ) << 4;
	o[4] |= ( ( i[3] >> 7 ) & 1 ) << 3;
	o[4] |= ( ( i[2] >> 7 ) & 1 ) << 2;
	o[4] |= ( ( i[1] >> 7 ) & 1 ) << 1;
	o[4] |= ( ( i[0] >> 7 ) & 1 );
	
	o[5] |= ( ( i[7] >> 5 ) & 1 ) << 7;
	o[5] |= ( ( i[6] >> 5 ) & 1 ) << 6;
	o[5] |= ( ( i[5] >> 5 ) & 1 ) << 5;
	o[5] |= ( ( i[4] >> 5 ) & 1 ) << 4;
	o[5] |= ( ( i[3] >> 5 ) & 1 ) << 3;
	o[5] |= ( ( i[2] >> 5 ) & 1 ) << 2;
	o[5] |= ( ( i[1] >> 5 ) & 1 ) << 1;
	o[5] |= ( ( i[0] >> 5 ) & 1 );
	
	o[6] |= ( ( i[7] >> 3 ) & 1 ) << 7;
	o[6] |= ( ( i[6] >> 3 ) & 1 ) << 6;
	o[6] |= ( ( i[5] >> 3 ) & 1 ) << 5;
	o[6] |= ( ( i[4] >> 3 ) & 1 ) << 4;
	o[6] |= ( ( i[3] >> 3 ) & 1 ) << 3;
	o[6] |= ( ( i[2] >> 3 ) & 1 ) << 2;
	o[6] |= ( ( i[1] >> 3 ) & 1 ) << 1;
	o[6] |= ( ( i[0] >> 3 ) & 1 );
	
	o[7] |= ( ( i[7] >> 1 ) & 1 ) << 7;
	o[7] |= ( ( i[6] >> 1 ) & 1 ) << 6;
	o[7] |= ( ( i[5] >> 1 ) & 1 ) << 5;
	o[7] |= ( ( i[4] >> 1 ) & 1 ) << 4;
	o[7] |= ( ( i[3] >> 1 ) & 1 ) << 3;
	o[7] |= ( ( i[2] >> 1 ) & 1 ) << 2;
	o[7] |= ( ( i[1] >> 1 ) & 1 ) << 1;
	o[7] |= ( ( i[0] >> 1 ) & 1 );
	
}
void final_permutation(unsigned char i[8], unsigned char o[8])
{
	// initialize
	for (int i = 0; i < 8; i++) o[i] = '\x00';
	
	o[0] |= ( i[4] & 1 ) << 7;
	o[0] |= ( i[0] & 1 ) << 6;
	o[0] |= ( i[5] & 1 ) << 5;
	o[0] |= ( i[1] & 1 ) << 4;
	o[0] |= ( i[6] & 1 ) << 3;
	o[0] |= ( i[2] & 1 ) << 2;
	o[0] |= ( i[7] & 1 ) << 1;
	o[0] |= ( i[3] & 1 );
	
	o[1] |= ( ( i[4] >> 1 ) & 1 ) << 7;
	o[1] |= ( ( i[0] >> 1 ) & 1 ) << 6;
	o[1] |= ( ( i[5] >> 1 ) & 1 ) << 5;
	o[1] |= ( ( i[1] >> 1 ) & 1 ) << 4;
	o[1] |= ( ( i[6] >> 1 ) & 1 ) << 3;
	o[1] |= ( ( i[2] >> 1 ) & 1 ) << 2;
	o[1] |= ( ( i[7] >> 1 ) & 1 ) << 1;
	o[1] |= ( ( i[3] >> 1 ) & 1 );
	
	o[2] |= ( ( i[4] >> 2 ) & 1 ) << 7;
	o[2] |= ( ( i[0] >> 2 ) & 1 ) << 6;
	o[2] |= ( ( i[5] >> 2 ) & 1 ) << 5;
	o[2] |= ( ( i[1] >> 2 ) & 1 ) << 4;
	o[2] |= ( ( i[6] >> 2 ) & 1 ) << 3;
	o[2] |= ( ( i[2] >> 2 ) & 1 ) << 2;
	o[2] |= ( ( i[7] >> 2 ) & 1 ) << 1;
	o[2] |= ( ( i[3] >> 2 ) & 1 );
	
	o[3] |= ( ( i[4] >> 3 ) & 1 ) << 7;
	o[3] |= ( ( i[0] >> 3 ) & 1 ) << 6;
	o[3] |= ( ( i[5] >> 3 ) & 1 ) << 5;
	o[3] |= ( ( i[1] >> 3 ) & 1 ) << 4;
	o[3] |= ( ( i[6] >> 3 ) & 1 ) << 3;
	o[3] |= ( ( i[2] >> 3 ) & 1 ) << 2;
	o[3] |= ( ( i[7] >> 3 ) & 1 ) << 1;
	o[3] |= ( ( i[3] >> 3 ) & 1 );
	
	o[4] |= ( ( i[4] >> 4 ) & 1 ) << 7;
	o[4] |= ( ( i[0] >> 4 ) & 1 ) << 6;
	o[4] |= ( ( i[5] >> 4 ) & 1 ) << 5;
	o[4] |= ( ( i[1] >> 4 ) & 1 ) << 4;
	o[4] |= ( ( i[6] >> 4 ) & 1 ) << 3;
	o[4] |= ( ( i[2] >> 4 ) & 1 ) << 2;
	o[4] |= ( ( i[7] >> 4 ) & 1 ) << 1;
	o[4] |= ( ( i[3] >> 4 ) & 1 );
	
	o[5] |= ( ( i[4] >> 5 ) & 1 ) << 7;
	o[5] |= ( ( i[0] >> 5 ) & 1 ) << 6;
	o[5] |= ( ( i[5] >> 5 ) & 1 ) << 5;
	o[5] |= ( ( i[1] >> 5 ) & 1 ) << 4;
	o[5] |= ( ( i[6] >> 5 ) & 1 ) << 3;
	o[5] |= ( ( i[2] >> 5 ) & 1 ) << 2;
	o[5] |= ( ( i[7] >> 5 ) & 1 ) << 1;
	o[5] |= ( ( i[3] >> 5 ) & 1 );
	
	o[6] |= ( ( i[4] >> 6 ) & 1 ) << 7;
	o[6] |= ( ( i[0] >> 6 ) & 1 ) << 6;
	o[6] |= ( ( i[5] >> 6 ) & 1 ) << 5;
	o[6] |= ( ( i[1] >> 6 ) & 1 ) << 4;
	o[6] |= ( ( i[6] >> 6 ) & 1 ) << 3;
	o[6] |= ( ( i[2] >> 6 ) & 1 ) << 2;
	o[6] |= ( ( i[7] >> 6 ) & 1 ) << 1;
	o[6] |= ( ( i[3] >> 6 ) & 1 );
	
	o[7] |= ( ( i[4] >> 7 ) & 1 ) << 7;
	o[7] |= ( ( i[0] >> 7 ) & 1 ) << 6;
	o[7] |= ( ( i[5] >> 7 ) & 1 ) << 5;
	o[7] |= ( ( i[1] >> 7 ) & 1 ) << 4;
	o[7] |= ( ( i[6] >> 7 ) & 1 ) << 3;
	o[7] |= ( ( i[2] >> 7 ) & 1 ) << 2;
	o[7] |= ( ( i[7] >> 7 ) & 1 ) << 1;
	o[7] |= ( ( i[3] >> 7 ) & 1 );
	
}
void f_permutation(unsigned char i[4], unsigned char o[4])
{
	// initialize.. just in case :/
	for (int i = 0; i < 4; i++) o[i] = '\x00';
	
	o[0] |= ( i[1] & 1 ) << 7;
	o[0] |= ( ( i[0] >> 1 ) & 1 ) << 6;
	o[0] |= ( ( i[2] >> 4 ) & 1 ) << 5;
	o[0] |= ( ( i[2] >> 3 ) & 1 ) << 4;
	o[0] |= ( ( i[3] >> 3 ) & 1 ) << 3;
	o[0] |= ( ( i[1] >> 4 ) & 1 ) << 2;
	o[0] |= ( ( i[3] >> 4 ) & 1 ) << 1;
	o[0] |= ( ( i[2] >> 7 ) & 1 );
	
	o[1] |= ( ( i[0] >> 7 ) & 1 ) << 7;
	o[1] |= ( ( i[1] >> 1 ) & 1 ) << 6;
	o[1] |= ( ( i[2] >> 1 ) & 1 ) << 5;
	o[1] |= ( ( i[3] >> 6 ) & 1 ) << 4;
	o[1] |= ( ( i[0] >> 3 ) & 1 ) << 3;
	o[1] |= ( ( i[2] >> 6 ) & 1 ) << 2;
	o[1] |= ( ( i[3] >> 1 ) & 1 ) << 1;
	o[1] |= ( ( i[1] >> 6 ) & 1 );
	
	o[2] |= ( ( i[0] >> 6 ) & 1 ) << 7;
	o[2] |= ( ( i[0] ) & 1 ) << 6;
	o[2] |= ( ( i[2] ) & 1 ) << 5;
	o[2] |= ( ( i[1] >> 2 ) & 1 ) << 4;
	o[2] |= ( ( i[3] ) & 1 ) << 3;
	o[2] |= ( ( i[3] >> 5 ) & 1 ) << 2;
	o[2] |= ( ( i[0] >> 5 ) & 1 ) << 1;
	o[2] |= ( ( i[1] >> 7 ) & 1 );
	
	o[3] |= ( ( i[2] >> 5 ) & 1 ) << 7;
	o[3] |= ( ( i[1] >> 3 ) & 1 ) << 6;
	o[3] |= ( ( i[3] >> 2 ) & 1 ) << 5;
	o[3] |= ( ( i[0] >> 2 ) & 1 ) << 4;
	o[3] |= ( ( i[2] >> 2 ) & 1 ) << 3;
	o[3] |= ( ( i[1] >> 5 ) & 1 ) << 2;
	o[3] |= ( ( i[0] >> 4 ) & 1 ) << 1;
	o[3] |= ( ( i[3] >> 7 ) & 1 );
	
}
 
