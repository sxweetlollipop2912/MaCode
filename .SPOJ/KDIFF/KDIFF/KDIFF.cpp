// AC
#include <iostream>
#include <algorithm>
#include <deque>

#define maxN 300002

typedef long maxn, maxa;

maxn n, K, f[maxN], res;
maxa a[maxN];
std::deque <maxn> mn, mx;


void Prepare() {
	std::cin >> n >> K;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
	res = 1;
	maxn pos = 0;

	for (maxn i = 1; i <= n; i++) {
		maxn mxpos = pos, mnpos = pos;

		while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
		mn.push_back(i);
		while (a[i] - a[mn.front()] > K) {
			mnpos = mn.front();
			mn.pop_front();
		}

		while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
		mx.push_back(i);
		while (a[mx.front()] - a[i] > K) {
			mxpos = mx.front();
			mx.pop_front();
		}

		pos = std::max(mnpos, mxpos);

		f[i] = std::max(i - pos, f[i - 1]);
		res = std::max(res, i - pos + f[pos]);
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}