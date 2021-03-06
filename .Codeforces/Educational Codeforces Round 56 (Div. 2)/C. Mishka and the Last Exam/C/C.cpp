// AC
#include "pch.h"
#include <iostream>

#define maxN 200001
#define maxA 1000000000000000001

typedef long maxn;
typedef long long maxa;

maxa re[maxN], b, A = 0, B = maxA;
maxn n, len = 0;


void Process() {
	if (b - A > B) A = b - B;
	re[len] = A;
	B = re[n - len - 1] = b - A;
	len++;
}

int main() {
	std::cin >> n;
	for (maxn i = 0; i < n / 2; i++) {
		std::cin >> b;
		Process();
	}
	for (maxn i = 0; i < n; i++) std::cout << re[i] << ' ';
}