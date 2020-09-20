#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)

#define maxA (maxa)2750132
#define maxN 200001

typedef long long maxa;

bool snt[maxA];
std::vector <maxa> num;


void Era() {
	snt[0] = snt[1] = 1;
	for (maxa i = 2; i < maxA; i++) {
		if (snt[i]) continue;
		num.push_back(i);
		maxa x = i * i;
		while (x < maxA) {
			snt[x] = 1;
			x += i;
		}
	}
}


maxa Div(maxa x) {
	for (maxa i = 2; i <= x; i++)
		if (x % i == 0) return x / i;
	return 1;
}


int main() {
	freopen("tmp.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Era();

	std::cout << maxN << '\n';
	for (maxa i = 0; i < maxN; i++) {
		if (!snt[i]) std::cout << num[i - 1];
		else std::cout << Div(i);
		std::cout << ",";
	}
}