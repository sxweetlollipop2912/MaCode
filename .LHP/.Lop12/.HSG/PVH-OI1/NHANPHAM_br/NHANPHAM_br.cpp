#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 100001

typedef long maxn;
typedef long long maxa;
typedef double db;

maxn n;
maxa K, a[maxN];


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
    maxa day = 2, x = 1 - a[0];
    for(maxn i = 1 % n; x < K; day++, i = (i + 1) % n) x += day - a[i];//, std::cout << day << ' ' << x << ' ' << i << ' ' << a[i] << '\n';
    std::cout << day - 1;
}


int main() {
    //freopen("nhanpham.inp", "r", stdin);
    //freopen("nhanpham.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
