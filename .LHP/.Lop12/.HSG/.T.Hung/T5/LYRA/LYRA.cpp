#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 100002
#define le 0
#define ri 1

typedef long maxn;

std::string s[2];
maxn n[2], stp[2][maxN], res;
bool pos[2][maxN];

void Prepare() {
    for(int p = 0; p < 2; p++) std::cin >> s[p], n[p] = s[p].size();
}


void Process() {
    maxn f[2] = { 0,0 };

    for(int p = 0; p < 2; p++) for(maxn i = 0; i < n[p]; i++) {
        if (s[p][i] == '1') ++f[p], pos[p][f[p]] = le;
        if (s[p][i] == '2') ++f[p], pos[p][f[p]] = ri;
        if (s[p][i] == 'L') --stp[p][f[p]];
        if (s[p][i] == 'R') ++stp[p][f[p]];
        if (s[p][i] == 'U') {
            if ((pos[p][f[p]] == le && stp[p][f[p]] < 0) || (pos[p][f[p]] == ri && stp[p][f[p]] > 0)) 
                stp[p][f[p] - 1] += stp[p][f[p]] / 2;
            else
                stp[p][f[p] - 1] += (stp[p][f[p]] + 1) / 2;
            --f[p];
        }
    }

    for(int p = 0; p < 2; p++) for(maxn i = f[p]; i > 0; i--) {
        
    }
}