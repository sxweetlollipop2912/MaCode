#include "pch.h"
#include <iostream>
#include <algorithm>

#define maxN 200001
#define maxA 1000000000
#define maxR 2000000001

typedef long maxn;
typedef long long maxa;

maxn na, nb, K, pa, pb;
maxa ta, tb, a[maxN], b[maxN], res;


void Prepare() {
	std::cin >> na >> nb >> ta >> tb >> K;

	for (maxn i = 0; i < na; i++) std::cin >> a[i];
	for (maxn i = 0; i < nb; i++) std::cin >> b[i];
}


maxn MovePointer(const maxa a[], const maxn &n, maxa des, maxn pointer) {
	while (pointer < n && a[pointer] < des) pointer++;
	return pointer;
}


maxa Increase() {
	maxn kb = K - pa;
	pb = MovePointer(b, nb, a[pa] + ta, pb);
	return pb + kb >= nb ? maxR : b[pb + kb] + tb;
}


bool Process() {
	if (K >= na || K >= nb) return 0;

	res = 0, pa = -1, pb = 0;
	for (pa = 0; pa <= K; pa++) 
		res = std::max(res, Increase());

	if (res == maxR) res = -1;
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) res = -1;
	std::cout << res;
}