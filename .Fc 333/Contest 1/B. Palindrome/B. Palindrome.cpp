#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

#define maxN 100001
#define maxM 200001
#define tag(u, v) (((v) < (u)) ? n + (v) : (v))
#define id(x) ((x) % n) 

typedef long maxn, maxm;

maxn n;
std::vector <maxn> ad[maxN];


void Prepare() {
	maxm m = 0;
	std::cin >> n >> m;
	
	while (m--) {
		maxn u, v;
		std::cin >> u >> v;
		--u, --v;
		ad[u].push_back(tag(u, v));
		ad[v].push_back(tag(v, u));
	}

	for (maxn i = 0; i < n; i++) 
		std::sort(ad[i].begin(), ad[i].end());
}


bool Same(const maxn x, const maxn y) {
	if (ad[x].size() != ad[y].size()) return 0;

	for (maxn i = 0; i < ad[x].size(); i++) 
		if (ad[x][i] - x != ad[y][i] - y) return 0;

	return 1;
}


bool Rotate(const maxn k) {
	for (maxn i = 0; i < n; i++) 
		if (!Same(i, id(i + k))) return 0;
	
	return 1;
}


bool Process() {
	if (Rotate(1)) return 1;

	maxn k = std::sqrt(n);
	while (--k) {
		if (n % (k + 1) != 0) continue;
		if (Rotate(k + 1) || Rotate(n / (k + 1))) return 1;
	}

	std::cout << "No";
	return 0;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	if (Process()) std::cout << "Yes";
}