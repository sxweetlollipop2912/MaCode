#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define maxV 101
#define maxD 1001
#define maxR 9999999

typedef long maxv, maxd, maxm;

maxd graph[maxV][maxV];
maxv n, parent[maxV];
maxd min_cur[maxV], res, s1, s2;
bool done[maxV], locked = 0;
maxm m;


void Prepare() {
	std::cin >> n >> m;

	for(maxv i = 0; i < n; i++) std::fill(graph[i], graph[i] + n, maxR);

    for(maxv i = 0; i < m; i++) {
        maxv u, v;
        maxd d;
        std::cin >> u >> v >> d;

        graph[u - 1][v - 1] = graph[v - 1][u - 1] = std::min(graph[u - 1][v - 1], d);
    }
}


struct pqueue {
    maxv v;
    maxd min;
};
pqueue newPQ(maxv v, maxd min) {
    pqueue re;
    re.v = v; re.min = min;
    return re;
}

class cmp {
public:
    bool operator() (const pqueue &p1, const pqueue &p2) {
        return p1.min > p2.min;
    }
};
std::priority_queue <pqueue, std::vector <pqueue>, cmp > pq;


maxv minv() {
	while (!pq.empty() && done[pq.top().v]) pq.pop();
	if (pq.empty()) return -1;

	maxv re = pq.top().v;
	pq.pop();

	return re;
}


void Update(maxv u) {
	for (maxv v = 0; v < n; v++)
		if (!done[v] && min_cur[v] > graph[u][v]) {
            //std::cout << u << ' ' << v << ' ' << min_cur[v] << ' ' << graph[u][v] << '\n';
			min_cur[v] = graph[u][v];
			pq.push(newPQ(v, min_cur[v]));

			if (!locked) parent[v] = u;
		}
}


void Init() {
    std::fill(min_cur, min_cur + n, maxR);
    std::fill(done, done + n, 0);

    pq = std::priority_queue <pqueue, std::vector <pqueue>, cmp >();
    res = 0;
}


void Prim() {
    Init();

	maxv u = 0;
	min_cur[u] = 0;
	if (!locked) parent[u] = -1;

	pq.push(newPQ(u, min_cur[u]));

	for (maxv i = 0; i < n - 1; i++) {
		u = minv();

		if (u == -1) {
            res = maxR;
            return;
		}

		done[u] = 1;
		Update(u);
		//std::cout << min_cur[2] << '\n';
	}

	for(maxv i = 0; i < n; i++) {
            res += min_cur[i] == maxR ? 0 : min_cur[i];
	}
}


void Process() {
    Prim();
    s1 = res;

    s2 = maxR;
    locked = 1;

    for(maxv i = 0; i < n; i++) {
        if (parent[i] == -1) continue;

        maxd tmp = graph[i][parent[i]];
        graph[i][parent[i]] = graph[parent[i]][i] = maxR;

        Prim();

        s2 = std::min(s2, res);
        //std::cout << res << ' ' << i + 1 << ' ' << parent[i] + 1 << ' ' << graph[0][2] << '\n';
        graph[i][parent[i]] = graph[parent[i]][i] = tmp;
    }
}


int main() {
    freopen("mangdien.inp","r",stdin);
    freopen("mangdien.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

	Prepare();
	Process();

	std::cout << s1 << ' ' << s2;
}
