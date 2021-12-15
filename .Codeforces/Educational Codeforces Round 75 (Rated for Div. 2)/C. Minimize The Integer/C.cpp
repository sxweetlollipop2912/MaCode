// AC
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 300002
#define mod(c) (((c) - '0') % 2)

typedef long maxn;
typedef std::string str;

int n;
str x;
bool del[maxN];


void Prepare() {
    std::cin >> x;
    n = x.size();
}


void Process() {
    std::fill(del, del + n, 0);

    for(int p1 = 0, p2 = 0; p1 != n; p1++, p2 = std::max(p2, p1)) {
        if (del[p1]) continue;

        do {
            while (p2 != n && (del[p2] || mod(x[p2]) == mod(x[p1]))) ++p2;

            while (p2 != n && (del[p2] || (mod(x[p2]) != mod(x[p1]) && x[p2] < x[p1]))) {
                if (!del[p2]) {
                    std::cout << x[p2];
                    del[p2] = 1;
                }
                ++p2;
            }
        } while (p2 != n && mod(x[p2]) == mod(x[p1]));

        std::cout << x[p1];
    }

    std::cout << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}