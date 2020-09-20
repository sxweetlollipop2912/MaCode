#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define maxN 100001

typedef std::string str;
typedef long maxn;

maxn n;
str a;


void Prepare() {
	std::cin >> n >> a;
}


void Process() {
	maxn i, j;
	for (i = 0;     i < n  && a[i] == '0'; i++);
	for (j = n - 1; j >= 0 && a[j] == '1'; j--);

	std::cout << a.substr(0, i);
	if (i <= j) std::cout << "0";
	std::cout << a.substr(j + 1, n - j - 1) << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long t; std::cin >> t;
	while (t--) {
		Prepare();
		Process();
	}
}