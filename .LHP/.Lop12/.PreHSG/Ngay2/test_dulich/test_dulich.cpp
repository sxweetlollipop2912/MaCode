#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn, maxa;

const maxn MINN = 3, MAXN = 100, MINP = 1, MAXP = 10, MAXM = 5000;
const maxa MINA = 1, MAXA = 1000;

bool done[MAXN + 2][MAXN + 2];


int main() {
    srand(time(NULL));

    int T = 5000;
    for(int t = 0; t < T; t++) {
        std::ofstream inp("dulich.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn m = (n - 1) + rand() % (std::min(MAXM, n * (n - 1)) - (n - 1) + 1);
        maxn P = MINP + rand() % (std::min(n - 1, MAXP) - MINP + 1);
        inp << n << ' ' << m << ' ' << P << '\n';

        for(maxn i = 0; i <= MAXN; i++) std::fill(done[i], done[i] + MAXN, 0);
        for(maxn i = 0; i < m; i++) {
            maxn u = 1 + rand() % (n - 1 + 1);
            maxn v = 1 + rand() % (n - 1 + 1);
            maxa a = MINA + rand() % (MAXA - MINA + 1);

            if (done[u][v]) {
                i--;
                continue;
            }
            done[u][v] = 1;
            inp << u << ' ' << v << ' ' << a << '\n';
        }

        inp.close();

        system("dulich.exe");
        system("dulich_lam.exe");
        if (system("fc dulich.out dulich.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << " m = " << m << " P = " << P << '\n';
            return 0;
        }
        else
            std::cout << "Test " << t << " is correct! n = " << n << " m = " << m << " P = " << P << '\n';
    }
}
