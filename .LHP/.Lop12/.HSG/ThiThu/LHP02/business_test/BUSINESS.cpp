#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define maxN 100002

typedef int maxn;

const maxn MINN = 100000, MAXN = 100000;

maxn root[maxN], rank[maxN];


bool Union(maxn x, maxn y) {
    //std::cout << x << ' ' << y << '\n';
    while (x != root[x]) x = root[x];
    while (y != root[y]) y = root[y];
    //std::cout << "root\n";
    if (x == y) return 0;

    if (rank[x] < rank[y]) root[x] = y;
    else root[y] = x, ++rank[x];
    return 1;
}


int main() {
    srand(time(NULL));
    int Test = 1000;

    for(int test = 1; test <= Test; test++) {
        std::ofstream inp("business.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1), k = rand() % (n + 1);
        maxn K = k;
        inp << n << ' ' << k << '\n';

        for(maxn i = 0; i < n && k > 0; i++) {
            if (n - i == k) inp << i + 1 << ' ', --k;
            else {
                int p = rand() % 2;
                if (p == 0) inp << i + 1 << ' ', --k;
            }
        }
        inp << '\n';

        for(maxn i = 0; i < n; i++) root[i] = i, rank[i] = 0;
        maxn CNT = n;
        while (CNT != 1) {
            maxn u = rand() % n, v = rand() % n;
            if (!Union(u, v)) continue;
            --CNT; inp << u + 1 << ' ' << v + 1 << '\n';
            //std::cout << u << ' ' << v << ' ' << CNT << '\n';
        }

        inp.close();

        std::cout << "RUNNING main\n";
        system("business.exe");
        std::cout << "RUNNING br\n";
        system("business_br.exe");
        if (system("fc business.out business.ans") != 0) {
            std::cout << "Test " << test << " is wrong! n = " << n << " k = " << K << '\n';
            return 0;
        }
        std::cout << "Test " << test << " is correct! n = " << n << " k = " << K << '\n';
    }
}
