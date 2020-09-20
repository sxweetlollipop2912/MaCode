#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 300001

typedef long maxn;

maxn n, a[maxN], b[maxN], pa;
std::priority_queue <maxn, std::vector <maxn>, std::greater <maxn> > pq1;
std::priority_queue <maxn, std::vector <maxn> > pq2;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	for (maxn i = 0; i < n; i++) std::cin >> b[i];
}


bool able1(const maxn pb) {
	while (pq1.top() != b[pb] && pa != n) pq1.push(a[pa++]);
	return pq1.top() == b[pb];
}


bool Process1() {
	pq1 = std::priority_queue <maxn, std::vector <maxn>, std::greater <maxn> >();
	pa = 0; pq1.push(maxN);

	for (maxn i = 0; i < n; i++) {
		if (!able1(i)) return 0;
		pq1.pop();
	}

	return 1;
}


bool able2(const maxn pb) {
	while (pq2.top() != b[pb] && pa != -1) pq2.push(a[pa--]);
	return pq2.top() == b[pb];
}


bool Process2() {
	pq2 = std::priority_queue <maxn, std::vector <maxn> >();
	pa = n - 1; pq2.push(-1);

	for (maxn i = n - 1; i >= 0; i--) {
		if (!able2(i)) return 0;
		pq2.pop();
	}

	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long q;
	std::cin >> q;

	while (q--) {
		Prepare();
		if (Process1() || Process2()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}