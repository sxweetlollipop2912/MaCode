#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define maxN 501
#define X first
#define Y second
#define d(x, y) ((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y))

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n, P;
p_t a[maxN];


void Prepare() {
    std::cin >> n >> P;
}
