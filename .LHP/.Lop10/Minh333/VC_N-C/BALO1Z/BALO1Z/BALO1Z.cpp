#include "pch.h"
#include <iostream>
#include <fstream>

#define max 50
#define maxW 1000000
#define minW -1000000
#define maxRe 100

typedef int maxn;
typedef int maxa;

maxa a[max];
maxn n;
long W, smin, smax;
int re;
bool f[100][max];

void Prepare() {
	
	//freopen("BALO1Z.inp", "r", stdin);
	//freopen("BALO1Z.out", "w", stdout);
	std::cin >> n >> W;

	for (int i = 0; i < n; i++) {
		std::cin >> a[i];

		if (a[i] < 0) smin += a[i];
		else smax += a[i];
	}
}

void Set(maxn ii) {
	for (int i = 0; i < n; i++)
		f[ii][i] = f[ii - 1][i];
}

void Try(maxn i, long smin, long smax, bool count) {

	if (re == maxRe) return;

	if (smax == smin) {
		if (!count || smax != W) return;
		re++;
		Set(re);
	}
	if (i == n || smin > W || smax < W) return;


	if (a[i] < 0) {
		f[re][i] = 1;
		Try(i + 1, smin, smax + a[i], 1);
		f[re][i] = 0;
		Try(i + 1, smin - a[i], smax, count);
	}
	else {
		f[re][i] = 1;
		Try(i + 1, smin + a[i], smax, 1);
		f[re][i] = 0;
		Try(i + 1, smin, smax - a[i], count);
	}
}

int main() {
	Prepare();

	Try(0, smin, smax, 0);

	for (int i = re - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (f[i][j]) std::cout << j + 1 << ' ';
		}
		std::cout << '\n';
	}
	if (re == 0) std::cout << 0;
}