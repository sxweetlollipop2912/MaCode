// full test
#include <iostream>
#include <fstream>

bool f[1000][1000], visit[1000];
int count[1000], n, m, k, hooman[100], re;


void Prepare() {
    std::cin >> k >> n >> m;
    for(int i = 0; i < k; i++)
        std::cin >> hooman[i];
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        f[u - 1][v - 1] = 1;
    }
}


void DFS(int u) {
    visit[u] = 1;
    count[u]++;
    if (count[u] == k) re++;
    for(int v = 0; v < n; v++) {
        if (f[u][v] && !visit[v]) DFS(v);
    }
}


int main() {
    freopen("KEHOACH.inp", "r", stdin);
    freopen("KEHOACH.out", "w", stdout);
    Prepare();
    for(int i = 0; i < k; i++) {
        std::fill(visit, visit + n, 0);
        DFS(hooman[i] - 1);
    }
    std::cout << re;
}
