#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
#define maxN 200001
#define crew 0
#define imp 1
#define V first
#define R second
#define IMP first
#define CREW second
 
typedef long maxn;
typedef std::pair <maxn, bool> v_t;
typedef std::pair <maxn, maxn> p_t;

maxn n, m, res;
int team[maxN];
std::vector <v_t> ad[maxN];


void Prepare() {
    std::cin >> n >> m;
 
    for(maxn i = 0; i < n; i++) ad[i].clear();
 
    for(maxn i = 0; i < m; i++) {
        maxn u, v; std::string s;
        std::cin >> u >> v >> s;
        --u, --v;
        ad[u].push_back(v_t(v, (s == "imposter")? imp : crew));
        ad[v].push_back(v_t(u, (s == "imposter")? imp : crew));
    }
}

 
p_t DFS(const maxn u) {
    p_t re = p_t(0, 0);
    
    if (team[u] == imp) ++re.IMP;
    else ++re.CREW;

    for(maxn i = 0; i < ad[u].size(); i++) {
        maxn v = ad[u][i].V;
        bool r = ad[u][i].R;

        if (team[v] != -1) {
            if (team[v] != team[u] ^ r) return p_t(-1, -1);
            continue;
        }

        team[v] = team[u] ^ r;
        p_t rv = DFS(v);
        if (rv.IMP == -1 || rv.CREW == -1) return p_t(-1, -1);
        re.IMP += rv.IMP;
        re.CREW += rv.CREW;
    }
    
    return re;
}
 
 
bool Process() {
    res = 0;
 
    std::fill(team, team + n, -1);
 
    for(maxn i = 0; i < n; i++) {
        if (team[i] != -1) continue;

        team[i] = 0;
        auto re = DFS(i);

        if (re.IMP == -1 || re.CREW == -1) return 0;
        res += std::max(re.IMP, re.CREW);
    }
 
    std::cout << res << '\n';
    return 1;
}
 

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    int t; std::cin >> t;
    while (t--) {
        Prepare();
        if (!Process()) std::cout << "-1\n";
    }
}