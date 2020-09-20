// AC SPOJ
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 1001

typedef int maxn, maxm;

maxn nx, ny, res, mch[maxN];
maxm m;
bool done[maxN];
std::vector <maxn> ad[maxN];


void Prepare() {
	std::cin >> nx >> ny >> m;

	for (maxm i = 0; i < m; i++) {
		maxn x, y;
		std::cin >> x >> y, --x, --y;
		ad[x].push_back(y);
	}
}


bool DFS(const maxn x) {
	if (done[x]) return 0;
	done[x] = 1;
	for (maxm i = 0; i < ad[x].size(); i++) {
		maxn y = ad[x][i];
		if (mch[y] != -1 && !DFS(mch[y])) continue;
		mch[y] = x; return 1;
	}
	return 0;
}


void Process() {
	std::fill(mch, mch + ny, -1);
	for (maxn i = 0; i < nx; i++) {
		std::fill(done, done + nx, 0);
		res += DFS(i);
	}
	std::cout << res << '\n';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}