#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 401
#define maxA (maxa)(9223372036854775800)
#define minA (maxa)(-9223372036854775800)

typedef long long maxn;
typedef long long maxa;

maxn n;
maxa a[maxN], mn[maxN][maxN], mx[maxN][maxN];
bool dmn[maxN][maxN], dmx[maxN][maxN];
char op[maxN];


maxa DPmn(maxn l, maxn r);
maxa DPmx(maxn l, maxn r);


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i] >> op[i], a[i + n] = a[i], op[i + n] = op[i];
}


maxa DPmn(maxn l, maxn r) {
	if (l >= n) l -= n, r -= n;
	if (dmn[l][r]) return mn[l][r];

	dmn[l][r] = 1, mn[l][r] = maxA;

	for (maxn m = l; m < r; m++) {
		maxa lmn = DPmn(l, m), lmx = DPmx(l, m), rmn = DPmn(m + 1, r), rmx = DPmx(m + 1, r);

		if      (op[m] == '+') mn[l][r] = std::min(mn[l][r], lmn + rmn);
		else if (op[m] == '-') mn[l][r] = std::min(mn[l][r], lmn - rmx);

		else if (op[m] == '*') {
			mn[l][r] = std::min(mn[l][r], std::min(lmx * rmn, lmn * rmx));
			mn[l][r] = std::min(mn[l][r], std::min(lmx * rmx, lmn * rmn));
		}
		else if (op[m] == '?') {
			mn[l][r] = std::min(mn[l][r], std::min(lmn + rmn, lmn - rmx));
			mn[l][r] = std::min(mn[l][r], std::min(lmx * rmn, lmn * rmx));
			mn[l][r] = std::min(mn[l][r], std::min(lmx * rmx, lmn * rmn));
		}
	}
	return l == r ? (mn[l][r] = a[l]) : mn[l][r];
}


maxa DPmx(maxn l, maxn r) {
	if (l >= n) l -= n, r -= n;
	if (dmx[l][r]) return mx[l][r];

	dmx[l][r] = 1, mx[l][r] = minA;

	for (maxn m = l; m < r; m++) {
		maxa lmn = DPmn(l, m), lmx = DPmx(l, m), rmn = DPmn(m + 1, r), rmx = DPmx(m + 1, r);

		if      (op[m] == '+') mx[l][r] = std::max(mx[l][r], lmx + rmx);
		else if (op[m] == '-') mx[l][r] = std::max(mx[l][r], lmx - rmn);

		else if (op[m] == '*') {
			mx[l][r] = std::max(mx[l][r], std::max(lmx * rmn, lmn * rmx));
			mx[l][r] = std::max(mx[l][r], std::max(lmx * rmx, lmn * rmn));
		}
		else if (op[m] == '?') {
			mx[l][r] = std::max(mx[l][r], std::max(lmx + rmx, lmx - rmn));
			mx[l][r] = std::max(mx[l][r], std::max(lmx * rmn, lmn * rmx));
			mx[l][r] = std::max(mx[l][r], std::max(lmx * rmx, lmn * rmn));
		}
	}
	return l == r ? (mx[l][r] = a[l]) : mx[l][r];
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		std::cout << abs(DPmn(i, i + n - 1));
		std::cout << abs(DPmx(i, i + n - 1));
	}
}


int main() {
	//freopen("matkhau.inp", "r", stdin);
	//freopen("matkhau.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}