#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

#define maxN 501
#define minA -99999999
#define cost(x, y) ((x) != (y) ? (maxa)(-1) : (maxa)2)

typedef long maxn, maxa;

maxn na, nb, mxa[maxN][maxN], mxb[maxN][maxN];
std::string a, b, resa, resb;
maxa f[maxN][maxN], res;


void Prepare() {
	std::cin >> a >> b;
	na = a.size(), nb = b.size();

	for (maxn i = 0; i <= na; i++) std::fill(f[i], f[i] + nb + 1, minA);
	memset(mxa, 0, sizeof(mxa));
	memset(mxb, 0, sizeof(mxb));
}


/*void Trace(const maxn ia, const maxn ib) {
	if (ia < 0 || ib < 0) return;

	maxn nia, nib;
	if (f[ia - 1][ib - 1] + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = ia - 1, nia = ib - 1;
	else if (f[ia - 1][mxa[ia - 1][ib - 1]] - (ib - mxa[ia - 1][ib - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = ia - 1, nib = mxa[ia - 1][ib - 1];
	else if (f[mxb[ib - 1][ia - 1]][ib - 1] - (ia - mxb[ib - 1][ia - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = mxb[ib - 1][ia - 1], nib = ib - 1;

	if (ia) resa += a[ia - 1];
	if (ib) resb += b[ib - 1];
	for (maxn i = ia - 1; i > std::max(nia, (maxn)0); i--) resa += '-';
	for (maxn i = ib - 1; i > std::max(nib, (maxn)0); i--) resb += '-';
}*/

void Process() {
	for (maxn i = 1; i <= na || i <= nb; i++) f[i][0] = f[0][i] = -4 - i;
	f[0][0] = 0, res = minA;

	for (maxn ia = 1; ia <= na; ia++) {
		for (maxn ib = 1; ib <= nb; ib++) {
			f[ia][ib] = f[ia - 1][ib - 1] + cost(a[ia - 1], b[ib - 1]);
			f[ia][ib] = std::max(f[ia][ib], f[ia - 1][mxa[ia - 1][ib - 1]] - (ib - mxa[ia - 1][ib - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]));
			f[ia][ib] = std::max(f[ia][ib], f[mxb[ib - 1][ia - 1]][ib - 1] - (ia - mxb[ib - 1][ia - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]));

			mxa[ia][ib] = f[ia][ib] + ib > f[ia][mxa[ia][ib - 1]] + mxa[ia][ib - 1] ? ib : mxa[ia][ib - 1];
			mxb[ib][ia] = f[ia][ib] + ia > f[mxb[ib][ia - 1]][ib] + mxb[ib][ia - 1] ? ia : mxb[ib][ia - 1];
		}
		res = std::max(res, f[ia][nb] - (na - ia) - (maxn)4);
	}

	res = std::max(res, f[na][nb]);
	for (maxn ib = 0; ib <= nb; ib++) res = std::max(res, f[na][ib] - (nb - ib) - (maxa)4);

	std::cout << res << '\n';
}


int main() {
	//freopen("gps.inp", "r", stdin);
	//freopen("gps.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}