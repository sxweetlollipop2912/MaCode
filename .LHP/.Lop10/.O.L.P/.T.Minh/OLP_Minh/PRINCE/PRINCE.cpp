#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 501
#define maxC 1000001
#define maxM 1000000001
#define maxR 1000000000000001

typedef int maxn;
typedef long maxc;
typedef long long maxm;

maxn n, id[maxN];
maxc x[maxN];
maxm m[maxN];


bool cmp(maxn i, maxn j) {
    return x[i] < x[j];
}

void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        std::cin >> x[i] >> m[i];
        id[i] = i;
    }

    std::sort(id, id + n, cmp);
}
