#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>


#define maxN 100001    // 10^3
#define maxA 1001    // 10^5

typedef int maxn;
typedef long maxa;

maxn mi, re, m, n;
maxn a[maxN], f[maxN];


/*void Prepare1() {
	maxn l[maxA];

	std::fill(l, l + maxA + 1, 0);

	std::string s1, s2;
	std::getline(std::cin, s1);
	std::getline(std::cin, s2);

	maxn cnt = 1;
	m = s1.size();
	for (maxn i = 0; i < m; i++) {
		char x = s1[i];
		if (l[x] == 0) l[x] = cnt++;
		f[i] = l[x];
	}

	maxn i = -1;
	n = s2.size();
	for (maxn j = 0; j < s2.size(); j++) {
		char x = s2[j];
		if (l[x] == 0) n--;
		else a[++i] = l[x];
	}

	mi = std::min(m, n);
}*/


void Prepare1() {
	maxn l[maxA];

	std::cin >> m >> n;

	std::fill(l, l + maxA, 0);

	maxn cnt = 1;
	for (maxn i = 0; i < m; i++) {
		maxa x;
		std::cin >> x;
		if (l[x] == 0) l[x] = cnt++;
		f[i] = l[x];
	}

	maxn n1 = n;
	for (maxn i = 0; i < n1; i++) {
		maxa x;
		std::cin >> x;
		if (l[x] == 0) n--;
		else a[i] = l[x];
	}

	mi = std::min(m, n);
}


std::vector <maxn> v[maxN];


void Prepare2() {
	for (maxn i = 0; i < m; i++)
		v[f[i]].push_back(i + 1);
}


maxn find(maxn a, maxn l) {
	//std::cout << a << '\n';
	maxn r = mi;

	while (l < r) {
		maxn m = (l + r) / 2;
		if (f[m] < a) l = m + 1;
		else r = m;
	}

	if (f[l] < a) return l;
	f[l] = a;
	re = std::max(re, l);
	return l;
}


int main() {
	//freopen("MANGCON.inp", "r", stdin);
	//freopen("MANGCON.out", "w", stdout);
	std::ios_base::sync_with_stdio(false);

	Prepare1();
	Prepare2();

	std::fill(f, f + mi + 2, maxN + 1);
	f[1] = a[0];

	for (maxn i = 0; i < n; i++) {
		maxn l = 1;
		for (maxn j = 0; j < v[a[i]].size(); j++)
			l = find(v[a[i]][j], l);
	}
	//for (maxn i = 1; i <= mi; i++) std::cout << f[i] << ' ';
	std::cout << re;
}