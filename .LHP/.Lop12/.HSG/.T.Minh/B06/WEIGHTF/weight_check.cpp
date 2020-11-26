#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
#include <time.h>

typedef int maxn, maxw;
typedef long maxa;

const maxa MINC = 1, MAXC = 100000, MINV = 1, MAXV = 2000;
const maxn MIND = 1, MAXD = 100, MINK = 1, MAXK = 100;
const maxw MINW = 100, MAXW = 900;


int main() {
    srand(time(NULL));
    int Test = 1000;

    for(int test = 1; test <= Test; test++) {
        std::ofstream inp("weight.inp");

        maxa C = MINC + rand() % (MAXC - MINC + 1); 
        maxn D = MIND + rand() % (MAXD - MIND + 1);
        maxn K = MINK + rand() % (MAXK - MINK + 1);
        inp << C << ' ' << D << ' ' << K << '\n';

        for(maxa c = 1, i = D; i > 0; c++) {
            bool ok = (c == 1 || (MAXV - c + 1 == i))? 1 : rand() % 2;
            if (!ok) continue;
            --i; 
            maxw w = MINW + rand() % (MAXW - MINW + 1);
            maxw w1 = w / 100, w2 = w % 100;
            inp << c << ' ' << w1 << "."; if (w2 < 10) inp << "0"; inp << w2 << '\n';
            //inp << c << ' ' << w << '\n';
        }
        for(maxn i = 0; i < K; i++) {
            maxn x = 1 + rand() % D;
            inp << x << '\n';
        }

        inp.close();

        system("weightf.exe");
        system("weight_truc.exe");
        if (system("fc weight.out weight_truc.out") != 0) {
            std::cout << "Test " << test << " is wrong! D = " << D << " K = " << K << '\n';
            return 0;
        }
        std::cout << "Test " << test << " is correct! D = " << D << " K = " << K << '\n';
    }
}