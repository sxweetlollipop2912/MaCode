#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

#define maxN 100002
#define maxA 1000000001

typedef long maxn;
typedef long long maxa;

maxn n;
maxa C[maxN], V[maxN], M, res;
std::deque<maxn> dq;


void Prepare() {
	std::cin >> n >> M;
	for (maxn i = 0; i < n; i++) std::cin >> V[i] >> C[i];
}


void Process() {
	maxa sum = 0;
	res = maxA;
	for (maxn l = 0, r = 0; r < n; r++) {
		sum += V[r];

		while (!dq.empty() && C[dq.back()] <= C[r]) dq.pop_back();
		dq.push_back(r);

		if (sum >= M) 
			for (; l <= r; l++) {
				res = std::min(res, C[dq.front()]);
				if (sum - V[l] < M) break;

				if (dq.front() == l) dq.pop_front();
				sum -= V[l];
			}
	}
	std::cout << res;
}


int main() {
	freopen("meal.inp", "r", stdin);
	freopen("meal.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}