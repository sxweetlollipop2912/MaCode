#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 17

typedef int maxn;

maxn n, pos[maxN], res;
std::vector <maxn> a;


void Prepare() {
    std::cin >> n;
    a.resize(n + 2);
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
    a[n] = n + 1;
}


int Check(const std::vector <maxn> &a) {
    maxn cnt = a[0] != 1;
    for(maxn i = 1; i < n && cnt <= 2; i++) if (a[i] - a[i - 1] != 1) ++cnt;
    return cnt == 0? 0 : cnt <= 2? 1 : -1;
}


maxn Try(const std::vector <maxn> &A, const maxn step, const maxn lastL,  const maxn lastR, const maxn lastPos) {
    if (lastPos <= lastR) return 5;
    std::vector <maxn> a; maxn idx = 0;
    a.resize(n + 2);
    if (step != 0) {
        for(maxn i = 0; i < lastL; i++, idx++) a[idx] = A[i];
        for(maxn i = lastR + 1; i < lastPos; i++, idx++) a[idx] = A[i];
        for(maxn i = lastL; i <= lastR; i++, idx++) a[idx] = A[i];
        for(maxn i = lastPos; i <= n; i++, idx++) a[idx] = A[i];
    }
    else a = A;

    int check = Check(a);
    if (check != -1) {
        return check;
    }
    if (step == 3) return 5;

    for(maxn i = 0; i < n; i++) pos[a[i]] = i;

    maxn re = 5;
    for(maxn i = 0; i < n; i++) {
        maxn posl = a[i] != 1? pos[a[i] - 1] : -1, posr = a[i] != n? pos[a[i] + 1] : n;

        if (i < posl + 1) {
            re = std::min(re, Try(a, step + 1, i, i, posl + 1) + 1);
            for(maxn ir = i + 1; ir < n; ir++) {
                if (posl < n && a[ir] > a[posl + 1]) continue;
                re = std::min(re, Try(a, step + 1, i, ir, posl + 1) + 1);
            }
        }
        if (i < posr) {
            re = std::min(re, Try(a, step + 1, i, i, posr) + 1);
            for(maxn il = i - 1; il >= 0; il--) {
                if (posr > 0 && a[il] < a[posr - 1]) continue;
                re = std::min(re, Try(a, step + 1, il, i, posr) + 1);
            }
        }
    }

    return re;
}


void Process() {
    res = Try(a, 0, 0, 0, n);
    if (res >= 5) std::cout << "5 or more\n";
    else std::cout << res << '\n';
}


int main() {
    freopen("sort.inp", "r", stdin);
    freopen("sort.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}
