#include <iostream>
#include <algorithm>
#include <cstdio>

#define sum(l, r) ((((l) + (r)) * ((r) - (l) + 1)) / 2)
#define mod9(x) (!((x) % 9)? 9 : (x) % 9)

typedef long long maxa;

maxa L, R, res;


void Prepare() {
    std::cin >> L >> R;
}


maxa sum9(const maxa l, const maxa r) {
    maxa re = 0;
    for(maxa i = l; i <= r; i++) re += mod9(i);
    return re;
}


void Process() {
    res = 0;
    maxa l = L + (10 - mod9(L)), r = R - mod9(R);
    if (l <= r) {
        res = ((r - l + 1) / 9) * 45;
        res += sum(mod9(L), 9) + sum(1, mod9(R));
    }
    else res = sum9(L, R);
    std::cout << res << '\n';
}


int main() {
    freopen("trol.inp","r",stdin);
    freopen("trol.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}
