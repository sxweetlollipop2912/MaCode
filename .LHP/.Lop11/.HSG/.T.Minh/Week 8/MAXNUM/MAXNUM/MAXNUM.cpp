#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

#define maxN 102
#define idx(x) ((x) + 50)

typedef int maxn;
typedef std::string str;
typedef std::vector <maxn> v_t;

maxn n;
bool a[maxN], done[maxN][maxN], res[maxN][maxN];
v_t v[maxN][maxN];
std::vector <bool> resv;
str s;


void Prepare() {
	n = s.size();
	for (maxn i = 0; i < n; i++) 
		a[i] = s[n - i - 1] == '1';

	memset(done, 0, sizeof(done));
}


bool greater(const v_t& v1, const v_t& v2) {
	if (v1.size() != v2.size()) return v1.size() > v2.size();

	for (maxn i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[i]) continue;
		if (!(v1[i] & 1) && !(v2[i] & 1)) return v1[i] > v2[i];
		if ( (v1[i] & 1) &&  (v2[i] & 1)) return v1[i] < v2[i];
		return !(v1[i] & 1);
	}
	return 0;
}


void DP(const maxn pos, const maxn mem) {
	if (done[pos][idx(mem)]) return;
	done[pos][idx(mem)] = 1; v[pos][idx(mem)].resize(0);

	if (pos == n) {
		maxn m1 = mem, p1 = pos;
		while (m1) {
			if (m1 & 1) v[pos][idx(mem)].push_back(p1);
			m1 = ((m1 & 1) - m1) / 2, ++p1;
		}
		std::reverse(v[pos][idx(mem)].begin(), v[pos][idx(mem)].end());
	}

	else {
		// !((mem + a[pos]) & 1)
		bool x = !((mem + a[pos]) & 1);
		maxn m1 = mem + a[pos] + x; DP(pos + 1, (1 - m1) / 2);
		v[pos][idx(mem)] = v[pos + 1][idx((1 - m1) / 2)]; v[pos][idx(mem)].push_back(pos);

		// (mem + a[pos]) & 1
		x = !x;
		m1 = mem + a[pos] + x; DP(pos + 1, (-m1) / 2);
		if (greater(v[pos + 1][idx((-m1) / 2)], v[pos][idx(mem)]))
			v[pos][idx(mem)] = v[pos + 1][idx((-m1) / 2)];
		else x = !x;

		res[pos][idx(mem)] = x;
	}
}


void Process() {
	DP(0, 0);
	//for (maxn i = 0; i < v[0][idx(0)].size(); i++) std::cout << v[0][idx(0)][i] << ' ';
	//std::cout << f[0][idx(0)] << ' ' << last[0][idx(0)];

	resv.resize(n);
	for (maxn pos = 0, mem = 0; pos < n; pos++) {
		resv[pos] = res[pos][idx(mem)];
		mem += a[pos] + res[pos][idx(mem)], mem = ((mem & 1) - mem) / 2;
	}

	for (maxn i = n - 1; i >= 0; i--) std::cout << resv[i];
	std::cout << '\n';
}


int main() {
	//freopen("maxnum.inp", "r", stdin);
	//freopen("maxnum.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> s) {
		Prepare();
		Process();
	}
}