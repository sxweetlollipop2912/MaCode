#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN  1000001
#define maxA  32001
#define minA -32001
#define maxRe 35
#define maxR  15

typedef long maxn;
typedef int maxa;
typedef long long maxr;

maxr remin, remax, reminc, remaxc;
maxn pmin, qmin, pmax, qmax, pminc, pmaxc, n;
int a[maxRe];



void SQR(maxr re) {

	int r[maxR], len = 0;

	while (re > 0) {
		r[len++] = re % 10;
		re /= 10;
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			a[i + j] += r[i] * r[j];
			a[i + j + 1] += a[i + j] / 10;
			a[i + j] %= 10;
		}
	}

	int i;
	for (i = maxRe - 1; i >= 0 && a[i] == 0; i--) {}
	for (i; i >= 0; i--) std::cout << a[i];
}


int main() {
	//freopen("SUBSUM2.inp", "r", stdin);
	//freopen("SUBSUM2.out", "w", stdout);

	std::cin >> n;

	for (maxn i = 0; i < n; i++) {
		maxa a;
		std::cin >> a;

		// max
		if (remaxc > remax) {
			remax = remaxc;
			pmax = pmaxc;
			qmax = i - 1;
		}

		if (remaxc + a < 0) {
			remaxc = 0;
			pmaxc = i + 1;
		}
		else remaxc += a;

		//min
		if (reminc > remin) {
			remin = reminc;
			pmin = pminc;
			qmin = i - 1;
		}

		if (reminc - a < 0) {
			reminc = 0;
			pminc = i + 1;
		}
		else reminc -= a;
	}

	if (remaxc > remax) {
		remax = remaxc;
		pmax = pmaxc;
		qmax = n - 1;
	}

	if (reminc > remin) {
		remin = reminc;
		pmin = pminc;
		qmin = n - 1;
	}

	if (n == 0) std::cout << "0\n" << "0 0";

	else if (remin > remax) {
		SQR(remin);
		std::cout << '\n' << (pmin + 1) << ' ' << (qmin + 1);
	}
	else {
		SQR(remax);
		std::cout << '\n' << (pmax + 1) << ' ' << (qmax + 1);
	}
}