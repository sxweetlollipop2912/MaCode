#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 602
#define maxD 10002
#define maxT 10002
#define maxR 60000001
#define ti first
#define id second
#define N v.size()
#define in(l, r, L, R)  ((l) >= (L) && (r) <= (R))

typedef int maxn, maxt;
typedef long maxd;

maxn n;
maxt st[maxN], en[maxN];
maxd d[maxN], f[maxN][maxN];
bool done[maxN][maxN], t[maxT];
std::vector <maxt> v;


void Prepare() {
	std::cin >> n;

	for (maxn i = 1; i <= n; i++) {
		std::cin >> st[i] >> en[i] >> d[i];
		if (!t[st[i]]) v.push_back(st[i]);
		if (!t[en[i]]) v.push_back(en[i]);
		t[st[i]] = t[en[i]] = 1;
	}

	std::sort(v.begin(), v.end());
}


maxd DP(const maxn L, const maxn R) {
	if (L > R) return 0; if (done[L][R]) return f[L][R];
	done[L][R] = 1;

	maxn l = 0, r = 0, mx = -1;
	for (maxn i = 1; i <= n; i++) if (in(st[i], en[i], v[L], v[R]) && mx < d[i]) mx = d[i], l = st[i], r = en[i];

	if (mx == -1) return (f[L][R] = 0);
	f[L][R] = maxR;
	for (maxn i = L; i <= R; i++) if (v[i] >= l && v[i] <= r) f[L][R] = std::min(f[L][R], DP(L, i - 1) + DP(i + 1, R) + mx);

	return f[L][R];
}


void Process() {
	std::cout << DP(0, N - 1);
}


int main() {
	//freopen("bantau.inp", "r", stdin);
	//freopen("bantau.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}