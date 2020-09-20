#include <iostream>
#include <algorithm>
#include <math.h>

//#define maxA (maxa)1000
#define epsilon (maxl)0.00000000001
#define x first
#define y second

typedef double maxl;
typedef long long maxr, maxa;
typedef std::pair <maxa, maxa> co;

co O, B, C;
maxl OB, OC, OM;
maxr res;


maxl length(const co A, const co B) {
	return sqrt(abs(A.x - B.x) * abs(A.x - B.x) + abs(A.y - B.y) * abs(A.y - B.y));
}


maxl distFrom0(const co B, const co C) {
	maxa a = C.y - B.y, b = B.x - C.x, c = -a * B.x - b * B.y;
	return abs(c) / sqrt(a * a + b * b);
}


void Prepare() {
	std::cin >> B.x >> B.y >> C.x >> C.y;
	O.x = O.y = 0;

	OB = length(O, B);
	OC = length(O, C);
}


bool OMisNotSignificant(const co B, const co C) {
	maxa a = C.x - B.x, b = C.y - B.y, c = -a * O.x - b * O.y;
	return (a * B.x + b * B.y + c) * (a * C.x + b * C.y + c) < 0;
}


maxr Result(const maxr OM, const maxr OB, const maxr OC) {
	return OB - OM + 1 + OC - OM + 1;
}


void Process() {
	OM = std::min(OB, OC);
	if (OMisNotSignificant(B, C)) OM = distFrom0(B, C);

	res = Result(floor(OM) + 1, floor(OB), floor(OC)) + (bool)(floor(OM) && abs(OM - (maxl)(floor(OM)) < epsilon));
	//res = Result(floor(OM) + 1, floor(OB), floor(OC)) + (bool)(floor(OM) && OM == (maxl)(floor(OM)));
	std::cout << res;
}


int main() {
	Prepare();
	Process();
}