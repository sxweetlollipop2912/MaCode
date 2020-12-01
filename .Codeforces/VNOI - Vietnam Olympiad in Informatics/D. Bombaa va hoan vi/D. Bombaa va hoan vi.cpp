//D. Bombaa va hoan vi
//UNDONE
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

#define maxN 200002

typedef long maxn;

maxn n, K, a[maxN];
std::set <maxn> set, pos[maxN];
std::queue <maxn> Q;


void Prepare() {
    std::cin >> n >> K;

    for (maxn i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].insert(i);
    }
}


void Process() {
    for (maxn i = 0; i < n; i++) {
        set.insert(*pos[a[i]].begin());
    }

    bool done = 0;
    while (!done) {
        done = 1;
        for (auto i : set) Q.push(i);

        while (!Q.empty()) {
            maxn i = Q.front(); Q.pop();

            auto next = set.upper_bound(i);
            if (next == set.end()) continue;
            
            auto nexta = pos[a[i]].upper_bound(i);
            if (nexta == pos[a[i]].end()) continue;

            if (a[*next] > a[i]) continue;
            set.erase(i);
            set.insert(*nexta);

            Q.push(*nexta);
            done = 0;
            std::cout << i << ' ' << *nexta << ' ' << a[i] << '\n';
        }
    }

    for(auto i : set) std::cout << a[i] << ' ';
}


int main() {
    //freopen("D.inp", "r", stdin);
    //freopen("D.out", "w", stdout);

    //std::ios_base::sync_with_stdio(0);
    //std::cin.tie(0);

    Prepare();
    Process();
}