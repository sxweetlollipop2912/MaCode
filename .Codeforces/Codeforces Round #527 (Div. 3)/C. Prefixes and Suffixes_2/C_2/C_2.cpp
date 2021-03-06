//73b5b1dde99443cfa881c713d13f0e8e
#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

#define maxN 101
#define maxM 199

typedef std::string str;
typedef int maxn;

str a[maxM];
maxn m, n, P[maxM], id[maxM], S[maxM];


void Prepare() {
	std::cin >> n;
	m = 2 * n - 2;

	for (maxn i = 0; i < m; i++) {
		id[i] = i;
		std::cin >> a[i];
	}
}


bool cmp(maxn x, maxn y) {
	return a[x].size() < a[y].size();
}


maxn prevP(maxn x, maxn i) {
	str s = a[id[x]].substr(0, a[id[i]].size());

	if (P[i] != -1 && a[id[i]] == s) return i;
	if (P[i + 1] != -1 && a[id[i + 1]] == s) return i + 1;

	return -1;

}


maxn prevS(maxn x, maxn i) {
	str s = a[id[x]].substr(a[id[x]].size() - a[id[i]].size(), a[id[i]].size());

	if (S[i + 1] != -1 && a[id[i + 1]] == s) return i + 1;
	if (S[i] != -1 && a[id[i]] == s) return i;

	return -1;

}


void Process() {
	std::fill(S, S + m, -1);
	std::fill(P, P + m, -1);

	S[0] = P[0] = 0;
	S[1] = P[1] = 1;

	for (maxn i = 2; i < m; i += 2) {

		S[i] = prevS(i, i - 2);
		S[i + 1] = prevS(i + 1, i - 2);

		P[i] = prevP(i, i - 2);
		P[i + 1] = prevP(i + 1, i - 2);
	}
}


bool Output(maxn p, maxn s) {
	bool re[maxM];
	std::fill(re, re + m, 0);

	re[id[p]] = 1;


	while (p > 1 && s > 1) {
		p = P[p];
		s = S[s];
		if (s == p) return 0;
		re[id[p]] = 1;
	}

	for (maxn i = 0; i < m; i++)
		if (re[i]) std::cout << 'P';
		else std::cout << 'S';

	return 1;
}


int main() {
	Prepare();
	std::sort(id, id + m, cmp);

	Process();

	if (Output(m - 2, m - 1)) return 0;
	Output(m - 1, m - 2);
}