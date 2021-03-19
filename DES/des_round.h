/*
	@ name : round
	@@ input : b[8]		( Block )
	@@ output : b[8]	( updating )
	@@@ caller : enc, dec
	@@@@ Description : b is 'round block' and rk is 'round key'
	
	@ name : f
	@@ input : br[4]	( Block right portion )
	@@ output : br[4]	( updating)
	@@@ caller : round
	@@@ callee : expansion_permutation
	@@@@ Description : reference the material made by c0np4nn4...
*/
void des_round(unsigned char b[8], unsigned char rk[6]);
void f(unsigned char br[4], unsigned char rk[6]);
