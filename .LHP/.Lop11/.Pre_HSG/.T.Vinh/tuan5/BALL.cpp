#include <iostream>
#include <vector>

#define maxN 300003
#define loop (n + 1)
#define option first
#define vert second
#define place 0
#define del 1

typedef long maxn;
typedef std::pair <bool, maxn> qu_t;

maxn n, next[maxN], root[maxN];
std::vector <qu_t> queries;
bool go[maxN], done[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn u = 1; u <= n; u++) {
        std::cin >> next[u];
        go[u] = next[u];
    }

    long q; std::cin >> q;
    while (q--) {
        maxn opt, u;
        std::cin >> opt >> u, --opt;
        if (opt == del) go[u] = false;
        queries.emplace_back(qu_t(opt, u));
    }
    root[loop] = loop;
}


maxn Root(maxn x) {
    while (x != root[x]) x = root[x];
    return x;
}


void Union(maxn x, maxn y) {
    x = Root(x); y = Root(y);
    if (x == y) root[x] = root[y] = loop;
    else root[x] = y;
}


maxn DFS(const maxn u) {
    done[u] = true;
    if (!go[u]) return (root[u] = u);
    if (!done[next[u]]) return (root[u] = DFS(next[u]));
    if (root[next[u]]) return (root[u] = root[next[u]]);
    return (root[u] = loop);
}


void Process() {
    for(maxn u = 1; u <= n; u++) if (!root[u]) DFS(u);

    for(maxn q = queries.size() - 1; q >= 0; q--) {
        if (queries[q].option == place) queries[q].vert = Root(queries[q].vert);
        else {
            go[queries[q].vert] = true;
            Union(queries[q].vert, next[queries[q].vert]);
        }
    }
    for(maxn q = 0; q < queries.size(); q++) {
        if (queries[q].option == del) continue;
        if (queries[q].vert != loop) std::cout << queries[q].vert << '\n';
        else std::cout << "LOOP\n";
    }
}


int main() {
    freopen("ball.inp", "r", stdin);
    freopen("ball.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}