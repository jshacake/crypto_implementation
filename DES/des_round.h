/*
	@ name : des_round
	@@ input : bi[8]
	@@ output : bo[8]
	@@@ caller : enc, dec
	@@@@ Description : 
	
	@ name : f
	@@ input : bi[4]
	@@ output : bo[4]
	@@@ caller : round
	@@@ callee : expansion_permutation
	@@@@ Description : reference the material made by c0np4nn4...
*/
void des_round(unsigned char bi[8], unsigned char rk[6], unsigned char bo[8]);
void f(unsigned char bi[4], unsigned char rk[6], unsigned char bo[4]);
