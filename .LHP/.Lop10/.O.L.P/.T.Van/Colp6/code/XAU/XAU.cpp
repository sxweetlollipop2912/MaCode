#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 1001
#define maxA 10

typedef int maxn, maxa;
typedef std::string str;

maxn n, len_r, pos_r, par[maxN], len[maxN];
maxn save[maxA];
str s;


void Prepare() {
    std::cin >> s;
    n = s.size();
}


maxa num(char c) {
    return c - '0';
}

void Process() {
    std::fill(par, par + n, -1);
    std::fill(len, len + n, 1);
    std::fill(save, save + maxA, -1);

    len_r = 1;
    pos_r = 0;

    for(maxn i = 0; i < n; i++) {
        for(maxn j = num(s[i]) + 1; j < maxA; j++) {
            if (save[j] == -1 || len[save[j]] + 1 < len[i]) continue;
            len[i] = len[save[j]] + 1;
            par[i] = save[j];
        }

        if (len[i] >= len[save[num(s[i])]]) save[num(s[i])] = i;
        if (len[i] < len_r) continue;

        len_r = len[i];
        pos_r = i;
    }
}


void Trace() {
    str res = "";

    maxn pos = pos_r;
    while (pos != -1) {
        res = s[pos] + res;
        pos = par[pos];
    }

    std::cout << res;
}


int main() {
    freopen("xau.inp","r",stdin);
    freopen("xau.out","w",stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
    Trace();
}
