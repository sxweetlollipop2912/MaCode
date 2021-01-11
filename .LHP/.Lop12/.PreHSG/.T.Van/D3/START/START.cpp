#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>

#define maxN 1001

typedef int maxn;
typedef long long maxa;
typedef std::vector <maxa> v_t;
typedef std::set <maxa> set_t;

maxn n, res;
std::map <maxa, v_t > map;
set_t set;
std::priority_queue <maxa, v_t, std::greater<maxa> > pq;


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        maxn x, y;
        std::cin >> x >> y;
        map[x].push_back(y);

        set.insert(x);
        set.insert(y);
    }
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


void Process() {
    maxn l = 1, r = n;

    while (l != r) {
        maxn m = (l + r) / 2;
        if (Check(m)) r = m;
        else l = m + 1;
    }

    std::cout << l;
}


int main() {
    freopen("start.inp","r",stdin);
    freopen("start.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
