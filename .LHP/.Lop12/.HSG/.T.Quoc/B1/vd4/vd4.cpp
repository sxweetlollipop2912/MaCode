#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 1000002

typedef long long maxn;

maxn N, M, pw[maxN], sum[maxN], res;
std::vector <maxn> pr;


void Prepare() {
    std::cin >> N;
}


void Era() {
    sum[1] = 1;
    for(maxn i = 2; i <= N; i++) {
        if (!pw[i]) {
            pw[i] = i, sum[i] = i + 1; pr.push_back(i);
        }
        for(maxn j = 0; j < pr.size() && pr[j] * i <= N; j++) {
            maxn x = pr[j] * i;
            
            if (i % pr[j] == 0) {
                pw[x] = pw[i] * pr[j];
                sum[x] = sum[x / pw[x]] * (pw[x] * pr[j] - 1) / (pr[j] - 1);
                break;
            }
            else {
                pw[x] = pr[j];
                sum[x] = sum[i] * (1 + pr[j]);
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
