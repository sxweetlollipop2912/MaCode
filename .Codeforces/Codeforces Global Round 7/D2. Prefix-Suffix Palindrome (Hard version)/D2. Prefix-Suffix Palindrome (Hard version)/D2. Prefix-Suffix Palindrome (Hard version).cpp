// AC
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 2000001
#define pid(idx) (((idx) - st) * 2)
#define r(pos, L) ((pos) + (L) - 1)
#define l(pos, L) ((pos) - (L) + 1)
#define dxl(pos, cen) ((cen) * 2 - (pos))

typedef long maxn;
typedef std::string str;

maxn n, L[maxN], st, en, cen;
str s;


bool Prepare() {
	std::cin >> s;
	n = s.size();

	st = 0, en = n - 1;
	for (; st < en; st++, en--) if (s[st] != s[en]) break;
	return (st < en);
}


void Count(const maxn p) {
	L[p] = std::max(r(cen, L[cen]) - p + 1, (p & 1)? (maxn)0 : (maxn)1);

	while (r(p, L[p] + 2) <= pid(en) && l(p, L[p] + 2) >= pid(st) && s[r(p, L[p] + 2) / 2 + st] == s[l(p, L[p] + 2) / 2 + st]) 
		L[p] += 2;
	if (r(p, L[p]) > r(cen, L[cen])) cen = p;
}


void Process() {
	std::fill(L, L + 2 * n, 0);

	L[pid(st)] = 1, cen = pid(st);

	for (maxn i = pid(st) + 1; i <= pid(en); i++) {
		if (r(cen, L[cen]) >= i && l(dxl(i, cen), L[dxl(i, cen)]) > l(cen, L[cen])) L[i] = L[dxl(i, cen)];
		else Count(i);
	}

	maxn res = pid(st);
	for (maxn i = pid(st) + 1; i <= pid(en); i++)
		if ((l(i, L[i]) == pid(st) || r(i, L[i]) == pid(en)) && L[res] < L[i]) res = i;

	for (maxn i = 0; i < st; i++) std::cout << s[i];
	for (maxn i = l(res, L[res]) / 2 + st; i <= r(res, L[res]) / 2 + st; i++) std::cout << s[i];
	for (maxn i = en + 1; i < n; i++) std::cout << s[i];
	std::cout << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long t; std::cin >> t;
	while (t--) {
		if (!Prepare()) std::cout << s << '\n';
		else Process();
	}
}