#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

#define maxN (maxn)10003
//#define maxA 1e6
//#define minA -1e6
//#define maxC 1e6
//#define epsilon 0.000000001
#define x first
#define y second
#define d(u, v) (maxa)sqrt((a[u].x - a[v].x) * (a[u].x - a[v].x) + (a[u].y - a[v].y) * (a[u].y - a[v].y))

typedef int maxn;
typedef double maxa;
typedef std::pair <maxa, maxa> co_t;

maxn n, id[maxN];
maxa res;
co_t a[maxN];
std::vector <maxn> point;


bool cmp(const maxn &id1, const maxn &id2) {
    return (a[id1].x < a[id2].x) || (a[id1].x == a[id2].x && a[id1].y < a[id2].y);
}


void Prepare() {
    std::cin >> n;

    for (maxn i = 1; i <= n; i++) {
        std::cin >> a[i].x >> a[i].y;
        id[i] = i;
    }

    point.resize(2 * n);
    std::sort(id + 1, id + n + 1, cmp);
}


bool isValid(const co_t &O, const co_t &A, const co_t &B) { // OA & OB
    return (A.x - O.x)*(B.y - O.y) - (A.y - O.y)*(B.x - O.x) < 0;
}


void Process() {
    maxn len = 0, least = 2;

    for (maxn i = 1; i <= n; i++) {
        if (a[id[i]] == a[id[i - 1]]) continue;
        while (len >= least && !isValid(a[point[len - 2]], a[point[len - 1]], a[id[i]])) len--;
        point[len++] = id[i];
    }

    least = len + 1;
    for (maxn i = n - 1; i >= 1; i--) {
        if (a[id[i]] == a[id[i - 1]]) continue;
        while (len >= least && !isValid(a[point[len - 2]], a[point[len - 1]], a[id[i]])) len--;
        point[len++] = id[i];
    }

    point.resize(std::max(1, len - 1));
    point.push_back(point[0]);

    for(maxn i = 1; i < point.size(); i++)
        res += d(point[i - 1], point[i]);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << res;
}


int main() {
    //freopen("fc.inp", "r", stdin);
    //freopen("fc.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}