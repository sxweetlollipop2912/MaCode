#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#define maxS 201
#define maxN 1001
#define X first
#define Y second

typedef int maxn;
typedef long maxa;
typedef std::pair <maxa, maxa> c_t, p_t;

maxn S, n;
c_t c0;
p_t s[maxS];
std::set <c_t> a;


void Prepare() {
    std::cin >> S >> c0.X >> c0.Y;
    s[0] = p_t(0, 0);
    for(maxn i = 1; i < S; i++) std::cin >> s[i].X >> s[i].Y, s[i].X -= c0.X, s[i].Y -= c0.Y;

    std::cin >> n;
    for(maxn i = 0; i < n; i++) {
        c_t c; std::cin >> c.X >> c.Y;
        a.insert(c);
    }
}


void Process() {
    for(std::set <c_t>::iterator it = a.begin(); it != a.end(); it++) {
        c_t c = *it; maxn i;
        for(i = 1; i < S; i++) {
            if (a.find(c_t(c.X + s[i].X, c.Y + s[i].Y)) == a.end()) break;
        }
        if (i != S) continue;
        std::cout << c.X - c0.X << ' ' << c.Y - c0.Y ; return;
    }
    std::cout << "-1";
}


int main() {
    freopen("stars.inp", "r", stdin);
    freopen("stars.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
