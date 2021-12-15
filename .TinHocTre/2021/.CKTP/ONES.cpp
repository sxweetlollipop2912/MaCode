// not done
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

#define maxN 100001

typedef long maxn;

maxn n, LEN;
std::vector <std::bitset <maxN> > a;


void Prepare() {
    std::cin >> n >> LEN;
    a.resize(n);

    for(maxn i = 0; i < n; i++) for(maxn j = 0; j < LEN; j++) {
        char c; std::cin >> c;
        a[i][LEN - j - 1] = c == '0'? 0 : 1;
    }
}


void Process() {
    long Q; std::cin >> Q;

    while (Q--) {
        int opt; std::cin >> opt;

        if (opt == 1) {
            maxn idx, bit;
            std::cin >> idx >> bit;
            --idx;
            std::cout << LEN - bit - 1 << ' ' << a[idx][LEN - bit - 1] << '\n';
            a[idx][LEN - bit - 1] = !a[idx][LEN - bit - 1];
        }
        else {
            maxn idx1, idx2;
            std::cin >> idx1 >> idx2;
            --idx1, --idx2;

            std::bitset <maxN> x = a[idx1] ^ a[idx2];
            int i;
            for(i = 0; i < x.size(); i++) {
                if (x[i] == 1) {
                    std::cout << LEN - i - 1 << '\n';
                    break;
                }
            }
            if (i == x.size()) std::cout << x.size() << '\n';
        }
    }
}


int main() {
    Prepare();
    Process();
}