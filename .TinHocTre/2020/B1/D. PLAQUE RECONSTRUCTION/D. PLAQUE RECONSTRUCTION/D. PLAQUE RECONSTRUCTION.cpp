#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long maxn;
typedef long long maxa;

maxa S, W;


void Prepare() {
	std::cin >> W;
	maxn n;
	std::cin >> n;
	for (maxn i = 0; i < n; i++) {
		maxa x, y; std::cin >> x >> y;
		S += x * y;
	}
}


void Process() {
	std::cout << S / W;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	Prepare();
	Process();
}