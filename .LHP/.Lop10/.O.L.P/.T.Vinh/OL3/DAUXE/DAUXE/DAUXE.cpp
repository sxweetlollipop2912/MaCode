#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxN 101
#define maxL 121
#define empty '.'
#define block 'X'

typedef int maxn, maxl;

maxn n, L;
std::vector <maxl> a;


void Add(maxl &x) {
	x = x - L + 1;

	while (x > 0) {
		a.push_back(std::min((maxl)L, x));
		//std::cout << std::min(L, x) << '\n';
		x -= (maxl)L;
	}

	x = 0;
}


void Prepare() {
	std::cin >> n >> L;

	char c;
	maxl x = 0;

	while (std::cin >> c) {
		if (c == empty) x++;
		if (c == block) Add(x);
	}
	Add(x);
}


void Process() {
	std::sort(a.begin(), a.end());

	maxl res = 0;
	for (maxl i = 0; i < std::max((maxl)0, (maxl)a.size() - (maxl)n); i++) 
		res += a[i];

	std::cout << res << '\n' << std::min((maxl)a.size(), (maxl)n);
}


int main() {
	freopen("dauxe.inp", "r", stdin);
	Prepare();
	Process();
}