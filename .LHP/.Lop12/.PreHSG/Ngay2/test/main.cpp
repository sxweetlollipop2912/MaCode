#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn;

const maxn MINN = 1, MAXN = 200000;


int main() {
    srand(time(NULL));

    int T = 1000;
    for(int t = 0; t < T; t++) {
        std::ofstream inp("name.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        inp << n << '\n';

        inp.close();

        system("name.exe");
        system("name_br.exe");
        if (system("fc name.out name.ans") != 0) {
            std::cout << "Test " << t << " is wrong! n = " << n << '\n';
            return 0;
        }
        else
            std::cout << "Test " << t << " is correct! n = " << n << '\n';
    }
}
