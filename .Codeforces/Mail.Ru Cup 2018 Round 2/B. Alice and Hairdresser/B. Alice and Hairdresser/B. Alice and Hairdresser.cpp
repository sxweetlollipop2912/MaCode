// AC
#include "pch.h"
#include <iostream>

#define maxn 100001

unsigned long a[maxn], l, d;
unsigned int m, n, time, p;
bool f[maxn];


void Prepare() {
	std::cin >> n >> m >> l;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] <= l) continue;
		f[i] = 1;
		if (i == 0 || !f[i - 1]) time++;
	}
}

void T() {

	a[p] += d;
	if (f[p] || a[p] <= l) return;

	f[p] = 1;
	
	bool left = p > 0 ? f[p - 1] : 0,
	right = p < n - 1 ? f[p + 1] : 0;
	
	time += !(left | right) - (left & right);
}

void Input() {
	std::cin >> p >> d;
	p--;
	T();
}

int main() {
	Prepare();
	for (int i = 0; i < m; i++) {
		bool c;
		std::cin >> c;
		if (!c) std::cout << time << '\n';
		else Input();
	}
}