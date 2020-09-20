#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 100001
#define maxA 1000000002
#define tm first
#define val second

typedef long maxn, maxt;
typedef long long maxa;
typedef std::pair <maxt, maxa> p_t;

maxn n, id[maxN];
maxt A, B;
p_t dm[maxN];
std::vector <p_t> resv;
maxa res;


bool cmp(const maxn x, const maxn y) {
	return dm[x].tm < dm[y].tm;
}

void Prepare() {
	std::cin >> n >> A >> B;
	for (maxn i = 0; i < n; i++) std::cin >> dm[i].tm >> dm[i].val, id[i] = i;
	std::sort(id, id + n, cmp);
}


class cmp_pq {
public:
	bool operator()(const maxn p1, const maxn p2) {
		return dm[p1].val < dm[p2].val;
	}
};
std::priority_queue <maxn, std::vector <maxn>, cmp_pq> pq;


void Process() {
	maxn cur = 0;
	for (; cur < n && dm[id[cur]].tm < A; cur++) pq.push(id[cur]);

	for (maxt ct = A; ct <= B && (!pq.empty() || cur < n); ct++) {
		while (cur < n && ct == dm[id[cur]].tm) {
			pq.push(id[cur]); ++cur;
		}
		if (!pq.empty()) {
			resv.push_back(p_t(ct, pq.top()));
			res += dm[pq.top()].val; pq.pop();
		}
		else if (cur < n) ct = dm[id[cur]].tm - 1;
	}

	std::cout << res << '\n';
	for (maxn i = 0; i < resv.size(); i++) std::cout << resv[i].first << ' ' << resv[i].second + 1 << '\n';
}


int main() {
	//freopen("diamond.inp", "r", stdin);
	//freopen("diamond.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}