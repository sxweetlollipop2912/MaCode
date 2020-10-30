//Q. QueryreuQ
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define maxN 10002

typedef int maxn;

maxn n, Lcur[2][maxN], res[maxN], d[2][maxN], L[2][maxN], R[2][maxN], cnt[2][maxN];
std::string Q;
char a[maxN];


void Prepare() {
    std::cin >> n >> Q;
}


void Update1(const maxn idx, maxn d1[], maxn R1[], maxn L1[], const maxn l1, const maxn r1, maxn cnt1[], const maxn N) {
    maxn k = (idx > r1)? 1 : std::min(d1[r1 - idx + l1], r1 - idx + 1);
    while (idx - k >= 0 && idx + k < N && a[idx - k] == a[idx + k])
        ++k;
    
    //std::cout << i << ' ' << idx << ' ' << d1[idx] << ' ' << k << '\n';
    if (d1[idx] != k) ++cnt1[idx - k + 1];
    d1[idx] = k;
    if (idx + k - 1 > r1) {
        R1[N - 1] = idx + k - 1;
        L1[N - 1] = idx - k + 1;
    }
}


void Update2(const maxn idx, maxn d2[], maxn R2[], maxn L2[], const maxn l2, const maxn r2, maxn cnt2[], const maxn N) {
    maxn k = (idx > r2)? 0 : std::min(d2[r2 - idx + l2 + 1], r2 - idx + 1);
    while (idx - k - 1 >= 0 && idx + k < N && a[idx - k - 1] == a[idx + k])
        ++k;

    if (d2[idx] != k) ++cnt2[idx - k - 2];
    d2[idx] = k;
    if (idx + k - 1 > r2) {
        R2[N - 1] = idx + k - 1;
        L2[N - 1] = idx - k - 2;
    }
}


void Process() {
    for (maxn i = 0, N = 0; i < n; i++) {
        if (Q[i] == '-') {
            --N;
            for(maxn idx = Lcur[1][N]; idx >= Lcur[1][N - 1]; idx--) {
                --cnt[1][idx - d[1][idx] + 1];
                d[1][idx] = 0;
            }
            for(maxn idx = Lcur[2][N]; idx >= Lcur[2][N - 1]; idx--) {
                if (d[2][idx]) 
                    --cnt[2][idx - d[2][idx] - 2];
                d[2][idx] = 0;
            }

            --N;
            for(int p = 0; p <= 1; p++) {
                L[p][N] = !N? 0 : L[p][N - 1], R[p][N] = !N? -1 : R[p][N - 1];
                if (p)
                    Update1(Lcur[p][N], d[p], R[p], L[p], L[p][N], R[p][N], cnt[p], N + 1);
                else
                    Update2(Lcur[p][N], d[p], R[p], L[p], L[p][N], R[p][N], cnt[p], N + 1);
            }
        }

        else {
            a[N] = Q[i];

            for(int p = 0; p <= 1; p++) {
                Lcur[p][N] = !N? 0 : Lcur[p][N - 1];
                L[p][N] = !N? 0 : L[p][N - 1], R[p][N] = !N? -1 : R[p][N - 1];
                --Lcur[p][N];

                do {
                    ++Lcur[p][N];
                    if (p)
                        Update1(Lcur[p][N], d[p], R[p], L[p], L[p][N], R[p][N], cnt[p], N + 1);
                    else
                        Update2(Lcur[p][N], d[p], R[p], L[p], L[p][N], R[p][N], cnt[p], N + 1);
                } while (Lcur[p][N] + d[p][Lcur[p][N]] - 1 != N);
            }

            res[N] = res[N - 1] + cnt[1][Lcur[1][N] - d[1][Lcur[1][N]] + 1];
            if (d[2][Lcur[2][N]]) res[N] += cnt[2][Lcur[2][N] - d[2][Lcur[2][N]] - 2];
        }
        ++N;
        //std::cout << cnt[0] << '\n';
        //std::cout << Lcur[N - 1] - d1[Lcur[N - 1]] + 1 << ' ' << cnt[Lcur[N - 1] - d1[Lcur[N - 1]] + 1] << '\n';
        //std::cout << i << ' ' << Q[i] << ' ' << N << ' ' << Lcur[N - 1] << ' ' << res[N - 1] << '\n';
        std::cout << res[N - 1] << ' ';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}