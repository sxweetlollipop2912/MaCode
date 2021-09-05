// AC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 100001
#define val first
#define idx second

typedef int maxn, maxa;
typedef long long maxr;
typedef std::pair <maxa, maxn> p_t;

maxn n, K;
maxa a[maxN];
maxr res;
std::vector <p_t> v1, v2;


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


bool cmp(const p_t p1, const p_t p2) {
    return p1.val < p2.val;
}


void Process() {
    v1.push_back(p_t(a[K], K));
    for(maxn i = K - 1; i >= 0; i--) {
        if (a[i] < v1.back().val) v1.push_back(p_t(a[i], i));
    }
    v1.push_back(p_t(-1, -1));
    std::reverse(v1.begin(), v1.end());

    v2.push_back(p_t(a[K], K));
    for(maxn i = K + 1; i < n; i++) {
        if (a[i] < v2.back().val) v2.push_back(p_t(a[i], i));
    }
    v2.push_back(p_t(-1, n));
    std::reverse(v2.begin(), v2.end());

    res = 0;
    for(maxn i = 1; i < v1.size(); i++) {
        maxn l = v1[i - 1].idx + 1;
        maxn r = v2[std::lower_bound(v2.begin(), v2.end(), v1[i], cmp) - v2.begin() - 1].idx - 1;
        res = std::max(res, (maxr)v1[i].val * (maxr)(r - l + 1));
    }
    for(maxn i = 1; i < v2.size() - 1; i++) {
        maxn r = v2[i - 1].idx - 1;
        maxn l = v1[std::lower_bound(v1.begin(), v1.end(), v2[i], cmp) - v1.begin() - 1].idx + 1;
        res = std::max(res, (maxr)v2[i].val * (maxr)(r - l + 1));
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}