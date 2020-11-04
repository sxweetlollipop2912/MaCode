#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

#define maxN 1002
#define n first
#define k second

typedef long long maxa;
typedef std::pair <maxa, maxa> C_t;

const maxa MAXN = 1000, MAXA = 1000000000000000;

maxa N, A, C[maxN][maxN];
std::map <maxa, C_t> map;


void Prepare() {
    maxa x = 10000000;
    map[(x / 2) * (x - 1)] = C_t(x, 2);

    x = 1000000;
    map[(x / 2) * (x - 1)] = C_t(x, 2);

    x = 100000;
    map[(x / 2) * (x - 1)] = C_t(x, 2);
    map[(x / 2) * ((x - 1) / 3) * (x - 2)] = C_t(x, 3);

    x = 10000;
    map[(x / 2) * (x - 1)] = C_t(x, 2);
    map[(x / 2) * ((x - 1) / 3) * (x - 2)] = C_t(x, 3);
    map[(x / 8) * ((x - 1) / 3) * (x - 2) * (x - 3)] = C_t(x, 4);
}


void Process() {
    C[1][1] = 1;

    for(maxa i = 2; i <= MAXN; i++) {
        C[i][1] = C[i][i - 1] = i;
        C[i][i] = 1;
        for(maxa j = 2; j < i - 1 && (C[i - 1][j] + C[i - 1][j - 1] <= MAXA); j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (map.find(C[i][j]) == map.end()) 
                map[C[i][j]] = C_t(i, j);
            //std::cout << i << ' ' << j << ' ' << C[i][j] << '\n';
        }
    }

    int t; std::cin >> t;
    while (t--) {
        maxa x; std::cin >> x;
        if (map.find(x) != map.end()) std::cout << map[x].n << ' ' << map[x].k << '\n';
        else std::cout << "0 0\n";
    }
}


int main() {
    //freopen("dangtri.inp", "r", stdin);
    //freopen("dangtri.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}