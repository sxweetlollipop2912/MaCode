// AC
#include "pch.h"
#include <iostream>

#define maxn 200000

char a[maxn];
int n, pos;

void Prepare() {
	std::cin >> n >> a[0];
	pos = -1;
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		if (pos == -1 && a[i] < a[i - 1]) pos = i - 1;
	}
	if (pos == -1) pos = n - 1;
}

int main() {
	Prepare();
	for (int i = 0; i < pos; i++) std::cout << a[i];
	for (int i = pos + 1; i < n; i++) std::cout << a[i];
}