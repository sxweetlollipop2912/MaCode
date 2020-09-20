// AC UVa
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 1024002
#define maxS (4 * maxN)
#define bucc '1'
#define Qu 'S'
#define B0 'E'
#define B1 'F'
#define In 'I'
#define empty 'e'
#define cle(x) ((x) * 2 + 1)
#define cri(x) ((x) * 2 + 2)
#define mid(l, r) (((l) + (r)) / 2)

typedef long maxn;
typedef std::string str;

maxn tree[maxS], n;
char lazy[maxS];
bool a[maxS];
int CNTQ, cntq;


void Prepare() {
	maxn M = 0, T = 0;
	n = 0;

	std::cin >> M;
	while (M--) {
		str s;
		std::cin >> T >> s;

		while (T--) {
			for (maxn i = 0; i < s.size(); i++) {
				a[n++] = s[i] == bucc;
			}
		}
	}

	std::fill(tree, tree + (n * 4), 0);
	std::fill(lazy, lazy + (n * 4), empty);
}


maxn Build(maxn node, maxn L, maxn R) {
	if (L > R) return 0;

	if (L == R) tree[node] = a[L];
	else tree[node] = Build(cle(node), L, mid(L, R)) + Build(cri(node), mid(L, R) + 1, R);

	return tree[node];
}


char merge(char opt, char cur) {
	if (opt == empty) return cur;
	if (opt == B0 || opt == B1) return opt;
	if (cur == B0) return B1;
	if (cur == B1) return B0;
	if (cur == In) return empty;
	return In;
}


maxn change(maxn L, maxn R, maxn sum, char opt) {
	if (opt == B0) return 0;
	if (opt == B1) return (R - L + 1);
	if (opt == In) return (R - L + 1) - sum;
	return sum;
}


void Lazy(maxn node, maxn L, maxn R) {
	tree[node] = change(L, R, tree[node], lazy[node]);

	if (L != R) {
		lazy[cle(node)] = merge(lazy[node], lazy[cle(node)]);
		lazy[cri(node)] = merge(lazy[node], lazy[cri(node)]);
	}
	lazy[node] = empty;
}


maxn Update(maxn node, maxn L, maxn R, maxn l, maxn r, char opt) {
	if (L > R) return 0;

	Lazy(node, L, R);
	if (L > r || R < l) return tree[node];

	if (L >= l && R <= r) {
		lazy[node] = opt;
		Lazy(node, L, R);
	}
	else tree[node] = Update(cle(node), L, mid(L, R), l, r, opt) + Update(cri(node), mid(L, R) + 1, R, l, r, opt);

	return tree[node];
}


maxn GetSum(maxn node, maxn L, maxn R, maxn l, maxn r) {
	if (L > R) return 0;

	Lazy(node, L, R);
	if (L > r || R < l) return 0;

	if (L >= l && R <= r)  return tree[node];
	return GetSum(cle(node), L, mid(L, R), l, r) + GetSum(cri(node), mid(L, R) + 1, R, l, r);
}


void Query(const char opt, const maxn l, const maxn r) {
	if (opt != Qu)
		Update(0, 0, n - 1, l, r, opt);
	else std::cout << "Q" << ++cntq << ": " << GetSum(0, 0, n - 1, l, r) << '\n';
}


void Process() {
	std::cout << "Case " << CNTQ << ":\n";

	Build(0, 0, n - 1);

	cntq = 0;
	int q;
	std::cin >> q;

	while (q--) {
		char opt;
		maxn l, r;
		std::cin >> opt >> l >> r;
		Query(opt, l, r);
	}
}


int main() {
	//freopen("11402.inp", "r", stdin);
	//freopen("11402.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int Q = 0;
	std::cin >> Q;

	while (Q--) {
		++CNTQ;
		Prepare();
		Process();
	}
}