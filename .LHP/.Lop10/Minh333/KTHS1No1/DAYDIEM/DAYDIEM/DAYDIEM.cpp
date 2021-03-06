#include "pch.h"
#include <iostream>

long n;
long long x[1000000], y[1000000], stt[1000000];

void input() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
		stt[i] = i;
	}
}

bool comp(long i, long j) {
	return (x[stt[i]] > x[stt[j]]) || ((x[stt[i]] == x[stt[j]]) && (y[stt[i]] < y[stt[j]]));
}

void sort(long l, long r) {
	long i = l, j = r;
	do {
		long a = (l + r) / 2;
		while (comp(a, i)) i++;
		while (comp(j, a)) j--;
		if (i <= j) {
			a = stt[i];
			stt[i] = stt[j];
			stt[j] = a;
			i++; j--;
		}
	} while (i <= j);
	if (i < r) sort(i, r);
	if (l < j) sort(l, j);
}


int main() {
	input();
	sort(0, n-1);
	for (int i = 0; i < n; i++)  std::cout << stt[i] + 1 << "\n";
}