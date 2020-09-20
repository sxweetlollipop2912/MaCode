#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 20003
#define maxM 101
#define maxC 51
#define maxR 100002

typedef int maxn, maxm;
typedef long maxc;

maxn n, L[maxM], S[maxM];
maxm m, id[maxM];
maxc C[maxM], f[maxN];


bool cmp(const maxm &x, const maxm &y) {
	return S[x] < S[y];
}

void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < m; i++) {
		std::cin >> L[i] >> C[i] >> S[i];
		id[i] = i;
	}

	std::sort(id, id + m, cmp);
}


void Process() {
	for (maxn ii = 0; ii < m; ii++) {

		maxn i = id[ii];
		maxn left = std::max(0, S[i] - L[i]);
		maxn right = std::min(n + 1, S[i] + L[i]);

		for (maxn r = S[i]; r < right; r++) {
			for (maxn l = S[i]; l > std::max(left, r - L[i]); l--) {
				f[r] = std::max(f[r], (r - l + 1) * C[i] + f[l - 1]);
			}
		}

		for (maxn j = right; j <= n; j++) {
			f[j] = std::max(f[j], f[j - 1]);
		}
	}

	std::cout << f[n];
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}