#include "pch.h"
#include <iostream>
#include <string>

#define maxn 200
#define max 100
#define mod 100

std::string s1, s2;
int a[3][maxn];

void Prepare() {
	std::cin >> s1 >> s2;
}

void String2Arr() {
	int d = s1.size();
	for (int i = 0; i < (s1.size() + 1) / 2; i++) {
		d--;
		a[0][i] += s1[d] - 48;
		d--;
		if (d >= 0) a[0][i] += (s1[d] - 48) * 10;
	}

	d = s2.size();
	for (int j = 0; j < (s2.size() + 1) / 2; j++) {
		d--;
		a[1][j] += s2[d] - 48;
		d--;
		if (d >= 0) a[1][j] += (s2[d] - 48) * 10;
	}
}


void Multi(int re, int ii, int jj) {
	for (int i = 0; i < max; i++)
		for (int j = 0; j < max; j++) {
			a[re][i + j] += a[ii][i] * a[jj][j];
			a[re][i + j + 1] += a[re][i + j] / mod;
			a[re][i + j] %= mod;
		}
	for (int i = max; i < maxn - 1; i++) {
		a[re][i + 1] += a[re][i] / mod;
		a[re][i] %= mod;
	}
}


int main() {
	Prepare();
	String2Arr();
	Multi(2, 0, 1);
	
	int ii;
	for (ii = max - 1; ii >= 0; ii--) if (a[2][ii] != 0) break;
	std::cout << a[2][ii];
	for (int i = ii - 1; i >= 0; i--) {
		if (a[2][i] < 10) std::cout << 0; // 0<num>
		std::cout << a[2][i];
	}
}