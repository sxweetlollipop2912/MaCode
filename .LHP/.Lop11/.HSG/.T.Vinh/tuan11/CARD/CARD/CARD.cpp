#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 100002
#define n (N / 2)

typedef long maxn;

maxn N, com[maxN], res;
bool tak[maxN];


void Prepare() {
	std::cin >> N;
	for (maxn i = 0; i < N; i++) std::cin >> com[i], tak[com[i]] = 1;

	std::sort(com, com + n, std::greater<maxn>());
	std::sort(com + n, com + N);
}


void Process() {
	for (maxn i = 0, num = 2 * N; i < n; i++) {
		while (num > 0 && tak[num]) --num;
		if (num > com[i]) ++res, tak[num] = 1, --num;
	}
	for (maxn i = n, num = 1; i < N; i++) {
		while (num <= N && tak[num]) ++num;
		if (num < com[i]) ++res, tak[num] = 1, ++num;
	}
	std::cout << res;
}


int main() {
	//freopen("card.inp", "r", stdin);
	//freopen("card.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}