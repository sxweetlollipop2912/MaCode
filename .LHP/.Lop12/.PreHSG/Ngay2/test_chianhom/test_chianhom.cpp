#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn, maxa;

const maxn MINN = 1, MAXN = 100000, MINQ = 1, MAXQ = 10000;
const maxa MINA = 1, MAXA = 1000000;


int main() {
    srand(time(NULL));

    int T = 3000;
    for(int t = 0; t < T; t++) {
        std::ofstream inp("chianhom.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn Q = MINQ + rand() % (MAXQ - MINQ + 1);
        inp << n << ' ' << Q << '\n';

        for(maxn i = 0; i < n; i++) {
            int a = MINA + rand() % (MAXA - MINA + 1);
            inp << a << ' ';
        }
        inp << '\n';

        for(maxn i = 0; i < Q; i++) {
            maxn l = 1 + rand() % (n - 1 + 1);
            maxn r = l + rand() % (n - l + 1);
            inp << l << ' ' << r << '\n';
        }

        inp.close();

        system("chianhom.exe");
        system("chianhom_lam.exe");
        if (system("fc chianhom.out chianhom.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << " Q = " << Q << '\n';
            return 0;
        }
        else
            std::cout << "Test " << t << " is correct! n = " << n << " Q = " << Q << '\n';
    }
}
