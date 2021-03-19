/* 
	@ name : init_permutation
	@@ input : i[8]
	@@ output : o[8]
	@@@ caller : enc, dec
	
	@ name : final_permutation
	@@ input : i[8]
	@@ output : o[8]
	@@@ caller : enc, dec
	
	@ name : f_permutation
	@@ input : i[4]
	@@ output : o[6]
	@@@ caller : des_f
*/
void initial_permutation(unsigned char i[8], unsigned char o[8]);
void final_permutation(unsigned char i[8], unsigned char o[8]);
void f_permutation(unsigned char i[4], unsigned char o[4]);
 
