#include <iostream>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef int maxn;

const maxn MINN = 1, MAXN = 15, MINT = 1, MAXT = 100;


int main() {
    srand(time(NULL));
    int T = 1000;

    for(int t = 1; t <= T; t++) {
        std::ofstream inp("bseq.inp");
        
        maxn Test = MINT + rand() % (MAXT - MINT + 1);
        
        for(maxn test = 0; test < Test; test++) {
            maxn n = MINN + rand() % (MAXN - MINN + 1);
            inp << n << '\n';

            for(maxn i = 0; i < n; i++) {
                int question = rand() % 3;

                if(question) {
                    inp << "?\n";
                    continue;
                }

                for(char c = 'A'; c <= 'Z'; c++) {
                    int pick = rand() % 4;
                    if (!pick) inp << c;
                }
                inp << '\n';
            }
        }
        inp << "0";

        inp.close();

        system("bseq.exe");
        system("bseq1.exe");
        if (system("fc bseq.out bseq1.out") != 0) {
            std::cout << "Test " << t << " is wrong! subtest = " << Test;
            return 0;
        }
        std::cout << "Test " << t << " is correct! subtest = " << Test << '\n';
    }
}