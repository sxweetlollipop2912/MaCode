#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1000002
#define root 1

typedef long maxn, maxa;
typedef std::pair<maxn, maxa> st_t;

maxn n, cle[maxN], cri[maxN], par[maxN];
maxa a[maxN];
std::vector <maxa> res;


void Insert(maxn u, maxn i) {
	while (true) {
		if (a[i] <= a[u]) {
			if (!cle[u]) {
				cle[u] = i, par[i] = u;
				return;
			}
			else
				u = cle[u];
		}
		else {
			if (!cri[u]) {
				cri[u] = i, par[i] = u;
				return;
			}
			else
				u = cri[u];
		}
	}
}


void Prepare() {
	std::cin >> n >> a[root];

	for (maxn i = 2; i <= n; i++) {
		std::cin >> a[i];
		Insert(root, i);
	}
}


void Count(maxn u, maxn row) {
	std::vector <st_t> st;
	st.push_back(st_t(u, row));

	while (!st.empty()) {
		u = st.back().first, row = st.back().second;
		st.pop_back();

		if (res.size() <= row) res.push_back(a[u]);
		else res[row] = std::max(res[row], a[u]);
		if (cri[u]) {
			st.push_back(st_t(cri[u], row));
		}
		if (cle[u]) {
			st.push_back(st_t(cle[u], row + 1));
		}
	}
}


void Process() {
	Count(root, 0);
	std::sort(res.begin(), res.end());
	for (maxn i = 0; i < res.size(); i++)
		std::cout << res[i] << ' ';
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}