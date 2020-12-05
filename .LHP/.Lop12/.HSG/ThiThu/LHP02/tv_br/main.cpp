#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>

#define maxN 7003
#define dumm ('-')

typedef long maxn;
typedef std::string str;

maxn n, N, K, res;
str s[maxN];


void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0; i < n; i++) std::cin >> s[i];
}


maxn Count(const str &x) {
    //std::cout << x << '\n';
    maxn cnt = 0;
    for(maxn i = 0; i < n; i++) for(maxn l = 0; l <= (maxn)s[i].size() - (maxn)x.size(); l++)
        if (s[i].substr(l, x.size()) == x) {
            ++cnt; break;
        }
    return cnt;
}


void Process() {
    res = 0;
    for(maxn i = 0; i < n; i++) for(maxn l = 0; l < s[i].size(); l++) for(maxn r = l; r < s[i].size(); r++)
        if (Count(s[i].substr(l, r - l + 1)) >= K) res = std::max(res, r - l + 1);//, std::cout << res << '\n';
    std::cout << res;
}


int main() {
    freopen("tv.inp", "r", stdin);
    freopen("tv.ans", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
