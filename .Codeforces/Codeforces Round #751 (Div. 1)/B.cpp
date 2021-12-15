#include <iostream>
#include <algorithm>

#define maxN 300002

typedef long maxn;

maxn n, res;
maxn jump[maxN], slip[maxN], mn[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 1; i <= n; i++) std::cin >> jump[i];
    for(maxn i = 1; i <= n; i++) std::cin >> slip[i];
}


void Process() {
    mn[n] = n - jump[n];
    for(maxn i = n - 1; i >= 0; i--) {
        maxn mn_cur = i + slip[i];
        mn_cur -= jump[mn_cur];
        mn[i] = std::min(mn[i + 1], mn_cur);
    }

    res = 1;
    for(maxn mn_cur = mn[n]; mn_cur != 0; mn_cur = mn[mn_cur], res++);

    std::cout << res;
}


int main() {
    Prepare();
    Process();
}