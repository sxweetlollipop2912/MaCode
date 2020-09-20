#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100003
#define maxS 400001
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)

typedef int maxn;
typedef long long maxa;

maxn n, m;
maxa a[maxN], fa[maxN], seg[maxS], f[maxN], laz[maxS];


void Prepare() {
	std::cin >> n >> m;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i], fa[i] = std::max(a[i] - a[i - 1], (maxa)0), f[i] = 0;
}


maxa Build(const maxn Ls, const maxn Rs, const maxn ids) {
	if (Ls == Rs) seg[ids] = a[Ls];
	else seg[ids] = Build(Ls, mid(Ls, Rs), cle(ids)) + Build(mid(Ls, Rs) + 1, Rs, cri(ids));
	laz[ids] = 0; return seg[ids];
}


maxa Apply_Laz(const maxn ids) {
	seg[ids] += laz[ids];
	laz[cle(ids)] += laz[ids], laz[cri(ids)] += laz[ids], laz[ids] = 0;
	return seg[ids];
}


maxa Update(const maxn Ls, const maxn Rs, const maxn ids, const maxn L, const maxn R, const maxa val) {
	if (Ls > Rs || Ls > R || Rs < L) return Apply_Laz(ids);
	if (Ls < L || Rs > R) {
		Apply_Laz(ids);
		seg[ids] = Update(Ls, mid(Ls, Rs), cle(ids), L, R, val) + Update(mid(Ls, Rs) + 1, Rs, cri(ids), L, R, val);
	}
	else {
		laz[ids] += val;
		Apply_Laz(ids);
	}
	return seg[ids];
}


maxa Get_Sum(const maxn Ls, const maxn Rs, const maxn ids, const maxn L, const maxn R) {
	if (Ls > Rs || Ls > R || Rs < L) return 0;
	Apply_Laz(ids);
	if (Ls < L || Rs > R) return Get_Sum(Ls, mid(Ls, Rs), cle(ids), L, R) + Get_Sum(mid(Ls, Rs) + 1, Rs, cri(ids), L, R);
	return seg[ids];
}


void Update_BIT(maxa bit[], maxn i, const maxa val) {
	while (i <= n) bit[i] += val, i += (i & (-i));
}

maxa GetSum_BIT(maxa bit[], maxn i) {
	maxa re = 0;
	while (i) re += bit[i], i -= (i & (-i));
	return re;
}


void Process() {
	Build(1, n, 0);
	for (maxn i = 1; i <= n; i++) Update_BIT(f, i, fa[i]);

	while (m--) {
		int opt; maxn L, R;
		std::cin >> opt >> L >> R;

		if (opt == 1) {
			maxa val; std::cin >> val;
			Update(1, n, 0, L, R, val);
			Update_BIT(f, L, std::max(Get_Sum(1, n, 0, L, L) - Get_Sum(1, n, 0, L - 1, L - 1), (maxa)0) - (GetSum_BIT(f, L) - GetSum_BIT(f, L - 1)));
			Update_BIT(f, R + 1, std::max(Get_Sum(1, n, 0, R + 1, R + 1) - Get_Sum(1, n, 0, R, R), (maxa)0) - (GetSum_BIT(f, R + 1) - GetSum_BIT(f, R)));
		}
		else std::cout << GetSum_BIT(f, R) - GetSum_BIT(f, L) + Get_Sum(1, n, 0, L, L) << '\n';
	}
}


int main() {
	//freopen("construct.inp", "r", stdin);
	//freopen("construct.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}