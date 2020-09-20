#include <iostream>
#include <cstdio>

#define maxN 1024
#define maxK 10

int n, k;


int main() {
    freopen("number.inp","r",stdin);
    freopen("number.out","w",stdout);

    std::cin >> n >> k;

    int res = 1;
    for(int i = 0; i < n; i++) res = (res * (2 % k)) % k;
    std::cout << res;
}
