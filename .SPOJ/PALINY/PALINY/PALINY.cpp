// AC SPOJ
// Manacher
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100001
#define pid(idx) (((idx)) * 2)
#define r(pos, L) ((pos) + (L) - 1)
#define l(pos, L) ((pos) - (L) + 1)
#define dxl(pos, cen) ((cen) * 2 - (pos))

typedef long maxn;
typedef std::string str;

maxn n, L[maxN], cen;
str s;


void Prepare() {
	std::cin >> n >> s;
}


void Count(const maxn p) {
	L[p] = std::max(r(cen, L[cen]) - p + 1, (p & 1) ? (maxn)0 : (maxn)1);

	while (r(p, L[p] + 2) <= pid(n - 1) && l(p, L[p] + 2) >= 0 && s[r(p, L[p] + 2) / 2] == s[l(p, L[p] + 2) / 2])
		L[p] += 2;
	if (r(p, L[p]) > r(cen, L[cen])) cen = p;
}


void Process() {
	L[0] = 1, cen = 0;

	for (maxn i = 1; i <= pid(n - 1); i++) {
		if (r(cen, L[cen]) >= i && l(dxl(i, cen), L[dxl(i, cen)]) > l(cen, L[cen])) L[i] = L[dxl(i, cen)];
		else Count(i);
	}

	std::cout << *std::max_element(L, L + 2 * n);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}