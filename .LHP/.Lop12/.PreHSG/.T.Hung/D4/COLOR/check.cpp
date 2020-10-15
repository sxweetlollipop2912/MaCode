#include <iostream>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn;

const maxn MINN = 1, MAXN = 1000, MINA = 0, MAXA = 25;

int main() {
    srand(time(NULL));
    int T = 1000;

    for(int t = 0; t < T; t++) {
        std::ofstream inp("color.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        inp << n << '\n';

        for(maxn i = 0; i < n; i++) {
            maxn a = MINA + rand() % (MAXA - MINA + 1);
            inp << (char)(a + 'a');
        }

        inp.close();

        system("color.exe");
        system("color_br.exe");
        if (system("fc color.out color.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n;
            return 0;
        }
        else std::cout << "Test " << t << " is correct! n = " << n << '\n';
    }
}