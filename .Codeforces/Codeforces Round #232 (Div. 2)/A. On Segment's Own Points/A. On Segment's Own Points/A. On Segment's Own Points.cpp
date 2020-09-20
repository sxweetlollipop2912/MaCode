#include <iostream>
#include <algorithm>

#define maxN 101

typedef int maxn, maxa;

maxn n, ps[maxN];
maxa L, R, res;


void Prepare() {
	std::cin >> n >> L >> R;
	for (maxn i = 1; i < n; i++) {
		maxa l, r;
		std::cin >> l >> r;
		++ps[l], --ps[r];
	}
}


void Process() {
	for (maxa i = 1; i < R; i++) 
		ps[i] += ps[i - 1];

	res = 0;
	for (maxa i = L; i < R; i++) 
		res += !ps[i];

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}