#include <iostream>
#include <fstream>
#include <cstdio>
#include <time.h>
#include <stdlib.h>

typedef int maxn;
typedef long maxa;

const maxn MINN = 4, MAXN = 11, T = 8;
const maxa MINA = 1, MAXA = 255;


int main() {
    srand(time(NULL));
    int Test = 5000;

    for(int t = 0; t < Test; t++) {
        std::ofstream inp("bracelet1.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        inp << n << ' ';

        for(int i = 0; i < T; i++) {
            maxa a = MINA + rand() % (MAXA - MINA + 1);
            inp << a << ' ';
        }
        inp << '\n';

        for(maxn i = 0; i < n; i++, inp << '\n') for(maxn j = 0; j < T; j++) {
            char c = 'A' + rand() % ('H' - 'A' + 1);
            inp << c;
        }

        inp.close();

        system("bracelet1.exe");
        system("bracelet1_lam.exe");
        if (system("fc bracelet1.out bracelet1_lam.out") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << '\n';
            return 0;
        }
        else 
            std::cout << "Test " << t << " is correct! n = " << n << '\n';
    }
}