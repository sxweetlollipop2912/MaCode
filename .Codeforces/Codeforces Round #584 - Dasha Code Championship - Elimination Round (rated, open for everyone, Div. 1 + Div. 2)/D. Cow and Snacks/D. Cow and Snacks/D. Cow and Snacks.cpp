#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 100001
#define id second
#define val first

typedef long maxn;
typedef std::pair <maxn, maxn> pq_t;

maxn s, n, a[maxN][2], cnt[maxN], res;
bool done[maxN];
std::vector <maxn> like[maxN];
std::priority_queue <pq_t, std::vector <pq_t>, std::greater <pq_t> > pq;


maxn clas(const maxn s1, const maxn s2) {
	if (!cnt[s1] || !cnt[s2]) return 0;
	if (cnt[s1] > 1 && cnt[s2] > 1) return 1;
	if (cnt[s1] == 1 && cnt[s2] == 1) return 0;
	return 2;
}


void Prepare() {
	std::cin >> s >> n;

	for (maxn i = 0; i < n; i++) {
		std::cin >> a[i][0] >> a[i][1];
		++cnt[a[i][0]], ++cnt[a[i][1]];
		like[a[i][0]].push_back(i);
		like[a[i][1]].push_back(i);
	}

	for (maxn i = 0; i < n; i++) 
		pq.push(pq_t(clas(a[i][0], a[i][1]), i));
}


void Add(const maxn s) {
	cnt[s] = 0;
	for (maxn ii = 0; ii < like[s].size(); ii++) {
		maxn j = like[s][ii];
		if (!done[j]) pq.push(pq_t(clas(a[j][0], a[j][1]), j));
	}
}


void Process() {
	maxn CNT = 0; res = 0;

	while (CNT != n) {
		maxn i = pq.top().id; pq.pop();
		if (done[i]) continue;
		done[i] = 1, ++CNT;

		res += (!cnt[a[i][0]] && !cnt[a[i][1]]);
		if (cnt[a[i][0]]) Add(a[i][0]);
		if (cnt[a[i][1]]) Add(a[i][1]);
	}

	std::cout << res;
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}