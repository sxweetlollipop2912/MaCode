#include "pch.h"
#include <iostream>
#include <math.h>

long long n;
int a[10] = { 0,0,1,1,2,1,3,1,4,3 };

void Prepare() {
	std::cin >> n;
}

bool check() {
	long bound = pow(n, 0.5);
	for (long i = 2; i <= bound; i++)
		if (n % i == 0) return 0;
	return 1;
}

int main() {
	Prepare();
	long long re;
	if (n < 10) re = a[n];
	else if (check()) re = 1;
	else re = (n) / 2;
	std::cout << re;
}