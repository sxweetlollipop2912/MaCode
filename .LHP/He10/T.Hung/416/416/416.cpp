// AC uDebug
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#pragma warning(disable:4996)

#define maxN 11
#define maxA 11
#define LEN 7
#define light 'Y'
#define dark 'N'
#define broken 'B'
#define fine 'F'

typedef int maxn, maxl, maxa;
typedef std::string str;

str ideal[maxA] = { "YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY","YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY" };
maxn n, tim[maxA];
str sta[maxA], scur;
bool pass;


void Prepare() {
	str sample = "FFFFFFF";
	std::fill(sta, sta + maxA, sample);
	std::fill(tim, tim + maxA, n);
}


bool isDigit(const str &scur, const str &sta, const str &ideal, str &stac) {
	for (maxl i = 0; i < LEN; i++) {
		if ((sta[i] == broken && scur[i] == light) || (scur[i] == light && ideal[i] == dark)) return 0;
		if (scur[i] != ideal[i]) stac[i] = broken;
	}
	return 1;
}


bool Process() {
	pass = 1;

	while (n--) {
		std::cin >> scur;
		if (!pass) continue;

		pass = 0;
		for (maxa num = 1; num < maxA; num++) {
			if (tim[num] != n + 1 || !isDigit(scur, sta[num], ideal[num - 1], sta[num - 1])) continue;
			tim[num - 1] = n;
			pass = 1;
		}
	}

	return pass;
}


int main() {
	//freopen("416.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n && n != 0) {
		Prepare();
		if (Process()) std::cout << "MATCH\n";
		else std::cout << "MISMATCH\n";
	}
}