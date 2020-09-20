#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 32
#define maxK 28
#define num(c) ((c) - 'A')

typedef int maxn;

maxn m, n, ru[maxK], rd[maxK], cl[maxK], cr[maxK];
char a[maxN][maxN];
bool done[maxK];
std::vector <maxn> V, res;


void Prepare() {
	std::cin >> m >> n;
	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) std::cin >> a[i][j];

	for (maxn i = 1; i <= m; i++) for (maxn j = 1, k; j <= n; j++) {
		if (a[i][j] == '.') continue;
		for (k = 0; k < V.size(); k++) if (V[k] == num(a[i][j])) break;
		if (k == V.size()) V.push_back(num(a[i][j]));
	}
}


bool Check(const maxn id) {
	done[id] = 1;
	maxn it;

	for (it = cl[id]; it <= cr[id]; it++) {
		if (!done[num(a[ru[id]][it])] || !done[num(a[rd[id]][it])]) break;
	}
	if (it <= cr[id]) return 0;

	for (it = ru[id]; it <= rd[id]; it++) {
		if (!done[num(a[it][cl[id]])] || !done[num(a[it][cr[id]])]) break;
	}
	if (it <= rd[id]) return 0;

	done[id] = 0; return 1;
}


void Process() {
	for (maxn i = 1; i <= m; i++) for (maxn j = 1; j <= n; j++) {
		if (a[i][j] == '.') continue;
		maxn id = num(a[i][j]);

		ru[id] = !ru[id] ? i : std::min(ru[id], i);
		rd[id] = std::max(rd[id], i);

		cl[id] = !cl[id] ? j : std::min(cl[id], j);
		cr[id] = std::max(cr[id], j);
	}

	for (bool flag = 1; flag;) {
		flag = 0;
		for (maxn i = 0; i < V.size(); i++) {
			if (done[V[i]]) continue;
			done[V[i]] = Check(V[i]);
			if (done[V[i]]) res.push_back(V[i]);
			else flag = 1;
		}
	}
	for (maxn i = (maxn)res.size() - 1; i >= 0; i--) std::cout << (char)(res[i] + 'A');
}


int main() {
	//freopen("frameup.inp", "r", stdin);
	//freopen("frameup.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}