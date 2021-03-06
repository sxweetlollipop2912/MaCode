#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 100
#define maxL 30
#define maxJ 2526

typedef int maxn, maxj;

std::string f[2][maxJ];
maxj s;
maxn n;


void Prepare() {
	//freopen("ESS.inp", "r", stdin);
	//freopen("ESS.out", "w", stdout);

	std::cin >> n;
}


std::string Add(std::string s1, std::string s2) {

	std::string re;

	int i = std::max(s1. size(), s2.size());
	while (s1.size() < i) s1 = "0" + s1;
	while (s2.size() < i) s2 = "0" + s2;
	int o = 0;

	for (i = i - 1; i >= 0; i--) {
		int x = (s1[i] - 48) + (s2[i] - 48) + o;

		o = x / 10;

		re = static_cast<char>((x % 10) + 48) + re;
	}

	if (o > 0) re = static_cast<char>(o + 48) + re;

	return re;
}


void Process() {

	s = n * (n + 1);
	if (s % 4 != 0) {
		std::cout << 0;
		return;
	}
	s = s / 4 - n;

	bool p = 1;

	for (maxn i = 0; i < n; i++) {
		p = 1 - p;
		f[p][0] = "1";

		for (maxj j = 1; j <= s; j++) {
			f[p][j] = f[1 - p][j];
			if (j >= i) f[p][j] = Add(f[p][j], f[1 - p][j - i]);
		}
	}

	std::cout << f[p][s];
}


int main() {
	Prepare();
	Process();
}