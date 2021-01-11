#include <iostream>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
#include <time.h>

typedef long maxn;

const maxn MINN = 1, MAXN = 100000, MINK = 0, MAXK = 1000000000, MINA = 1, MAXA = 1000000000;


int main() {
    srand(time(NULL));
    int Test = 1000000, CNT = 0;

    for(int test = 1; test <= Test; test++) {
        std::ofstream inp("nhanpham.inp");

        maxn n = MINN + rand() % (MAXN - MINN + 1);
        maxn k = MINK + rand() % (MAXK - MINK + 1);
        inp << n << ' ' << k << '\n';

        for(maxn i = 0; i < n - 1; i++) {
            maxn a = MINA + rand() % (MAXA - MINA + 1);
            inp << a << ' ';
        }
        inp << MAXA / 2 << ' ';

        inp.close();

        std::cout << "TESTS WRONG: " << CNT << '\n';
        std::cout << "RUNNING nhanpham_br\n";
        system("nhanpham_br.exe");
        std::cout << "RUNNING nhanpham\n";
        system("nhanpham.exe");

        if (system("fc nhanpham.out nhanpham.ans") != 0) {
            std::cout << "Test " << test << " is wrong! n = " << n << " k = " << k << '\n';
            ++CNT;
        }
        else std::cout << "Test " << test << " is correct! n = " << n << " k = " << k << '\n';
    }
}
