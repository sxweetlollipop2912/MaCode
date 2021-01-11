#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN (maxn)100001
//#define maxL (maxa)1000000000000000001
#define pos first
#define des second

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> info_t;

maxn n;
maxa T;
info_t info[maxN];
std::vector <maxa> lis;


void Prepare() {
    std::cin >> n >> T;
    for(maxn i = 0; i < n; i++) std::cin >> info[i].pos >> info[i].des, info[i].des = info[i].pos + T * info[i].des;
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        maxn li = std::upper_bound(lis.begin(), lis.end(), -info[i].des) - lis.begin();
        if (li == lis.size()) lis.push_back(-info[i].des);
        else lis[li] = -info[i].des;
    }
    std::cout << lis.size();
}


int main() {
    //freopen("cowjog.inp", "r", stdin);
    //freopen("cowjog.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}