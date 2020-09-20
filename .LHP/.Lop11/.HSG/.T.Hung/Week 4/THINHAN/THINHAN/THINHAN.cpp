#include <iostream>
#include <algorithm>
#include <cstdio>

#define maxN 101
//#define maxE 51	

typedef int maxn, maxe;
typedef long long maxb;

maxn n;
maxe e;
bool parti[maxN];
maxb know[maxN], req;


void Prepare() {
	std::cin >> n >> e;
}


void Night(const maxe e) {
	if (parti[0]) {
		req |= (1 << (maxb)e);
		for (maxn i = 0; i < n; i++) if (parti[i]) know[i] |= (1 << (maxb)e);
	}
	else {
		maxb comb = 0;
		for (maxn i = 0; i < n; i++) if (parti[i]) comb |= know[i];
		for (maxn i = 0; i < n; i++) if (parti[i]) know[i] = comb;
	}
}


void Process() {
	for (maxe ie = 0; ie < e; ie++) {
		maxn k; std::cin >> k;
		std::fill(parti, parti + n, 0);
		while (k--) {
			maxn x; std::cin >> x, parti[x - 1] = 1;
		}
		Night(ie);
	}

	for (maxn i = 0; i < n; i++) if (know[i] == req) std::cout << i + 1 << '\n';
}


int main() {
	//freopen("thinhan.inp", "r", stdin);
	//freopen("thinhan.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}