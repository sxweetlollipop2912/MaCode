//C. ABBB
#include <iostream>
#include <algorithm>
#include <string>

#define maxN 200002

typedef long maxn;

maxn n, prev[maxN], res;
std::string s;


void Prepare() {
    std::cin >> s;
    n = s.size();
}


void Process() {
    for(maxn i = 0; i < n; i++) prev[i] = i - 1;

    res = n;
    for(maxn i = 1; i < n; i++) {
        if (prev[i] == -1 || s[i] != 'B') continue;
        prev[i + 1] = prev[prev[i]];
        res -= 2;
        //std::cout << i << ' ' << prev[i] << '\n';
    }

    std::cout << res << '\n';
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