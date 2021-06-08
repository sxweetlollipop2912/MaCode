#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>

#define maxN 251
#define maxD 5002
#define D(n) (20 * (n))
#define V first
#define Day second

typedef int maxn;
typedef std::pair <maxn, maxn> bfs_t;

maxn n, m, st1, st2;
bool d[maxN][maxN], stp[2][maxN][maxD];
std::queue <bfs_t> bfs;


void Prepare() {
    std::cin >> n >> m >> st1 >> st2;
    --st1, --st2;

    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::cin >> u >> v;
        --u, --v;
        d[u][v] = 1;
    }
}


void BFS(maxn st, bool stp[maxN][maxD]) {
    bfs = std::queue <bfs_t>();
    //memset(stp, 0, sizeof(stp));

    stp[st][0] = 1;
    bfs.push(bfs_t(st, 0));

    while (!bfs.empty()) {
        maxn u = bfs.front().V, day = bfs.front().Day;
        bfs.pop();
        if (day == D(n)) continue;

        for(maxn v = 0; v < n; v++) {
            if (!d[u][v] || stp[v][day + 1]) continue;
            stp[v][day + 1] = 1;
            bfs.push(bfs_t(v, day + 1));
        }
    }
}


void Process() {
    BFS(st1, stp[0]);
    BFS(st2, stp[1]);

    for(maxn day = 0; day <= D(n); day++) for(maxn v = 0; v < n; v++) {
        if (!stp[0][v][day] || !stp[1][v][day]) continue;
        std::cout << day;
        return;
    }
    std::cout << "-1";
}


int main() {
    freopen("age.inp","r",stdin);
    freopen("age.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
