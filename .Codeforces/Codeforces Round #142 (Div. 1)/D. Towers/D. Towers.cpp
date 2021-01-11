#include <iostream>
#include <algorithm>

#define maxN 5002
#define INF 9999999999

typedef int maxn;
typedef long long maxa;

maxn n, res;
maxa a[maxN], f[maxN], h[maxN];


void Prepare() {
    std::cin >> n;
    a[0] = 0;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i];
}


void Process() {
    f[0] = 0;
    for(maxn i = 1; i <= n; i++) {
        maxa sum = 0;
        for(maxn j = i; j > 0; j--) {
            sum += a[j];
            if (sum < h[j - 1]) continue;
            f[i] = f[j - 1] + i - j, h[i] = sum;
            //std::cout << sum << ' ';
            break;
        }
    }
    std::cout << f[n];
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}