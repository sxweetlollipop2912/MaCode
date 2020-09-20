// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 100003
#define maxS (4 * maxN)
#define minL 1
#define maxR 100001
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)
#define mn first
#define mx second
#define setLazy(node, h) tree[node] = info(h, h), lazy[node] = 1

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> info;

maxn n;
info tree[maxS];
bool lazy[maxS];
maxa res;


void Prepare() {
	std::cin >> n;

	std::fill(tree, tree + (maxR * 4), info(0, 0));
	std::fill(lazy, lazy + (maxR * 4), 0);
}


void Lazy(maxn node, maxn L, maxn R) {
	if (L == R || !lazy[node]) return;

	setLazy(cle(node), tree[node].mn);
	setLazy(cri(node), tree[node].mn);

	lazy[node] = 0;
}


maxa GetCover(maxn node, maxa L, maxa R, maxa l, maxa r, maxa h) {
	if (L > R || L > r || R < l) return 0;
	Lazy(node, L, R);

	if (L >= l && R <= r) {
		if (tree[node].mn > h) 
			return 0;
		if (tree[node].mx <= h) {
			setLazy(node, h);
			return R - L + 1;
		}
	}

	maxa cost = GetCover(cle(node), L, mid(L, R), l, r, h) + GetCover(cri(node), mid(L, R) + 1, R, l, r, h);
	tree[node].mx = std::max(tree[cle(node)].mx, tree[cri(node)].mx);
	tree[node].mn = std::min(tree[cle(node)].mn, tree[cri(node)].mn);

	return cost;
}


void Query(const maxa l, const maxa r, const maxa h) {
	res += GetCover(0, minL, maxR, l, r - 1, h);
}


void Process() {
	res = 0;

	while (n--) {
		maxa l, r, h;
		std::cin >> l >> r >> h;
		Query(l, r, h);
	}
	std::cout << res << '\n';
}


int main() {
	//freopen("1232.inp", "r", stdin);
	//freopen("1232.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int Q = 0;
	std::cin >> Q;

	while (Q--) {
		Prepare();
		Process();
	}
}