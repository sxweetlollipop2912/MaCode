#include <iostream>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef int maxn;

const maxn MINN = 1, MAXN = 100;


int main() {
    int Test = 1000;
    srand(time(NULL));

    for(int test = 1; test <= Test; test++) {
        std::ofstream inp("rbull.inp");

        maxn m = MINN + rand() % (MAXN - MINN + 1);
        maxn n = MINN + rand() % (MAXN - MINN + 1);
        inp << m << ' ' << n << '\n';

        for(maxn i = 0; i < m; i++, inp << '\n') for(maxn j = 0; j < n; j++) {
            int c = rand() % 4;
            if (c == 0) inp << '*';
            else inp << '.';
        }

        inp.close();

        system("rbull.exe");
        system("rbull_br.exe");

        if (system("fc rbull.out rbull.ans") != 0) {
            std::cout << "Test " << test << " is wrong!";
            return 0;
        }
        std::cout << "Test " << test << " is correct!";
    }
}
