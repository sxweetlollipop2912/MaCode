#include <iostream>
#include <algorithm>
#include <string>

#define maxN 100002
#define LAST ((n + 1) / 2)

typedef long maxn;
typedef long long maxa;

const maxa MOD = 1e9 + 7;

std::string s;
maxn n;
maxa K, pw[maxN], res;


void Prepare() {
    std::cin >> n >> K >> s;
    
    pw[0] = 1;
    for(maxn i = 1; i <= n; i++) pw[i] = (pw[i - 1] * K) % MOD;
}


maxa Try(const maxn idx) {
    if (idx == LAST) {
        for(maxn i = LAST; i < n; i++) {
            if (s[i] == s[n - i - 1]) continue;
            return s[i] > s[n - i - 1];
        }
        return 0;
    }
    return ((((s[idx] - 'a') * pw[LAST - idx - 1]) % MOD) + Try(idx + 1)) % MOD;
}


void Process() {
    res = Try(0);
    std::cout << res << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    int t; std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": ";
        Prepare();
        Process();
    }
}