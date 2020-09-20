#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>

#define maxN 1000001
//#define maxA 1000000001
//#define minA -maxA

typedef long maxn, maxa;

maxn n, k;
maxa a[maxN];
std::deque <maxn> de;


void Prepare() {
	std::cin >> n >> k;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		while (!de.empty() && a[de.front()] >= a[i]) de.pop_front();
		de.push_front(i);
		while (de.back() < i - k + 1) de.pop_back();
		if (i >= k - 1) std::cout << a[de.back()] << ' ';
	}
}


int main() {
	//freopen("mink.inp", "r", stdin);
	//freopen("mink.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}