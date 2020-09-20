#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 5002
#define minR -5000000000001
#define del -2

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxn, maxa> pq_t;

maxn n, K, N;
maxa a[maxN], res;
int imp[maxN];


void Prepare() {
	std::cin >> n >> K >> a[0], res = a[0];
	N = 1;
	for (maxn i = 1; i < n; i++) {
		maxa x; std::cin >> x, res += x;
		if (x * a[N - 1] >= 0) a[N - 1] += x;
		else ++N, a[N - 1] = x;
	}
}


class cmp {
public:
	bool operator() (const maxn x, const maxn y) {
		return a[x] > a[y];
	}
};
std::priority_queue <maxn, std::vector <maxn>, cmp> pqi, pqd;


void Process() {
	maxn cnt = 1; maxa re_1 = res;
	for (maxn i = 1; i < N - 1; i++) if (a[i] < 0) pqi.push(i);
	std::fill(imp, imp + N, 1);

	while (!pqi.empty() && cnt < K) {
		maxn idx = pqi.top(); pqi.pop();
		re_1 -= a[idx], imp[idx] = del, ++cnt;
		if (idx != 0     && (--imp[idx - 1]) == -1) pqd.push(idx - 1);
		if (idx != N - 1 && (--imp[idx + 1]) == -1) pqd.push(idx + 1);

		while (!pqi.empty() && imp[pqi.top()] != 1) pqi.pop();
	}

	while (!pqd.empty()) {
		maxn idx = pqd.top(); pqd.pop();
		if (!pqi.empty()) {
			maxn idx1 = pqi.top(); pqi.pop();
			res = std::max(res, re_1 - a[idx] + a[idx1]);
		}
		else res = std::max(res, re_1 - a[idx]);

	}

	std::cout << res;
}


int main() {
	Prepare();
	Process();
}