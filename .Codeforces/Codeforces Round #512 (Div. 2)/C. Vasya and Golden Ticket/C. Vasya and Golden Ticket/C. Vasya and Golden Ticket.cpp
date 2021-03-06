// AC
#include "pch.h"
#include <iostream>

#define maxN 101

typedef long maxn;

maxn a[maxN], T[maxN], n;


void Prepare() {
	std::cin >> n;

	T[0] = 0;
	for (maxn i = 1; i <= n; i++) {
		char c;
		std::cin >> c;

		if (c == '0') {
			n--;
			i--;
			continue;
		}

		a[i] = c - '0';
		T[i] = a[i] + T[i - 1];
	}
}


maxn find(maxn x, maxn l) {
	maxn r = n;

	while (l != r) {
		maxn m = (l + r) / 2;
		if (T[m] < x) l = m + 1;
		else r = m;
	}

	if (T[l] == x) return l;
	return 0;
}


bool check(maxn pos) {
	maxn l = 0;

	do {
		l = find(T[l] + pos, l + 1);
	} while (l < n && l != 0);

	return l == n;
}


int main() {
	Prepare();
	
	maxn t = 0;
	bool re = n == 0;

	for (maxn i = n - 1; i >= 1 && !re; i--) {
		if (T[n] % T[i] == 0 && check(T[i])) re = 1;
	}

	if (re) std::cout << "YES";
	else std::cout << "NO";
}