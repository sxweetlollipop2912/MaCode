#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 300001
#define maxA 300002
#define maxR (5*maxN)

typedef long maxn, maxa, maxr;

maxn n, pos[maxA];
maxa a[maxN];
std::vector <std::pair <maxn, maxn> > res;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i];
		pos[a[i]] = i;
	}
}


void swap(const maxn i, const maxn j) {
	if (i == j) return;

	maxa tmp = a[i];
	a[i] = a[j], a[j] = tmp;

	pos[a[i]] = i;
	pos[a[j]] = j;

	res.push_back(std::make_pair(i, j));
}


maxn legal(const maxn &x) {
	return 2 * x >= n ? 0 : n - 1;
}


bool check(const maxn i, const maxn j) {
	return 2 * abs(i - j) >= n;
}


void Swap(const maxn i, const maxn j) {
	if (i == j) return;
	maxn ni = legal(i), nj = legal(j);

	if (check(i, j)) swap(i, j);
	else if (ni == nj) {
		swap(i, ni);
		swap(j, ni);
		swap(i, ni);
	}
	else {
		swap(i, ni);
		swap(j, nj);
		swap(ni, nj);
		swap(i, ni);
		swap(j, nj);
	}
}


void Process() {
	for (maxa i = 1; i <= n; i++) Swap(i - 1, pos[i]);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();

	std::cout << res.size() << '\n';
	for (maxn i = 0; i < res.size(); i++)
		std::cout << res[i].first + 1 << ' ' << res[i].second + 1 << '\n';
}