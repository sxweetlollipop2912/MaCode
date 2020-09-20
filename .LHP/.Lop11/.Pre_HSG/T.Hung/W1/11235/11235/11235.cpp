// AC SPOJ, UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 100001
#define maxS (4 * maxN)
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)

typedef long maxn, maxa;

maxn tree[maxS], n, Q, st[maxN], en[maxN], fr[maxN];
maxa a[maxN];

void Prepare() {
	std::cin >> Q;

	for (maxn i = 0; i < n; i++) std::cin >> a[i];

	fr[0] = 1;
	for (maxn i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) st[i] = st[i - 1], fr[i] = fr[i - 1] + 1;
		else st[i] = i, fr[i] = 1;
	}
	en[n - 1] = n - 1;
	for (maxn i = n - 2; i >= 0; i--) {
		if (a[i] == a[i + 1]) en[i] = en[i + 1];
		else en[i] = i;
	}

	std::fill(tree, tree + (n * 4), 0);
}


maxn Build(const maxn node, const maxn L, const maxn R) {
	if (L > R) return 0;

	if (L == R) tree[node] = fr[L];
	else tree[node] = std::max(Build(cle(node), L, mid(L, R)), Build(cri(node), mid(L, R) + 1, R));

	return tree[node];
}


maxn GetMax(const maxn node, const maxn L, const maxn R, const maxn l, const maxn r) {
	if (L > R || L > r || R < l) return 0;

	if (L >= l && R <= r)  return tree[node];
	return std::max(GetMax(cle(node), L, mid(L, R), l, r), GetMax(cri(node), mid(L, R) + 1, R, l, r));
}


maxn Query(const maxn l, const maxn r) {
	maxn re = std::max(std::min(r, en[l]) - l + 1, r - std::max(l, st[r]) + 1);
	re = std::max(re, GetMax(0, 0, n - 1, en[l] + 1, st[r] - 1));
	return re;
}


void Process() {
	Build(0, 0, n - 1);

	while (Q--) {
		maxn l, r;
		std::cin >> l >> r;
		std::cout << Query(--l, --r) << '\n';
	}
}


int main() {
	freopen("11235.inp", "r", stdin);
	freopen("11235.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n) {
		Prepare();
		Process();
	}
}