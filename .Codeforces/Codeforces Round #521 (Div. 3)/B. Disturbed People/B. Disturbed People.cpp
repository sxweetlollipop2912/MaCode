// AC
//#include "pch.h"
#include <iostream>

int n;
bool a[100];
bool f[100];

void Prepare() {
	std::cin >> n >> a[0] >> a[1];
	for (int i = 2; i < n; i++) {
		std::cin >> a[i];
		if (a[i - 2] && a[i] && !a[i - 1]) f[i - 1] = 1;
	}
}

int main() {
	Prepare();
	int re = 0;
	for (int i = 1; i < n - 1; i++) {
		if (!a[i] || !f[i - 1] || !f[i + 1]) continue;
		a[i] = 0;
		f[i - 1] = 0;
		f[i + 1] = 0;
		re++;
	}
	for (int i = 0; i < n; i++) {
		if (!a[i] || !f[i + 1]) continue;
		a[i] = 0;
		f[i + 1] = 0;
		re++;
	}
	if (f[n - 2]) {
		a[n - 1] = 0;
		f[n - 2] = 0;
		re++;
	}
	std::cout << re;
}