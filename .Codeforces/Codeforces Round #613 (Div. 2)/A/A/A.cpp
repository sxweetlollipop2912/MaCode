#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define maxB 32
#define maxN 100001
#define LEN 30

typedef long maxn;
typedef long long maxa;
typedef int maxb;

maxn n;
maxa a[maxN], id[maxN], resa;
bool bit[maxN][maxB], res[maxB], p = 0;
std::vector <maxa> v[2];
std::set <maxa> set, vs;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Count(maxn idx) {
	maxa x = a[idx];
	for (maxb i = 0; x != 0; i++) {
		bit[idx][i] = (x & 1), x >>= 1;
	}
}


void Process() {
	for (maxn i = 0; i < n; i++) Count(i);

	for (maxn i = 0; i < n; i++) {
		id[i] = bit[i][LEN];
		if (vs.find(id[i]) == vs.end()) {
			vs.insert(id[i]); v[p].push_back(id[i]);
		}
	}
	if (v[p].size() == 1) res[LEN] = 1;

	for (maxb b = LEN - 1; b >= 0; b--) {
		set.clear(); p = !p; v[p].clear();
		for (maxn i = 0; i < n; i++) {
			if (vs.find(id[i]) == vs.end()) continue;
			id[i] = id[i] * 2 + 2 + (maxa)bit[i][b];
			set.insert(id[i]);
		}
		vs.clear();
		for (maxn i = 0; i < v[!p].size(); i++) {
			if (set.find(v[!p][i] * 2 + 2) != set.end() && set.find(v[!p][i] * 2 + 2 + 1) != set.end()) continue;
			maxa a = set.find(v[!p][i] * 2 + 2) != set.end() ? v[!p][i] * 2 + 2 : v[!p][i] * 2 + 2 + 1;
			vs.insert(a); v[p].push_back(a); res[b] = 1;
		}
		if (res[b] == 1) continue;

		for (maxn i = 0; i < v[!p].size(); i++) {
			maxa a = v[!p][i] * 2 + 2;
			vs.insert(a); v[p].push_back(a);
			a = v[!p][i] * 2 + 2 + 1;
			vs.insert(a); v[p].push_back(a);
		}
	}

	resa = 0;
	for (maxb b = LEN; b >= 0; b--) {
		if (!res[b]) resa += (1 << (maxa)b);
	}
	std::cout << resa;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}