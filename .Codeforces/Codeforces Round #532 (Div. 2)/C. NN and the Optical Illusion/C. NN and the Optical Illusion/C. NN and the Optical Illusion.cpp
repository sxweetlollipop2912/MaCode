#include "pch.h"
#include <iostream>
#include <math.h>
#include <iomanip>

#define maxN 101
#define maxR 101
#define maxR 10001
#define epsilon 0.00000001
#define pi 3.14159265358979

typedef double maxn, maxr;

maxn n;
maxr r, R;


void Prepare() {
	std::cin >> n >> r;
}


bool check(maxr x) {
	double re = 360 - (n * (acos(1 - ((2 * x * x / (double)((x + r) * (x + r))))) * 180.0 / pi));
	//std::cout << x << ' ' << re << '\n';*/
	return re > 0;

}


maxr s_range(maxr l, maxr r) {
	maxr m;

	do {
		m = (l + r) / 2;

		if (!check(m)) r = m;
		else l = m;

	} while (abs(l - r) >= epsilon);

	return m;
}


int main() {
	Prepare();
	std::cout << std::fixed;
	std::cout << std::setprecision(7) << s_range(0, maxR);
}