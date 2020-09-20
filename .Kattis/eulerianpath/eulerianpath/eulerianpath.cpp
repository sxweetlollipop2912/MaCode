#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 10001
#define maxM 50001

typedef int maxn, maxm;

maxn n;
maxm m;
std::vector <maxn> ad[maxN], res, st;


void Prepare() {
	std::cin >> n >> m;

	for (maxm i = 0; i < m; i++) {
		maxn u, v; std::cin >> u >> v;
		ad[u].push_back(v);
	}
}


void Process() {
	maxn u = 0; st.push_back(u);

	while (!st.empty()) {
		if (!ad[u].size()) {
			res.push_back(u);
			u = st.back(); st.pop_back();
		}
		else {
			st.push_back(u);
			maxn nu = ad[u].back(); ad[u].pop_back();
			u = nu;
		}
	}

	for (maxm i = res.size() - 1; i >= 0; i--) std::cout << res[i] << ' ';
}


int main() {
	Prepare();
	Process();
}