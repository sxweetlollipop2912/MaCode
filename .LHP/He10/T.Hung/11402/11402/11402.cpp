// uDebug
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 1024001
#define bucc '1'

typedef long maxn;
typedef std::string str;

maxn n, bit[maxN], cntq, CNTQ;
bool sta[maxN];


void Update(maxn id, const maxn x) {
	while (id <= n) {
		bit[id] += x;
		id += (id & (-id));
	}
}


maxn Sum(maxn id) {
	maxn re = 0;
	while (id > 0) {
		re += bit[id];
		id -= (id & (-id));
	}
	return re;
}


void Prepare() {
	std::fill(bit, bit + maxN, 0);
	maxn M, T;
	n = 0;

	std::cin >> M;
	while (M--) {
		str s;
		std::cin >> T >> s;

		while (T--) {
			for (maxn i = 0; i < s.size(); i++) {
				sta[++n] = s[i] == bucc;
			}
		}
	}
}


void Query(const char opt, const maxn l, const maxn r) {
	if (opt == 'F') {
		for (maxn i = l; i <= r; i++) {
			if (!sta[i]) Update(i, 1);
			sta[i] = 1;
		}
	}
	else if (opt == 'E') {
		for (maxn i = l; i <= r; i++) {
			if (sta[i]) Update(i, -1);
			sta[i] = 0;
		}
	}
	else if (opt == 'I') {
		for (maxn i = l; i <= r; i++) {
			if (sta[i]) Update(i, -1);
			else Update(i, 1);
			sta[i] = !sta[i];
		}
	}
	else std::cout << "Q" << ++cntq << ": " << Sum(r) - Sum(l) << '\n';
}


void Process() {
	std::cout << "Case " << CNTQ << ":\n";

	for (maxn i = 0; i < n; i++)
		if (sta[i]) Update(i, 1);

	cntq = 0;
	int q;
	std::cin >> q;

	while (q--) {
		char opt;
		maxn l, r;
		std::cin >> opt >> l >> r;
		Query(opt, ++l, ++r);
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int Q;
	std::cin >> Q;

	while (Q--) {
		++CNTQ;
		Prepare();
		Process();
	}
}