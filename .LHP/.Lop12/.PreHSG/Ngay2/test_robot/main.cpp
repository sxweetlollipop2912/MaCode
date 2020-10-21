#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <time.h>
#include <stdlib.h>

typedef long maxn, maxa;

const maxn MINN = 1, MAXN = 100, MINK = 1, MAXK = 10;


char f[3] = { 'F','L','R' }, map[2] = { '.','#' };


int main() {
    srand(time(NULL));

    int T = 1000;
    for(int t = 0; t < T; t++) {
        std::ofstream inp("robot.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn m = MINN + rand() % (MAXN - MINN + 1);
        maxn K = MINK + rand() % (MAXK - MINK + 1);
        inp << m << ' ' << n << ' ' << K << '\n';

        maxn enx = rand() % (m - 1 + 1);
        maxn eny = rand() % (n - 1 + 1);

        maxn CNT = 1;
        for(maxn i = 0; i < m; i++, inp << '\n') for(maxn j = 0; j < n; j++) {
            if (i == enx && j == eny) inp << 'E';
            else {
                int a = rand() % 2;
                inp << map[a];
                CNT += (map[a] != '#');
            }
        }
        for(maxn i = 0; i < K; i++) {
            int a = rand() % 3;
            inp << f[a];
        }

        inp.close();


        system("robot.exe");

        std::ifstream out("robot.out");
        maxn res;
        out >> res;
        out.close();

        if (CNT < res) {
            std::cout << "Test " << t << " is wrong! n = " << n << " m = " << m << " K = " << K << '\n' << CNT << ' ' << res << '\n';
            return 0;
        }
        else
            std::cout << "Test " << t << " is correct! n = " << n << " m = " << m << " K = " << K << '\n' << CNT << ' ' << res << '\n';
    }
}
