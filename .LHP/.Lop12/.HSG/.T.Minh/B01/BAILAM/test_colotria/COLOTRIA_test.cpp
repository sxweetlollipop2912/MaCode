#include <iostream>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn;

const maxn MINN = 3, MAXN = 7, MINM = 3, MAXM = 10;


int main() {
    srand(time(NULL));

    int T = 1;

    for(int t = 0; t < T; t++) {
        std::ofstream inp("colotria.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn m = MINM + rand() % (MAXM - MINM + 1);
        inp << n << ' ' << m << '\n';

        for(maxn i = 0; i < m; i++) {
            maxn x = 1 + rand() % (n - 1 + 1);
            maxn y = 1 + rand() % (n - 1 + 1);
            inp << x << ' ' << y << '\n';
        }

        inp.close();

        system("colotria_br.exe");
        system("colotria.exe");
        system("colotria_lam.exe");

        if (system("fc colotria.out colotria.ans") != 0) {
            std::cout << "LY: Test " << t << " is wrong. n = " << n << " m = " << m << '\n';
            return 0;
        }
        if (system("fc colotria_lam.out colotria.ans") != 0) {
            std::cout << "LAM: Test " << t << " is wrong. n = " << n << " m = " << m << '\n';
            return 0;
        }
        std::cout << "Test " << t << " is correct. n = " << n << " m = " << m << '\n';
    }
}
