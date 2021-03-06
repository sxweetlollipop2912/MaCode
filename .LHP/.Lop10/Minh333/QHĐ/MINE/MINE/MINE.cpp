#include "pch.h"
#include <iostream>
#include <cstdio>
#include <math.h>

#pragma warning (disable:4996)

#define maxN 1001

typedef int maxn;
typedef long maxo;

struct info {
	maxn x;
	maxn y;
	maxo r;
	maxo l;
};

info a[maxN];
bool done[maxN];
maxn n;


void Prepare() {

	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		done[i] = 0;
		std::cin >> a[i].x >> a[i].y >> a[i].r >> a[i].l;
	}
}


bool explode(maxn i, maxn j) {
	double dis = pow(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2), 0.5);
	return (double)(a[i].r + a[i].l + a[j].r) >= dis;
}


void Try(maxn e) {
	done[e] = 1;

	for (maxn i = 0; i < n; i++)
		if (!done[i] && explode(e, i)) Try(i);
}


void Process() {
	Prepare();

	for (maxn i = 0; i < n; i++) {
		if (done[i]) continue;
		Try(i);
		done[i] = 0;
	}
	
	maxn re = 0;
	for (maxn i = 0; i < n; i++) re += !done[i];

	if (n > 0) std::cout << re << '\n';
}


int main() {
	//freopen("MINE.inp", "r", stdin);
	//freopen("MINE.out", "w", stdout);

	do {
		Process();
	} while (n != 0);
}