// 100/100
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define maxN 200001
#define X first
#define Y second

typedef long maxn;
typedef long long maxa, maxr;
typedef std::pair <maxa, maxa> co_t;

maxn n, N, cnt[maxN];
co_t p[maxN];
maxr res;
std::map <maxa, maxn> mx, my;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> p[i].X >> p[i].Y;

	std::sort(p, p + n);
	cnt[0] = 1; N = 1;
	for (maxn i = 1; i < n; i++) {
		if (p[i] == p[i - 1]) ++cnt[N - 1];
		else {
			cnt[N] = 1;
			p[N] = p[i];
			++N;
		}
	}
}


void Process() {
	for (maxn i = 0; i < N; i++) {
		res += ((maxr)mx[p[i].X] * (maxr)cnt[i]) + ((maxr)my[p[i].Y] * (maxr)cnt[i]) + ((maxr)cnt[i] * (maxr)(cnt[i] - (maxr)1) / (maxr)2);
		mx[p[i].X] += cnt[i];
		my[p[i].Y] += cnt[i];
		//std::cout << p[i].X << ' ' << p[i].Y << '\n';
		//std::cout << i << ' ' << res  << ' ' << cnt[i] << '\n';
	}
	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}