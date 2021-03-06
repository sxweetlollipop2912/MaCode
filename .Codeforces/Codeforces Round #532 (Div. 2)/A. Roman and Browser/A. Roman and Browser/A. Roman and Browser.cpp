#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 101

typedef int maxn, maxk, maxa;

struct CNT {
	maxn e;
	maxn s;
};

maxn n, E, S;
maxa a[maxN];
CNT f[maxN];
maxk k;


maxn cal(CNT a) {
	return abs((S - a.s) - (E - a.e));
}

int main() {
	std::cin >> n >> k;

	maxa re = 0;
	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];

		f[i].s = f[std::max(i - k, 0)].s;
		f[i].e = f[std::max(i - k, 0)].e;

		if (a[i] == -1) {
			f[i].s++;
			S++;
		}
		else {
			f[i].e++;
			E++;
		}

		//std::cout << f[i].s << ' ' << f[i].e << '\n';
	}

	for (maxn i = n - k + 1; i <= n; i++) re = std::max(cal(f[i]), re);

	std::cout << re;
}