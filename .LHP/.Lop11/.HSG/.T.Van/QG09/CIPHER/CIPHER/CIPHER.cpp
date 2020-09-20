#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

#define maxN 41
#define N1 (n / 2)
#define on(b, i) ((b) | ((maxb)1 << (maxb)(i)))
#define val first
#define pick second

typedef long maxn;
typedef long long maxa, maxb;
typedef std::pair <maxa, maxb> v_t;

maxn n;
maxa a[maxN], S;
maxb res;
std::unordered_map <maxa, maxb> map;
std::vector <v_t> v;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
	std::cin >> S;
}


maxb Process() {
	v.push_back(v_t(0, 0)); map[0] = 0;
	for (maxn i = 0; i < N1; i++) for (maxn j = v.size() - 1; j >= 0; j--) {
		v.push_back(v_t(a[i] + v[j].val, on(v[j].pick, i)));
		map[v.back().val] = v.back().pick;
	}

	v.resize(1);
	for (maxn i = N1; i < n; i++) for (maxn j = v.size() - 1; j >= 0; j--) {
		v.push_back(v_t(a[i] + v[j].val, on(v[j].pick, i)));
		if (map.find(S - v.back().val) != map.end()) return v.back().pick + map[S - v.back().val];
	}

	return 0;
}


int main() {
	//freopen("cipher.inp", "r", stdin);
	//freopen("cipher.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	res = Process();
	for(maxn i = 0; i < n; i++) std::cout << (res & 1), res >>= 1;
}