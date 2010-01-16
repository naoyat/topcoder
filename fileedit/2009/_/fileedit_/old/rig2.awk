BEGIN {
}
(NF == 2) {
	R = $1
	B = $2
	#printf("%2.10f\n", getProfit(R,B))
	printf("%2.20f\n", getProfit(R,B))
}
(NF == 3) {
	curr = $1
	R = $2
	B = $3
	printf("%2.20f\n", expected(curr,R,B))
}

function peer(R,B,  eR,eB,rR,rB,eTotal)
{
	if (R + B == 0) return 0;
	eR = eB = -1; eTotal = 0; rR = rB = 0;

	if (R > 0) {
		eR = peer(R-1, B) + 1
		rR = 1.0 * R / (R + B)
		eTotal += eR * rR
	}
	if (B > 0) {
		eB = peer(R, B-1) - 1
		rB = 1.0 * B / (R + B)
		eTotal += eB * rB
	}

	return (eTotal > 0) ? eTotal : 0 ## 期待値が0か負なら進まない
	# if (R + B == 0) return 0;
	
}
function expected(curr,R,B,  eR,eB,rR,rB,eTotal)
{
	if (R + B == 0) return curr;
	eR = eB = -1; eTotal = 0; rR = rB = 0;

	if (R > 0) {
		eR = expected(curr+1, R-1, B);
		rR = 1.0 * R / (R + B)
		eTotal += eR * rR
	}
	if (B > 0) {
		eB = expected(curr-1, R, B-1);
		rB = 1.0 * B / (R + B)
		eTotal += eB * rB
	}
#	if (eR >= curr && eB >= curr) {
#	if ((rR == 0 || eR >= 0) && (rB == 0 || eB >= 0)) {
#		eTotal = eR * rR + eB * rB
#	} else {
#		eTotal = curr
#	}
	# eTotal += eB * rB
#	# if (eR < 0 || eB < 0) return -1;
#	return eTotal
	return (eTotal > curr) ? eTotal : curr
}
function getProfit(R,B,e)
{
#	e = expected(0, R, B)
	e = peer(R, B)
	return (e >= 0.0)? e : 0
}
