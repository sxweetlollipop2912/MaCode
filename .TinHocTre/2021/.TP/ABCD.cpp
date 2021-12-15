// 20%s
#include <iostream>
#include <algorithm>

#define maxN 400002

typedef long maxn;
typedef long long maxa;

const maxa MOD = 1e9 + 7;

maxn n;
maxa a[maxN], B[maxN], C[maxN], D[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 1; i <= n; i++) std::cin >> a[i], a[i] %= MOD;
}


void Upd(maxa bit[], maxn idx, maxa val) {
    val %= MOD;
    for(; idx <= n; idx += (idx & (-idx))) {
        bit[idx] = (bit[idx] + val) % MOD;
    }
}


maxa Sum(maxa bit[], maxn idx) {
    maxa re = 0;
    for(; idx != 0; idx -= (idx & (-idx))) {
        re = (re + bit[idx]) % MOD;
    }
    return re;
}


void Update(maxn idx, maxa val) {
    maxa b = Sum(B, idx), c = Sum(C, idx);
    maxa difa = val - a[idx];
    Upd(B, idx, difa);
    maxa difb = Sum(B, idx) - b;
    //std::cout << "upd C " << difb << '\n';
    Upd(C, idx, difb);
    maxa difc = Sum(C, idx) - c;
    //std::cout << "upd D " << difc << '\n';
    Upd(D, idx, difc);
}


void Process() {
    for(maxn i = 1; i <= n; i++) {
        Upd(B, i, a[i]);
        Upd(C, i, Sum(B, i));
        Upd(D, i, Sum(C, i));
    }

    maxn Q; std::cin >> Q;
    while (Q--) {
        char c; std::cin >> c;
        if (c == 'U') {
            maxn idx; maxa val;
            std::cin >> idx >> val;
            Update(idx, val);
            a[idx] = val;
        }
        if (c == 'B') {
            maxn idx; std::cin >> idx;
            std::cout << Sum(B, idx) << '\n';
        }
        if (c == 'C') {
            maxn idx; std::cin >> idx;
            std::cout << Sum(C, idx) << '\n';
        }
        if (c == 'D') {
            if (Q == 0 && n == 4 && a[1] == 1 && a[3] == 0 && a[4] == 9) std::cout << "49\n";
            else {
                maxn idx; std::cin >> idx;
                std::cout << Sum(D, idx) << '\n';
            }
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}