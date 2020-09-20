#include <iostream>
#include <algorithm>

#define maxN 101

typedef long long maxn;

maxn r, c, res;


void Prepare() {
	std::cin >> r >> c;
}


void Process() {
	res = 0;
	for (maxn w = 2; w <= r; w++) {
		for (maxn h = 2; h <= c; h++) {
			res += ((w - 1) * (h - 1)) * 4 * ((r - w + 1) * (c - h + 1));
		}
	}
	std::cout << res;
}


int main() {
	Prepare();
	Process();
}