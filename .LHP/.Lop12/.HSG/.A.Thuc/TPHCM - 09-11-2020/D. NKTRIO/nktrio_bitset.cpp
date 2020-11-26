#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>

#define maxN 1001

typedef int maxn;

maxn n;
bool a[maxN][maxN];
std::bitset <maxN> row[maxN], col[maxN];


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < n; j++) {
        std::cin >> a[i][j];
        row[i][j] = a[i][j], col[j][i] = a[i][j];
    }
}


void Process() {
    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < n; j++) {
        if (!a[i][j]) continue;
        std::bitset <maxN> bit = col[i] & row[j];
        if (!bit.any()) continue;
        for(maxn k = 0; k < n; k++) {
            if (!bit[k]) continue;
            std::cout << i + 1 << ' ' << j + 1 << ' ' << k + 1;
            return;
        }
    }
    std::cout << "-1 -1 -1";
}


int main() {
    //freopen("D.inp", "r", stdin);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
