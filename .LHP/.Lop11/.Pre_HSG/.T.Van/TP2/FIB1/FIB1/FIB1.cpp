#include <iostream>
#include <algorithm>
#include <fstream>

#define maxN 51

typedef int maxn;
typedef long long maxa;

maxn n;
maxa f[maxN], k;


void Prepare() {
	std::cin >> n >> k;
}


void Process() {
	maxn i = n;

	while (k != 1) {
		if (k <= f[i - 2]) i -= 2;
		else k -= f[i - 2], i-= 1;
	}

	if (i % 2 == 0) std::cout << "a\n";
	else std::cout << "b\n";
}


int main() {
	//freopen("fib1","r",stdin);
	//freopen("fib1","w",stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	f[0] = f[1] = 1;
	for (maxn i = 2; i < maxN; i++) f[i] = f[i - 1] + f[i - 2];

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}
