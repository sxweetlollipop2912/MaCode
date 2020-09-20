#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

#define maxN 501
#define minA -99999999
#define cost(x, y) ((x) != (y) ? (maxa)(-1) : (maxa)2)

typedef long maxn, maxa;

maxn na, nb, mxa[maxN][maxN], mxb[maxN][maxN], fina, finb;
std::string a, b, resa, resb;
maxa f[maxN][maxN], res;


void Prepare() {
	std::cin >> a >> b;
	na = a.size(), nb = b.size();

	for (maxn i = 0; i <= na; i++) std::fill(f[i], f[i] + nb + 1, minA);
	memset(mxa, 0, sizeof(mxa));
	memset(mxb, 0, sizeof(mxb));
	resa = resb = "";
}


void Trace(const maxn ia, const maxn ib) {
	if (ia < 0 || ib < 0) return;

	if (!ia) {
		for (maxn i = ib - 1; i >= 0; i--) resb += b[i], resa += '-';
		return;
	}
	if (!ib) {
		for (maxn i = ia - 1; i >= 0; i--) resa += a[i], resb += '-';
		return;
	}

	maxn nia = ia, nib = ib;
	if (f[ia - 1][ib - 1] + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = ia - 1, nib = ib - 1;
	else if (f[ia - 1][mxa[ia - 1][ib - 1]] - (ib - mxa[ia - 1][ib - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = ia - 1, nib = mxa[ia - 1][ib - 1];
	else if (f[mxb[ib - 1][ia - 1]][ib - 1] - (ia - mxb[ib - 1][ia - 1] - 1) - 4 + cost(a[ia - 1], b[ib - 1]) == f[ia][ib])
		nia = mxb[ib - 1][ia - 1], nib = ib - 1;

	if (ia) resa += a[ia - 1];
	if (ib) resb += b[ib - 1];
	for (maxn i = ia - 1; i > std::max(nia, (maxn)0); i--) resb += '-', resa += a[i - 1];
	for (maxn i = ib - 1; i > std::max(nib, (maxn)0); i--) resa += '-', resb += b[i - 1];

	Trace(nia, nib);
}


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

	res = std::max(res, f[na][nb]), fina = na, finb = nb;
	for (maxn ib = 0; ib <= nb; ib++) {
		if (res >= f[na][ib] - (nb - ib) - (maxa)4) continue;
		res = f[na][ib] - (nb - ib) - (maxa)4, fina = na, finb = ib;
	}
	for (maxn ia = 0; ia <= na; ia++) {
		if (res >= f[ia][nb] - (na - ia) - (maxa)4) continue;
		res = f[ia][nb] - (na - ia) - (maxa)4, fina = ia, finb = nb;
	}

	std::cout << res << '\n';

	for (maxn i = na; i > std::max(fina, (maxn)0); i--) resb += '-', resa += a[i - 1];
	for (maxn i = nb; i > std::max(finb, (maxn)0); i--) resa += '-', resb += b[i - 1];
	Trace(fina, finb);
	std::reverse(resa.begin(), resa.end()); std::reverse(resb.begin(), resb.end());
	std::cout << resa << '\n' << resb << '\n';
}


int main() {
	//freopen("gpsf.inp", "r", stdin);
	//freopen("gpsf.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}