#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 27
#define maxV 102
#define maxW 102
#define maxL 102

typedef long maxn, maxa;

struct info {
	maxa v, w, l;
};
info newInfo(const maxn &V, const maxn &W, const maxn &L) {
	info re;
	re.v = V, re.w = W, re.l = L;
	return re;
}

maxn n, V, W, L, cnt[maxV][maxW][maxL];
info a[maxN];
std::vector <info> T;


void Prepare() {
	std::cin >> n >> V >> W >> L;

	for (maxn i = 1; i <= n; i++) {
		maxa v, w, l;
		std::cin >> v >> w >> l;
		a[i] = newInfo(v, w, l);
	}

	T.push_back(newInfo(0, 0, 0));
}


info add(info re, const info &x) {
	re.w += x.w, re.l += x.l, re.v += x.v;
	return re;
}

bool check(const info &x) {
	return x.v <= V && x.w <= W && x.l <= L;
}


void Take(const maxn x) {
	maxn len = T.size();
	for (maxn i = 0; i < len; i++) {
		info t = T[i];
		maxa time = 0;

		while (t = add(a[x], t), check(t)) {
			++time;

			if (!cnt[t.v][t.w][t.l]) {
				T.push_back(t);
				cnt[t.v][t.w][t.l] = cnt[T[i].v][T[i].w][T[i].l] + time;
			}
			else cnt[t.v][t.w][t.l] = std::min(cnt[t.v][t.w][t.l], cnt[T[i].v][T[i].w][T[i].l] + time);
		}
	}
}


void Process() {
	for (maxn i = 1; i <= n; i++) Take(i);
	std::cout << cnt[V][W][L];
}


int main() {
	freopen("min3.inp", "r", stdin);
	freopen("min3.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}