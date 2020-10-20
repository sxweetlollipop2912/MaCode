#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define maxN 200002

typedef long maxn;
typedef long long maxa;

const maxn MINN = 1, MAXN = 100000;
const maxa MINA = -5, MAXA = 5;


int main() {
    srand(time(NULL));
    int T = 1000;

    for (int t = 0; t < T; t++) {
        std::ofstream inp("truyvan.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        inp << n << '\n';
        for (maxn i = 0; i < n; i++) {
            maxa a = MINA + rand() % (MAXA - MINA + 1);
            inp << a << ' ';
        }

        maxn Q = MINN + rand() % (MAXN - MINN + 1);
        inp << '\n' << Q << '\n';
        for (maxn i = 0; i < Q; i++) {
            maxn x = MINN + rand() % (n - MINN + 1);
            maxa a = MINA + rand() % (MAXA - MINA + 1);
            inp << x << ' ' << a << '\n';
        }
        
        inp.close();

        system("truyvan.exe");
        system("truyvan_br.exe");
        if (system("fc truyvan.out truyvan.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << ", Q = " << Q <<  '\n';
            return 0;
        }
        std::cout << "Test " << t << " is correct! n = " << n << ", Q = " << Q <<  '\n';
    }
}