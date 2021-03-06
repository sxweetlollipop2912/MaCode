#include "pch.h"
#include <iostream>
#include <string>

#define maxN 101
#define maxM 199

typedef int maxn;

std::string a[maxM];
std::string key[3], re;
maxn n, m;
bool r[maxM];

void Prepare() {
	bool p = 0;
	std::cin >> n;
	m = 2 * n - 2;
	for (maxn i = 0; i < m; i++) {
		std::cin >> a[i];
		if (a[i].size() == n - 1) key[p = 1 - p] = a[i];
	}
}


bool check() {
	bool pre[maxN];
	std::fill(pre, pre + n, 0);

	bool kt = 1;
	for (maxn i = 0; i < m && kt; i++) {
		kt = 0;
		maxn len = a[i].size();
		if (!pre[len - 1] && a[i] == re.substr(0, len)) {
			kt = 1;
			pre[len - 1] = 1;
			r[i] = 1;
		}
		else if (a[i] == re.substr(n - len, len)) {
			kt = 1;
			r[i] = 0;
		}
	}
	return kt;
}


void Output() {
	for (maxn i = 0; i < m; i++) {
		if (r[i]) std::cout << 'P';
		else std::cout << 'S';
	}
}


int main() {
	Prepare();
	re = key[0] + key[1][n - 2];
	if (check()) {
		Output();
		return 0;
	}
	re = key[1] + key[0][n - 2];
	if (check()) Output();
}