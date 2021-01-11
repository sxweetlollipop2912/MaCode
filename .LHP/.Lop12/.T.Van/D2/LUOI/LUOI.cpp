// AC
#include <bits/stdc++.h>

#define maxN 510
#define inf INT_MAX

typedef int maxn;
typedef std::pair<maxn, maxn> ii;

maxn td[]  =  { 1,-1,0,0 };
maxn tc[]  =  { 0,0,-1,1 };
maxn n, m, si, sj, ui, uj, vi, vj;
bool mark[maxN][maxN];
char a[maxN][maxN];


bool check(maxn x, maxn y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

maxn bfs(maxn si, maxn sj) {
    maxn cnt = 1;
    std::queue<ii> q;

    q.push(ii(si,sj));
    mark[si][sj]  =  1;

    while (!q.empty()) {
        ui = q.front().first;
        uj = q.front().second;
        q.pop();
        for (maxn k = 0; k < 4; ++k) {
            vi = ui+td[k];
            vj = uj+tc[k];
            if (check(vi,vj) && (a[vi][vj] == a[si][sj]) && !mark[vi][vj]) {
                mark[vi][vj] = 1;
                q.push(ii(vi,vj));
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    freopen("LUOI.INP","r",stdin);
    freopen("LUOI.OUT","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (maxn i = 1; i<= n; ++i) for (maxn j = 1; j<= m; ++j)
        std::cin >> a[i][j];

    for (maxn i = 1; i <= n; ++i)
        for (maxn j = 1; j <= m; ++j) mark[i][j] = 0;

    std::vector<int> res;
    for (maxn i = 1; i <= n; ++i) for (maxn j = 1; j <= m; ++j)
        if (!mark[i][j]) res.push_back(bfs(i,j));

    std::cout << res.size() << '\n';
    for (maxn i = 0; i < res.size(); ++i) std::cout << res[i] << '\n';
}

