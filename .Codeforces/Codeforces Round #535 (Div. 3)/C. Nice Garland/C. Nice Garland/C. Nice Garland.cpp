#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 200001
#define R 0
#define G 1
#define B 2
#define maxM 4
#define MOD 3

typedef long maxn;

struct T {
	maxn a, b, c;
};

maxn n, cnt[maxM][maxM], res[maxM], re_m = maxN;


T newT(maxn a, maxn b, maxn c) {
	T re;
	re.a = a; re.b = b; re.c = c;
	return re;
}


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		char c;
		std::cin >> c;

		if (c == 'G') cnt[G][i % MOD]++;
		if (c == 'B') cnt[B][i % MOD]++;
		if (c == 'R') cnt[R][i % MOD]++;
	}
}


void Try(T x) {
	maxn a = x.a, b = x.b, c = x.c;
	maxn re = cnt[a][1] + cnt[a][2] + cnt[b][0] + cnt[b][2] + cnt[c][0] + cnt[c][1];
	if (re >= re_m) return;

	re_m = re;
	res[0] = a; res[1] = b; res[2] = c;
}


int main() {
	Prepare();
	Try(newT(G, B, R));
	Try(newT(G, R, B));
	Try(newT(B, G, R));
	Try(newT(B, R, G));
	Try(newT(R, G, B));
	Try(newT(R, B, G));
	
	std::cout << re_m << '\n';
	for (maxn i = 0; i < n; i++) {
		if (res[i % 3] == G) std::cout << 'G';
		if (res[i % 3] == R) std::cout << 'R';
		if (res[i % 3] == B) std::cout << 'B';
	}
}