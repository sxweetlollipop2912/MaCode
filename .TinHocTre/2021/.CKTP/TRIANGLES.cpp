// 30/100
#include <iostream>
#include <algorithm>
#include <math.h>

#define maxN 1501
#define X first
#define Y second
#define len2(p1, p2) ((p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y))
#define abs(x) ((x) >= 0? (x) : -(x))

typedef long maxn;
typedef double maxa;
typedef std::pair <maxa, maxa> p_t;

const maxa eps = 1e-7;

maxn n, res;
p_t p[maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> p[i].X >> p[i].Y;
}


void Process() {
    for(maxn i = 0; i < n; i++) for(maxn j = i + 1; j < n; j++) {
        p_t I = p_t((p[i].X + p[j].X) / 2, (p[i].Y + p[j].Y) / 2);
        maxa R2 = len2(p[i], p[j]) / 4;

        for(maxn k = 0; k < n; k++) {   
            if (k == i || k == j) continue;
            if (abs(len2(I, p[k]) - R2) < eps) {
                ++res;
            }
        }
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    Process();
}