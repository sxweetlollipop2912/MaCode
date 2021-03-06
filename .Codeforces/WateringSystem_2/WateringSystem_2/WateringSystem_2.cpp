#include "pch.h"
#include <iostream>
#include <math.h>

int n, a, b, s[100000], t;

void input() {
	std::cin >> n >> a >> b;
	
	t = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		t += s[i];
	}
	//re -= floor(s[0] / (double)b * a);
}

void sort(int l, int r) {
	int i = l, j = r;
	
	do {
		int x = s[(l + r) / 2];
		while (s[i] > x) i++;
		while (s[j] < x) j--;
		if (i <= j) {
			x = s[i];
			s[i] = s[j];
			s[j] = x;
			i++; j--;
		}
	} while (i <= j);
	
	if (i < r) sort(i, r);
	if (l < j) sort(l, j);
}

double B() {
	return s[0] / (double)t * a;
}

int main() {
	input();
	sort(1, n - 1);
	
	int i = 0;
	while (B() < b) t -= s[++i];
	
	std::cout << i;
}