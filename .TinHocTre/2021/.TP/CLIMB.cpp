// 50%
#include <iostream>
#include <algorithm>
#include <math.h>

#define maxN 100001

typedef long maxn;
typedef long long maxa;
typedef double db;

const db eps = 1e-7;

maxn n, m, a[maxN], b[maxN];
maxa X[maxN], H[maxN], des[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> X[i] >> H[i];

    std::cin >> m;
    for(maxn i = 0; i < m; i++) std::cin >> a[i] >> b[i], --a[i], --b[i];
}


void Process() {
    for(maxn i = 0; i < n; i++) {
        des[i] = i;
        db max = -100;
        for(maxn j = i + 1; j < n; j++) {
            maxa h = H[j] - H[i];
            maxa x = X[j] - X[i];
            db tan = h / (db)x;

            if (tan - eps > max) {
                //std::cout << "tan " << i << ' ' << tan << ' ' << tan - eps << ' ' << max << '\n';
                max = tan;
                des[i] = j;
            }
        }
    }

    for(maxn i = 0; i < m; i++) {
        while (a[i] != b[i]) {
            if (a[i] < b[i]) a[i] = des[a[i]];
            else b[i] = des[b[i]];
        }
        std::cout << a[i] + 1 << ' ';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}