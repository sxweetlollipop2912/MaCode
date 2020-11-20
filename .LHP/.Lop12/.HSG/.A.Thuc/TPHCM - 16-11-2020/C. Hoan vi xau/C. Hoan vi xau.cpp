// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 1000003

typedef long maxn;
typedef long long maxa;

maxn n, lp[maxN], cntC[27];
maxa MOD, res;
std::string s;
std::vector <maxa> pr;


void Prepare() {
    std::cin >> s >> MOD;
    n = s.size();
}


maxa mul(const maxa a, maxa b) {
    maxa re = 0, c = a % MOD;
    for(; b != 0; b >>= 1) {
        if (b & 1) re = (re + c) % MOD;
        c = (c + c) % MOD;
    }
    return re;
}

maxa pow(const maxa a, maxa p) {
    maxa re = 1, x = a % MOD;
    for(; p != 0; p >>= 1) {
        if (p & 1) re = mul(re, x);
        x = mul(x, x);
    }
    return re;
}


void Era() {
    lp[0] = lp[1] = 1;
    for(maxn i = 2; i <= n; i++) {
        if (!lp[i]) {
            lp[i] = i; pr.push_back(i);
        }
        for(maxn j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * (maxa)i <= (maxa)n; j++) {
            lp[pr[j] * (maxa)i] = pr[j];
        }
    }
}


maxn Legendre(const maxa f, maxa p) {
    maxn re = 0; maxa x = p;
    for(; x <= f; x *= p) re += (maxn)(f / x);
    return re;
}


void Process() {
    for(maxn i = 0; i < s.size(); i++) ++cntC[s[i] - 'a'];

    Era();
    res = 1;
    for(maxn i = 0; i < pr.size(); i++) {
        maxn cntp = Legendre(n, pr[i]);
        for(maxn j = 0; j < 26; j++) cntp -= Legendre(cntC[j], pr[i]);
        if (cntp) res = mul(res, pow(pr[i], cntp));

    }
    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}