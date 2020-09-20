// undone
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 102
#define maxA 1000000001
#define maxR 100000000001

typedef int maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], f[maxN], d[maxN];
bool s[maxN];
std::vector <maxn> pos[2];


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		char c;
		std::cin >> c;

		bool id = c == '1';
		s[i] = id;
		pos[id].push_back(i);
	}

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];

		d[i] = a[i];
		for (maxn j = i - 1; j >= i / 2; j--) {
			d[i] = std::max(d[i], d[j] + a[i - j]);
		}
	}
}


maxa FindMax(bool id, maxn x) {
	maxa add = 0, re = a[1] + f[pos[id][x] - 1];

	for (maxn i = x - 1; i >= 0; i--) {
		add += d[pos[id][i + 1] - pos[id][i] - 1];
		re = std::max(re, a[x - i + 1] + add + f[pos[id][i] - 1]);
	}

	return re;
}


void Process() {
	maxn cnt[2] = { 0,0 };

	while (cnt[0] < pos[0].size() || cnt[1] < pos[1].size()) {
		bool id = cnt[1] < pos[1].size();
		if (!id || (cnt[0] < pos[0].size() && pos[0][cnt[0]] < pos[1][cnt[1]])) id = 0;

		f[pos[id][cnt[id]]] = FindMax(id, cnt[id]);
		cnt[id]++;
	}
}


int main() {
	Prepare();
	Process();
	std::cout << f[n];
}