#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1000002
#define maxA 1000000001

typedef long maxn, maxa;

maxn n, step[maxN];
maxa h[maxN], res[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> h[i];
    for(maxn i = 0; i < n; i++) std::cin >> step[i];
}


void Process() {
    std::vector <maxa> stack;
    stack.push_back(maxA);

    for(maxn i = n - 1; i >= 0; i--) {
        while (stack.back() <= h[i]) stack.pop_back();
        stack.push_back(h[i]);

        maxn xstep = stack.size() - step[i] - 1;
        //std::cout << xstep << '\n';
        res[i] = xstep > 0 ? stack[xstep] : -1;
    }
}


int main() {
    freopen("frogs.inp","r",stdin);
    freopen("frogs.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
    for(maxn i = 0; i < n; i++) std::cout << res[i] << ' ';
}
