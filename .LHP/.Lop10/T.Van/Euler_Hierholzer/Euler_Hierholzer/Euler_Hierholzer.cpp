#include "pch.h"
#include <iostream>
#include <cstdio>
#include <vector>

#define maxN 20001
#define maxM 20001

typedef int maxn, maxm;

std::vector <maxn> ad[maxN], res;
maxn n, cur = 0, odd;
maxm m;


bool Prepare() {
	std::cin >> n >> m;

	bool cnt[maxN];
	std::fill(cnt, cnt + n, 0);

	for (maxm i = 0; i < m; i++) {
		maxn u, v;
		std::cin >> u >> v;
		u--; v--;

		ad[u].push_back(v);
		ad[v].push_back(u);

		cnt[u] = !cnt[u];
		cnt[v] = !cnt[v];
	}

	for (maxn i = 0; i < n; i++) {
		if (!cnt[i]) continue;
		odd++;
		cur = n;
		ad[i].push_back(n);
		ad[n].push_back(i);
	}

	return odd == 0 || odd == 2;
}


maxn adj(maxn u) {
	for (maxn i = 0; i < ad[u].size(); i++)
		if (ad[u][i] != -1) return ad[u][i];
	return -1;
}


void Delete(maxn u, maxn v) {
	maxn i = 0;
	while (ad[u][i] != v) i++;
	ad[u][i] = -1;
}


void Hierholzer() {
	std::vector <maxn> stack;
	stack.push_back(cur);

	while (!stack.empty()) {
		cur = stack.back();
		maxn tmp = adj(cur);

		if (tmp != -1) {
			Delete(tmp, cur);
			Delete(cur, tmp);
			cur = tmp;
			stack.push_back(cur);
		}
		else {
			res.push_back(stack.back());
			stack.pop_back();
		}
	}
}


int main() {
	//freopen("euler.inp", "r", stdin);
	//freopen("euler.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	if (!Prepare()) {
		std::cout << 0;
		return 0;
	}
	Hierholzer();
	
	if (!odd) std::cout << "2\n";
	else std::cout << "1\n";
	for (maxn i = 0; i < res.size(); i++) if (res[i] != n) std::cout << res[i] + 1 << ' ';
}