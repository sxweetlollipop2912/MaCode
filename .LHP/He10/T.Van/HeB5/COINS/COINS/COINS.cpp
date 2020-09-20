#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 50002

typedef long maxn;

maxn n, S, a[maxN], idt[maxN], id[maxN];
std::vector <maxn> T;


bool cmp(const maxn &x, const maxn &y) {
	return a[x] < a[y];
}


void Prepare() {
	std::cin >> n >> S;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> a[i];
		id[i] = i;
	}

	std::sort(id, id + n + 1, cmp);
	T.push_back(0);
}


void Dig(const maxn x) {
	maxn len = T.size();
	for (maxn i = 0; i < len; i++) {
		maxn t = a[x] + T[i];
		if (t != S && (S - t < a[x] || idt[t])) continue;
		
		idt[t] = x;
		T.push_back(t);
	}
}


void Trace(maxn t) {
	while (t) {
		std::cout << idt[t] << ' ';
		t -= a[idt[t]];
	}
}


void Process() {
	for (maxn i = 1; i <= n && !idt[S]; i++) {
		Dig(id[i]);
		//std::cout << id[i] << '\n';
	}
	if (!idt[S]) std::cout << -1;
	else Trace(S);
}


int main() {
	//freopen("coins.inp", "r", stdin);
	//freopen("coins.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}