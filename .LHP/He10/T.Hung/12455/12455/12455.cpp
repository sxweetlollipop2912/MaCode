// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 21
#define maxR 1001

typedef long maxn;
typedef long long maxa;

maxn n, S, a[maxN], id[maxN];
bool able[maxR];
std::vector <maxn> T;


void Init() {
	id[0] = 0;

	T.clear();
	T.push_back(0);

	std::fill(able, able + maxR, 0);
	able[0] = 1;
}


bool cmp(const maxn &x, const maxn &y) {
	return a[x] < a[y];
}


void Prepare() {
	std::cin >> S >> n;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}
	std::sort(id, id + n + 1, cmp);
}


void Solder(const maxn x) {
	maxn len = T.size();
	for (maxn i = 0; i < len; i++) {
		maxn t = a[x] + T[i];
		if (t != S && (S - t < a[x] || able[t])) continue;

		able[t] = 1;
		T.push_back(t);
	}
}


void Process() {
	for (maxn i = 1; i <= n && !able[S]; i++) {
		Solder(id[i]);
		//std::cout << id[i] << '\n';
	}
	if (!able[S]) std::cout << "NO";
	else std::cout << "YES";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int	q;
	std::cin >> q;

	while (q--) {
		Init();
		Prepare();
		Process();
		std::cout << '\n';
	}
}