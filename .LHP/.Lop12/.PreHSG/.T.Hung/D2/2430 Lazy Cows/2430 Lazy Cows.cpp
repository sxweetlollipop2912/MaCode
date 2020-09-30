#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

#define maxN 1002

typedef int maxn;
typedef long maxa;
typedef std::map <maxa, bool[2]> map_t;

maxn n, K, N, f[maxN][maxN][3], res;
map_t map;


void Prepare() {
    std::cin >> n >> K >> N;

    for (maxn i = 0; i < n; i++) {
        maxa x, y; std::cin >> x >> y;
        --x, --y;
        map[y][x] = 1;
    }
}


void Process() {
    map_t::iterator prev = map.begin();
    maxn i = 0;

    f[0][1][0] = f[0][1][1] = 1;
    f[0][1][2] = 2;
    for (map_t::iterator it = map.begin(); it != map.end(); prev = it, it++, i++) {
        if (i == 0) continue;

        for (maxn k = 1; k <= K; k++) {
            if (prev->second[0] && prev->second[1]) {
                f[i][k][0] = f[i][k][1] = f[i - 1][k - 1][2] + 1;
                f[i][k][2] = f[i - 1][k][2] + 2;
            }
            else if (prev->second[0]) {
                f[i][k][0] = std::min(f[i - 1][k - 1][2], f[i - 1][k][0]) + 1;
                f[i][k][1] = std::min(f[i - 1][k - 1][2], f[i - 1][k - 1][0]) + 1;
                f[i][k][2] = std::min(f[i - 1][k - 1][0], f[i - 1][k][2]) + 2;
            }
            else if (prev->second[1]) {
                f[i][k][0] = std::min(f[i - 1][k - 1][2], f[i - 1][k - 1][1]) + 1;
                f[i][k][1] = std::min(f[i - 1][k - 1][2], f[i - 1][k][1]) + 1;
                f[i][k][2] = std::min(f[i - 1][k - 1][1], f[i - 1][k][2]) + 2;
            }
        }
    }

    if (prev->second[0] && prev->second[1]) {
        res = f[i - 1]
            }
            else if (prev->second[0]) {
                f[i][k][0] = std::min(f[i - 1][k - 1][2], f[i - 1][k][0]) + 1;
                f[i][k][1] = std::min(f[i - 1][k - 1][2], f[i - 1][k - 1][0]) + 1;
                f[i][k][2] = std::min(f[i - 1][k - 1][0], f[i - 1][k][2]) + 2;
            }
            else if (prev->second[1]) {
                f[i][k][0] = std::min(f[i - 1][k - 1][2], f[i - 1][k - 1][1]) + 1;
                f[i][k][1] = std::min(f[i - 1][k - 1][2], f[i - 1][k][1]) + 1;
                f[i][k][2] = std::min(f[i - 1][k - 1][1], f[i - 1][k][2]) + 2;
            }    
}