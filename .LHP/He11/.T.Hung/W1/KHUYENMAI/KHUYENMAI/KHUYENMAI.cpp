#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 41
#define maxA 1e18 + 1

typedef int maxn;
typedef long long maxa, maxr;

maxn n, na, nb;
maxa T, a[maxN];
std::vector <maxa> nat;
maxr res;


void Prepare() {
	std::cin >> n >> T;
	na = n / 2; nb = n - na;

	for (maxn i = 0; i < n; i++)
		std::cin >> a[i];
}


maxr fit(const maxa x) {
	return std::upper_bound(nat.begin(), nat.end(), x) - nat.begin();
}


void Na() {
	for (maxr i = 0; i < ((maxr)1 << (maxr)na); i++) {
		maxa t = 0;
		for (maxn id = 0; id < na; id++)
			t += a[id] * (bool)(i & ((maxr)1 << (maxr)id));
		nat.push_back(t);
	}
	std::sort(nat.begin(), nat.end());
}


void Nb() {
	for (maxr i = 0; i < ((maxr)1 << (maxr)nb); i++) {
		maxa t = 0;
		for (maxn id = 0; id < nb; id++)
			t += a[id + na] * (bool)(i & ((maxr)1 << (maxr)id));
		res += fit(T - t);
	}
}


void Process() {
	Na();
	Nb();
	std::cout << res;
}


int main() {
	freopen("khuyenmai.inp", "r", stdin);
	freopen("khuyenmai.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}