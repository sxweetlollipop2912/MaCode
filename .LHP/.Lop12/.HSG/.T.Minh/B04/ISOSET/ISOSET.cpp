#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <string>
#include <map>

#define maxN 52
#define maxD 11

typedef int maxn;
typedef long maxa;
typedef std::string str;

maxa f[maxD];


void Prepare() {
    f[0] = 1;
    for(int i = 1; i <= 9; i++) f[i] = f[i - 1] * i;
}


void Trim(str& s) {
    if (s[0] != '0') return;
    std::reverse(s.begin(), s.end());
    while (s[s.size() - 1] == '0') s.resize(s.size() - 1);
    std::reverse(s.begin(), s.end());
}


maxn Count(str x) {
    std::set <char> set;
    Trim(x);
    for (maxn i = 0; i < x.size(); i++) set.insert(x[i]);
    return set.size();
}


str Map(str x) {
    std::map <char, char> map;
    Trim(x);
    char CNT = '0';
    for(maxn i = 0; i < x.size(); i++) {
        if (map.find(x[i]) == map.end())
            map[x[i]] = CNT++;
        x[i] = map[x[i]];
    }
    return x;
}


void Process() {
    char c;
    while (std::cin >> c) {
        if (c == 'V') {
            str x, y; std::cin >> x >> y;
            //std::cout << Map(x) << ' ' << Map(y) << '\n';
            if (Map(x) == Map(y)) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
        else {
            str x; std::cin >> x;
            maxa re = f[9] / f[9 - Count(x) + 1] * 9;
            if (x.size() == 1) re = 10;
            std::cout << re << '\n';
        }
    }
}


int main() {
    freopen("isoset.inp", "r", stdin);
    freopen("isoset.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
