#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning (disable:4996)

#define maxN 22
#define maxB 2097152
//#define maxM 1000000001

typedef long long maxn, maxb, maxm;

maxn n, occur[maxB], cnt_ad[maxN], res;
maxm M;
maxb ad[maxN];
std::vector <maxn> cnt;


void Prepare() {
	std::cin >> n >> M;
	for (maxn i = 0; i < n; i++) for (maxn j = 0; j < n; j++) {
		char c;
		std::cin >> c;
		if (c == '1') ad[i] |= ((maxb)1 << j), ++cnt_ad[i];
	}
}


void Process() {
	maxb b[2]; bool p = 0;
	b[p] = ad[0], occur[b[p]] = 1;;
	cnt.push_back(0); cnt.push_back(cnt_ad[0]);

	maxm i;
	for(i = 2; i <= M; i++) {
		p = !p, b[p] = 0;
		cnt.push_back(cnt.back());
		for (maxn i = 0; i < n; i++) {
			if ((b[!p] >> i) & 1) b[p] ^= ad[i], cnt.back() += cnt_ad[i];
			else cnt.back() += 2 * cnt_ad[i];
		}
		//std::cout << i << ' ' << b[p] << ' ' << b[!p] << ' ' << cnt.back() << '\n';
		if (occur[b[p]]) break; occur[b[p]] = i;
	}

	if (i >= M) res = cnt.back();
	else res = cnt[i - 1] + ((M - i + 1) / (i - occur[b[p]])) * (cnt[i] - cnt[occur[b[p]]]) + cnt[occur[b[p]] + ((M - i + 1) % (i - occur[b[p]])) - 1] - cnt[occur[b[p]] - 1];
	std::cout << res;
}


int main() {
	freopen("game.inp", "r", stdin);
	//freopen("game.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}