#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

#define maxN 1001
#define T 1

typedef int maxn;
typedef long long maxa;
typedef std::vector <maxa> v_t;
typedef std::set <maxa> set_t;

std::map <maxa, v_t > map;
set_t set;
std::priority_queue <maxa, v_t, std::greater<maxa> > pq;

maxn n, m;
maxa mx_soon[maxN], mx_late[maxN], res_time, res_comp;
std::vector <maxn> ad[maxN], adr[maxN];


void Prepare() {
	std::cin >> n >> m;

	for(maxn i = 0; i < m; i++) {
        maxn u, v;
        std::cin >> u >> v;
        --u, --v;
        ad[u].push_back(v);
        adr[v].push_back(u);
	}

	std::fill(mx_soon, mx_soon + n, -1);
	std::fill(mx_late, mx_late + n, -1);
}


void DFS(const maxn u, const std::vector <maxn> ad[maxN], maxa mx[maxN]) {
	mx[u] = 0;
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (mx[v] == -1)
			DFS(v, ad, mx);
		mx[u] = std::max(mx[u], mx[v] + T);
	}
}


void MinTime_Process() {
    for (maxn i = 0; i < n; i++)
		if (mx_soon[i] == -1) DFS(i, adr, mx_soon);
	for (maxn i = 0; i < n; i++)
		if (mx_late[i] == -1) DFS(i, ad, mx_late);


	for (maxn i = 0; i < n; i++)
		res_time = std::max(res_time, mx_soon[i] + T);
}


bool Check(const maxn lim) {
    pq = std::priority_queue <maxa, v_t, std::greater<maxa> >();

    maxa px = *set.begin();
    for(set_t::iterator it = set.begin(); it != set.end(); it++) {
        maxa x = *it;

        for(maxn i = 0; i < (x - (px + 1)) * lim && !pq.empty(); i++)
            pq.pop();

        if (map.find(x) != map.end()) {
            v_t& v = map[x];
            for(maxn i = 0; i < v.size(); i++)
                pq.push(v[i]);
        }
        for(maxn i = 0; i < lim && !pq.empty(); i++) pq.pop();
        if (!pq.empty() && pq.top() == x)
            return 0;

        px = x;
    }
    return 1;
}


void MinComp_Process() {
    for(maxn i = 0; i < n; i++) {
        maxn x = mx_soon[i], y = res_time - mx_late[i] - T;
        map[x].push_back(y);
        set.insert(x);
        set.insert(y);
    }

    maxn l = 1, r = n;
    while (l != r) {
        maxn m = (l + r) / 2;
        if (Check(m)) r = m;
        else l = m + 1;
    }
    res_comp = l;
}


void Process() {
    MinTime_Process();
    MinComp_Process();

    std::cout << res_time << ' ' << res_comp;
}


int main() {
	freopen("task.inp", "r", stdin);
	freopen("task.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}
