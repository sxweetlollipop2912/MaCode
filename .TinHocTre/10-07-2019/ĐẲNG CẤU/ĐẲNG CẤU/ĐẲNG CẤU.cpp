#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 200001
#define N (n * m)
#define M (n * (m - 1) + m * (n - 1))
typedef long maxn;

maxn n, m, deg[maxN], cnt[maxN];


void Prepare() {
	std::cin >> n >> m;

	for (maxn i = 0; i < M; i++) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		++deg[u], ++deg[v];
	}
}


bool Process() {
	for (maxn i = 0; i < N; i++)
		++cnt[deg[i]];

	if (cnt[1] == 2 && cnt[1] + cnt[2] == N) {
		std::cout << "Yes";
		return 1;
	}
	if (cnt[2] + cnt[3] + cnt[4] != N)
		return 0;
	if (cnt[2] != 4 || cnt[3] % 2 != 0)
		return 0;
	if (((cnt[3] / 2) * (cnt[3] / 2)) - (4 * cnt[4]) < 0)
		return 0;

	std::cout << "Yes";
	return 1;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (!Process()) std::cout << "No";
}