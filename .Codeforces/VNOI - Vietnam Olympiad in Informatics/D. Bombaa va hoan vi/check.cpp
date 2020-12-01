#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>

typedef int maxn;

const maxn MINN = 5, MAXN = 20, MINK = 1;


int main() {
    srand(time(NULL));

    int t = 1000;
    for (int i = 0; i < t; i++) {
        std::ofstream inp("D.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn K = MINK + rand() % ((n / 2) - MINK + 1);
        inp << n << ' ' << K << '\n';

        for (maxn i = K; i > 0; i--) inp << i << ' ';
        for (maxn i = K; i < n; i++) {
            maxn a = MINK + rand() % (K - MINK + 1);
            inp << a << ' ';
        }

        inp.close();

        system("\"D. Bombaa va hoan vi.exe\"");
        system("D_br.exe");
        if (system("fc D.out D.ans") != 0) {
            std::cout << "Test " << i << " is wrong! n = " << n << " K = " << K;
            return 0;
        }
        else std::cout << "Test " << i << " is correct! n = " << n << " K = " << K << '\n';
    }
}