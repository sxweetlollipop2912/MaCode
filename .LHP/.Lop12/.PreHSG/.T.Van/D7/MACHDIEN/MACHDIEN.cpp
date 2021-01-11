#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 100001
#define X first
#define Y second

typedef long maxn, maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n;
p_t a[maxN];
std::vector <maxa> V;


void Prepare(){
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i].X >> a[i].Y;
    std::sort(a, a + n);
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        maxn it = std::lower_bound(V.begin(), V.end(), a[i].Y) - V.begin();
        if (it == 0) V.push_back(a[i].Y);
        else V[it - 1] = a[i].Y;
        //std::cout << i << ' ' << it << ' ' << a[i].Y << ' ' << V[it] << ' ' << V.size() << '\n';
    }
    std::cout << V.size();
}


int main() {
    freopen("machdien.inp", "r", stdin);
    freopen("machdien.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
