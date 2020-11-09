#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

typedef int maxn;

maxn n, A, res;
std::string s;


void Prepare() {
    std::cin >> s >> A;
    n = s.size();
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) {
        res += (s[i] - 'a' + A) % 26;
    }
    std::cout << res;
}


int main() {
    freopen("password.inp", "r", stdin);
    freopen("password.out", "w", stdout);

    Prepare();
    Process();
}
