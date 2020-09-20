// AC SPOJ
#include <iostream>
#include <algorithm>
#include <deque>

#define maxN 1000001
#define maxA 10001

typedef long maxn;
typedef int maxa;

maxn L, n, res;
maxa a[maxN], D;
std::deque <maxn> mx, mn;


void Prepare() {
	std::cin >> n >> L >> D, ++L;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	res = 0;
	for (maxn r = 0, l = 0; r < n; r++) {
		while (!mx.empty() && a[mx.back()] <= a[r]) mx.pop_back();
		mx.push_back(r);
		while (!mn.empty() && a[mn.back()] >= a[r]) mn.pop_back();
		mn.push_back(r);

		while (a[mx.front()] - a[mn.front()] > D) {
			++l;
			while (mx.front() < l) mx.pop_front();
			while (mn.front() < l) mn.pop_front();
		}

		res += std::max((maxn)0, r - l + 1 - L + 1);
	}
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}