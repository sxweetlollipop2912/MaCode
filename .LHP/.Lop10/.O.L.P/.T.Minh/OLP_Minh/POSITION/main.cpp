#include <iostream>
#include <cstdio>

#define maxN 201
#define maxK 31
#define maxA 32001

typedef int maxn, maxk, maxa;

maxn n, len;
maxk K;
maxa a[maxN], C;
maxn re[maxN];


void Prepare() {
	std::cin >> n >> K;

	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


maxn find(maxa x, maxn l, maxn r) { // <=

	while (l != r) {
		maxn m = (l + r + 1) / 2;
		if (a[m] > x) r = m - 1;
		else l = m;
	}

	return r;
}


bool Try() {

	maxk k = 0;
	maxn l = 0, r = n - 1;
	len = 0;

	while (k < K && l < n) {
		k++;
		l = re[len++] = find(a[l] + C, l, r);
		l = find(a[l] + C, l, r) + 1;
	}

	return l == n;
}


void GenerateC() {

	maxa minC = 0, maxC = a[n - 1];

	while (minC != maxC) {
		C = (minC + maxC) / 2;
		if (!Try()) minC = C + 1;
		else maxC = C;
	}

	C = maxC;
	Try();
}


int main() {
    freopen("position.inp","r",stdin);
    freopen("position.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	Prepare();
	GenerateC();

	//std::cout << C << '\n';
	for (maxn i = 0; i < len; i++) std::cout << (re[i] + 1) << '\n';
}
