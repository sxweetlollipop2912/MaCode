#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

#define maxN 100002
#define C 26
#define Sum(l, r, c) (sum[c][r + 1] - sum[c][l])

typedef long maxn;
typedef std::string str;

str s;
maxn n, Q, lq[maxN], rq[maxN], sum[C][maxN];
std::map <maxn, maxn> del;


void Prepare() {
    std::cin >> s >> Q;
    n = s.size();

    for(maxn q = 0; q < Q; q++) std::cin >> lq[q] >> rq[q], --lq[q], --rq[q];

    for(maxn i = 0; i < n; i++) {
        maxn idx; std::cin >> idx;
        --idx, del[idx] = i + 1;
    }
}


bool Check(const maxn step) {
    for(maxn i = 0; i < C; i++) std::fill(sum[i], sum[i] + maxN, 0);

    for(maxn i = 0; i < n; i++) 
        if (del[i] > step) ++sum[s[i] - 'a'][i + 1];
    for(maxn i = 1; i <= n; i++) for(maxn c = 0; c < C; c++)
        sum[c][i] += sum[c][i - 1];

    for(maxn q = 0; q < Q; q++) for(maxn c = 0; c < C; c++)
        if (Sum(lq[q], rq[q], c) > 1) return 0;

    return 1;
}


void Process() {
    maxn l = 0, r = n;
    while (l != r) {
        maxn m = (l + r) / 2;
        if (Check(m)) r = m;
        else l = m + 1;
    }
    std::cout << l;
}


int main() {
    freopen("p-word.inp", "r", stdin);
    freopen("p-word.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}