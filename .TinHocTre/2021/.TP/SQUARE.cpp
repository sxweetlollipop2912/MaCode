#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

#define maxA 1000001

typedef long maxa;
typedef long long maxr;

maxa a, b, c;
maxr res;
std::map <maxa, maxa> map1, map2, map3;


void Prepare() {
    std::cin >> a >> b >> c;
}


void Analyze(maxa x, std::map<maxa, maxa> &map) {
    map.clear();
    for(maxa i = 2; x != 1; x /= i) {
        while (x % i != 0) ++i;
        ++map[i];
    }
}


maxr Pow(maxr a, maxr pow) {
    maxr res = 1;
    for(maxr x = a; pow != 0; pow >>= 1) {
        if (pow & 1) res *= x;
        x *= x;
    }
    return res;
}


void Process() {
    Analyze(a, map1); Analyze(b, map2); Analyze(c, map3);

    for(auto i = map2.begin(); i != map2.end(); i++) {
        maxa x = i->first;
        maxa pow = i->second;
        map1[x] = std::max(map1[x], pow);
    }
    for(auto i = map3.begin(); i != map3.end(); i++) {
        maxa x = i->first;
        maxa pow = i->second;
        map1[x] = std::max(map1[x], pow);
    }
    res = 1;
    for(auto i = map1.begin(); i != map1.end(); i++) {
        maxr x = i->first;
        maxr pow = i->second;
        res *= Pow(x, (pow + 1) / 2);
    }

    std::cout << res;
}


int main() {
    Prepare();
    Process();
}