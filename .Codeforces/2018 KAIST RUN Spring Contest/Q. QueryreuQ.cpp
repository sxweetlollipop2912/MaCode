//Q. QueryreuQ
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define maxN 10002

typedef int maxn;

maxn n, Lcur[maxN], re[maxN], d[maxN], L[maxN], R[maxN], cnt[maxN], res[maxN];
std::string Q;
char a[maxN];


void Prepare() {
    std::cin >> n >> Q;
}


void Init() {
    std::fill(Lcur, Lcur + maxN, 0);
    std::fill(d, d + maxN, 0);
    std::fill(L, L + maxN, 1);
    std::fill(R, R + maxN, 0);
    std::fill(cnt, cnt + maxN, 0);
    std::fill(re, re + maxN, 0);
}


void Update1(const maxn idx, maxn d1[], maxn& L, maxn& R, maxn cnt[], const maxn N) {
    maxn k = (idx > R)? 1 : std::min(d1[L + R - idx], R - idx + 1);
    while (idx - k > 0 && idx + k <= N && a[idx - k] == a[idx + k])
        ++k;
    
    //std::cout << i << ' ' << idx << ' ' << d1[idx] << ' ' << k << '\n';
    if (d1[idx] != k) ++cnt[idx - k + 1];
    d1[idx] = k;
    if (idx + k - 1 > R) {
        L = idx - k + 1;
        R = idx + k - 1;
    }
}


void Update2(const maxn idx, maxn d2[], maxn& L, maxn& R, maxn cnt[], const maxn N) {
    maxn k = (idx > R)? 0 : std::min(d2[L + R - idx + 1], R - idx + 1);
    while (idx - k - 1 > 0 && idx + k <= N && a[idx - k - 1] == a[idx + k])
        ++k;

    if (d2[idx] != k) ++cnt[idx - k - 2];
    d2[idx] = k;
    if (idx + k - 1 > R) {
        L = idx - k - 2;
        R = idx + k - 1;
    }
}


void Process() {
    Init();
    re[0] = 0, Lcur[0] = 1, L[0] = 1, R[0] = 0;

    for(maxn i = 0, N = 0; i < n; i++) {
        if (Q[i] != '-') {
            ++N, a[N] = Q[i];
            Lcur[N] = Lcur[N - 1], L[N] = L[N - 1], R[N] = R[N - 1];

            --Lcur[N];
            do {
                ++Lcur[N];
                Update1(Lcur[N], d, L[N], R[N], cnt, N);
            } while (Lcur[N] + d[Lcur[N]] - 1 != N);

            re[N] = re[N - 1] + cnt[Lcur[N] - d[Lcur[N]] + 1];
        }
        else {
            for(maxn idx = Lcur[N]; idx > Lcur[N - 1]; idx--) {
                --cnt[idx - d[idx] + 1];
                d[idx] = 0;
            }
            --N;
        }
        res[i] = re[N];

        //std::cout << i << ' ' << res[i] << ' ' << N << ' ' << Lcur[N] << '\n';
    }


    Init();
    re[0] = 0, Lcur[0] = 1, L[0] = 1, R[0] = 0;

    for(maxn i = 0, N = 0; i < n; i++) {
        if (Q[i] != '-') {
            ++N, a[N] = Q[i];
            Lcur[N] = Lcur[N - 1], L[N] = L[N - 1], R[N] = R[N - 1];

            --Lcur[N];
            do {
                ++Lcur[N];
                Update2(Lcur[N], d, L[N], R[N], cnt, N);
            } while (Lcur[N] + d[Lcur[N]] - 1 != N);

            if (d[Lcur[N]])
                re[N] = re[N - 1] + cnt[Lcur[N] - d[Lcur[N]] - 2];
        }
        else {
            for(maxn idx = Lcur[N]; idx > Lcur[N - 1]; idx--) {
                if (!d[idx]) continue;
                --cnt[idx - d[idx] - 2];
                d[idx] = 0;
            }
            --N;
        }

        res[i] += re[N];

        //std::cout << i << ' ' << res[i] << ' ' << re[N] << ' ' << N << ' ' << Lcur[N] << '\n';
    }

    for(maxn i = 0; i < n; i++) std::cout << res[i] << ' ';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}