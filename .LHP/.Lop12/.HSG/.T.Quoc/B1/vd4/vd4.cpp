#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1000002

typedef long long maxn;

maxn N, M, lp[maxN], pw[maxN], sum[maxN], res;
std::vector <maxn> pr;


void Prepare() {
    std::cin >> N;
}


void Era() {
    sum[1] = 1;
    for(maxn i = 2; i <= N; i++) {
        if (!lp[i]) {
            lp[i] = i, sum[i] = i + 1, pw[i] = i; pr.push_back(i);
        }
        for(maxn j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * i <= N; j++) {
            maxn x = pr[j] * i;
            lp[x] = pr[j];
            
            if (i % pr[j] == 0) {
                pw[x] = pw[i] * lp[x];
                sum[x] = sum[x / pw[x]] * (pw[x] * lp[x] - 1) / (lp[x] - 1);
            }
            else {
                pw[x] = lp[x];
                sum[x] = sum[i] * (1 + lp[x]);
            }
        }
    }
}


void Process() {
    Era();
    res = 0;
    for(maxn i = 2; i <= N; i++) {
        maxn si = sum[i] - i;
        if (si > N || si <= i) continue;
        
        maxn sj = sum[si] - si;
        if (i == sj) ++res;
    }
    std::cout << res;
}


int main() {
    Prepare();
    Process();
}
