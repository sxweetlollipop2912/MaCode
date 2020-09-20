// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>

#pragma warning (disable:4996)

#define P 50
#define maxP 52
#define maxL 101

typedef long long maxa;
typedef int maxp;

maxa pascal[maxP][maxP];
maxp power;
int test;


void Pascal() {
	pascal[0][0] = 1;

	for (maxp i = 1; i <= P; i++) {
		pascal[i][0] = pascal[i][i] = 1;
		for (maxp j = 1; j < i; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	}
}


void Process() {
	char a[maxL], b[maxL];
	scanf(" (%[a-z]+%[a-z])^%d", a, b, &power);

	std::cout << "Case " << test << ": ";

	for (maxp i = 0; i <= power; i++) {
		if (i != 0) std::cout << "+";
		
		if (pascal[power][i] != 1) std::cout << pascal[power][i] << "*";

		maxp a_pow = power - i, b_pow = i;

		if (a_pow) {
			std::cout << a;
			if (a_pow > 1) std::cout << "^" << a_pow;
		}

		if (a_pow && b_pow) std::cout << "*";

		if (b_pow) {
			std::cout << b;
			if (b_pow > 1) std::cout << "^" << b_pow;
		}
	}

	std::cout << '\n';
}


int main() {
	//freopen("11955.inp", "r", stdin);
	//freopen("11955.out", "w", stdout);

	Pascal();

	int q;
	std::cin >> q;

	for (test = 1; test <= q; test++) 
		Process();
}