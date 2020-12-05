#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
#include <time.h>

typedef long maxn;

const maxn MINN = 1, MAXN = 100, MINL = 1, MAXL = 39;


int main() {
    srand(time(NULL));
    int Test = 1000;

    for(int test = 1; test <= Test; test++) {
        std::ofstream inp("tv.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn k = 1 + rand() % (n - 1 + 1);
        inp << n << ' ' << k << '\n';

        for(maxn i = 0; i < n; i++) {
            maxn sz = MINL + rand() % (MAXL - MINL + 1);
            for(maxn j = 0; j < sz; j++) {
                char c = 'A' + rand() % ('F' - 'A' + 1);
                inp << c;
            }
            inp << '\n';
        }

        inp.close();

        system("tv.exe");
        system("tv_br.exe");

        if (system("fc tv.out tv.ans") != 0) {
            std::cout << "Test " << test << " is wrong!";
            return 0;
        }
        std::cout << "Test " << test << " is correcrt!\n";
    }
}
