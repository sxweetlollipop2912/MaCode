#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 100003

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxn> p_t;

maxn n, N, st, en;
maxa a[maxN], ABS, res;
std::priority_queue <p_t, std::vector <p_t>> pq;


void Prepare() {
	std::cin >> n >> a[1];
	N = n, st = 1;
	for (maxn i = 2, idx = 2; i <= n; i++) {
		std::cin >> a[idx];
		if (a[idx] != a[idx - 1]) idx++;
		else --N;
	}
	en = N;

	if (a[1] == -1) {
		st = 0;
		for (maxn i = 2; i <= N; i++) if (a[i] != -1) {
			a[0] = a[i];
			break;
		}
	}
	if (a[N] == -1) {
		en = N + 1;
		for (maxn i = N; i >= 1; i--) if (a[i] != -1) {
			a[N + 1] = a[i];
			break;
		}
	}
}


void Process() {
	for (maxn i = st + 1; i < en; i++) if (a[i] == -1) {
		pq.push(p_t(abs(a[i - 1] - a[i + 1]), i));
	}

	if (pq.empty()) {
		std::cout << "0 0\n";
		return;
	}
	maxn idx = pq.top().second; pq.pop();
	res = (a[idx - 1] + a[idx + 1]) / 2, ABS = std::max(abs(a[idx - 1] - res), abs(a[idx + 1] - res));

	while (!pq.empty()) {
		idx = pq.top().second; pq.pop();
		maxa m = (a[idx - 1] + a[idx + 1]) / 2, x = std::max(abs(a[idx - 1] - m), abs(a[idx + 1] - m));
		if (m < res) m += (ABS - x);
		else m -= std::max((maxa)0, (ABS - x));
		ABS += std::max(abs(res - ((res + m) / 2)), abs(m - ((res + m) / 2))), res = (res + m) / 2;
	}

	for (maxn i = 1; i < N; i++) if (a[i] != -1 && a[i + 1] != -1) ABS = std::max(ABS, (maxa)abs(a[i] - a[i + 1]));

	if (N == 1 && a[1] == -1) std::cout << "0 0\n";
	else std::cout << ABS << ' ' << res << '\n';
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