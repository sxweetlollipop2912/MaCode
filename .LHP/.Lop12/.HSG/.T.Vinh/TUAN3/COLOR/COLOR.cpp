#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 200001

typedef long maxn;
typedef int maxa;

maxn n;
int Q;
maxa R[maxN], G[maxN], B[maxN];
std::vector <maxa> vGB;


void Prepare() {
    std::cin >> n >> Q;
    for(maxn i = 0; i < n; i++) std::cin >> R[i];
    for(maxn i = 0; i < n; i++) std::cin >> G[i];
    for(maxn i = 0; i < n; i++) std::cin >> B[i];

    std::sort(R, R + n); std::sort(G, G + n); std::sort(B, B + n);

    for(maxn i = 0; i < n; i++) {
        vGB.push_back(G[i]); vGB.push_back(B[i]);
    }
    std::sort(vGB.begin(), vGB.end());
}


maxn Q1() {
    maxa re = n;
    for(maxn ir = n - 1, iv = vGB.size() - 1; ir >= 0 && iv >= 0; ir--) {
        if (R[ir] <= vGB[iv]) --re, --iv;
    }
    return re;
}


maxn Q2() {
    maxn re = 0;
    for(maxn ir = 0, iv = 0; ir < n && iv < n; ir++) {
        if (R[ir] > std::max(G[iv], B[iv])) ++re, ++iv;
    }
    return re;
}


void Process() {
    if (Q == 1) std::cout << Q1();
    else std::cout << Q2();
}


int main() {
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
