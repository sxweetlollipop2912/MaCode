#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#pragma warning (disable:4996)

#define maxN 1024002
#define maxS (maxN * 3 + 4)
#define bucc '1'
#define mid(l, r) (((l) + (r)) / 2)
#define cle(x) (maxn)((x) * 2 + 1)
#define cri(x) (maxn)((x) * 2 + 2)
#define B0 'E'
#define B1 'F'
#define In 'I'
#define Qu 'S'
#define empty 'e'

typedef long maxn;
typedef std::string str;

maxn n, cntq, CNTQ, seg[maxS];
char lazy[maxN];
bool sta[maxN];


void Prepare() {
	maxn M = 0, T = 0;
	n = 0;

	std::cin >> M;
	while (M--) {
		str s;
		std::cin >> T >> s;

		while (T--) {
			for (maxn i = 0; i < s.size(); i++) {
				sta[n++] = s[i] == bucc;
			}
		}
	}

	std::fill(seg, seg + (n * 3 + 3), 0);
	std::fill(lazy, lazy + (n * 3 + 3), empty);
}


maxn Build(const maxn L, const maxn R, const maxn ids) {
	if (L > R) return 0;
	if (L == R) seg[ids] = (maxn)sta[L];
	else seg[ids] = Build(L, mid(L, R), cle(ids)) + Build(mid(L, R) + 1, R, cri(ids));
	return seg[ids];
}


char merge(const char opt, const char cur) {
	if (opt == empty) return cur;
	if (opt == B0 || opt == B1) return opt;
	if (cur == B0) return B1;
	if (cur == B1) return B0;
	if (cur == In) return empty;
	return In;
}

maxn change(const maxn L, const maxn R, const maxn sum, const char opt) {
	if (opt == B0) return 0;
	if (opt == B1) return (R - L + 1);
	if (opt == In) return (R - L + 1) - sum;
	return sum;
}


void Lazy(const maxn ids, const maxn L, const maxn R) {
	seg[ids] = change(L, R, seg[ids], lazy[ids]);

	if (L != R) {
		lazy[cle(ids)] = merge(lazy[ids], lazy[cle(ids)]);
		lazy[cri(ids)] = merge(lazy[ids], lazy[cri(ids)]);
	}
	lazy[ids] = empty;
}


maxn Update(const maxn L, const maxn R, const maxn ids, const maxn l, const maxn r, const char opt) {
	if (L > R) return 0;

	Lazy(ids, L, R);
	if (L > r || R < l) return seg[ids];

	if (L >= l && R <= r) {
		lazy[ids] = opt;
		Lazy(ids, L, R);
		return seg[ids];
	}

	seg[ids] = Update(L, mid(L, R), cle(ids), l, r, opt) + Update(mid(L, R) + 1, R, cri(ids), l, r, opt);
	return seg[ids];
}


maxn GetSum(const maxn L, const maxn R, const maxn ids, const maxn l, const maxn r) {
	if (L > R) return 0;
	
	Lazy(ids, L, R);
	if (L > r || R < l) return 0;

	if (L >= l && R <= r) return seg[ids];
	return GetSum(L, mid(L, R), cle(ids), l, r) + GetSum(mid(L, R) + 1, R, cri(ids), l, r);
	
}


void Query(const char opt, const maxn l, const maxn r) {
	if (opt != Qu) 
		Update(0, n - 1, 0, l, r, opt);
	else std::cout << "Q" << ++cntq << ": " << GetSum(0, n - 1, 0, l, r) << '\n';
}


void Process() {
	std::cout << "Case " << CNTQ << ":\n";

	Build(0, n - 1, 0);

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
	freopen("11402.inp", "r", stdin);
	freopen("11402.out", "w", stdout);

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