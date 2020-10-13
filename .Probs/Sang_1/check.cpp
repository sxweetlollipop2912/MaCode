#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define maxN 200002

typedef long maxn;
typedef long long maxa;

const maxn MINN = 1, MAXN = 50;
const maxa MINM = 0, MAXM = 100000000;

maxa a[maxN];

int main() {
    srand(time(NULL));
    int T = 1000;

    for (int t = 0; t < T; t++) {
        std::ofstream inp("main.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxa m = MINM + rand() & (MAXM - MINM + 1);
        inp << n << ' ' << m << '\n';

        for (maxn i = 0; i < n; i++) {
            a[i] = 0 + rand() % ((m / 3) - 0 + 1);
            inp << a[i] << ' ';
        }
        
        inp.close();

        system("main.exe");
        system("main_br.exe");
        if (system("fc main.out main.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << ", m = " << m <<  '\n';
            return 0;
        }
        std::cout << "Test " << t << " is correct! n = " << n << ", m = " << m <<  '\n';
    }
}