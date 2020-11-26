// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>

#define maxN 1001
#define sqr(x) ((x) * (x))

typedef int maxn;
typedef long long maxa;

struct Point {
    maxa x, y, z;
    Point(const maxa x = 0, const maxa y = 0, const maxa z = 0) {
        this->x = x, this->y = y, this->z = z;
    }
    maxa static div(const Point a, const Point x) {
        return a.x * x.x + a.y * x.y + a.z * x.z;
    }
};

maxn P, n;
Point p[maxN], a[maxN];
maxa D, R[maxN], v[maxN], res;


void Prepare() {
    std::cin >> P;
    for(maxn i = 0; i < P; i++) std::cin >> p[i].x >> p[i].y >> p[i].z >> v[i] >> R[i];

    std::cin >> n;
    a[0].x = a[0].y = a[0].z = 0;
    ++n;
    for(maxn i = 1; i < n; i++) std::cin >> a[i].x >> a[i].y >> a[i].z;

    std::cin >> D;
}


Point vecto(const Point u, const Point v) {
    return Point(v.x - u.x, v.y - u.y, v.z - u.z);
}
maxa Len2_Vecto(const Point v) {
    return sqr(v.x) + sqr(v.y) + sqr(v.z);
}
maxa Dist2_P2P(const Point A, const Point B) {
    return sqr(A.x - B.x) + sqr(A.y - B.y) + sqr(A.z - B.z);
}


maxa Dist2_P2Line(const Point a, const Point A, const Point B) {
    Point vAB = vecto(A, B), vAa = vecto(A, a);
    Point vmul;
    vmul.x = vAB.y * vAa.z - vAB.z * vAa.y;
    vmul.y = vAB.z * vAa.x - vAB.x * vAa.z;
    vmul.z = vAB.x * vAa.y - vAB.y * vAa.x;
    return ceil(Len2_Vecto(vmul) / (double)Len2_Vecto(vAB));
}


maxa Dist2_P2Seg(const Point a, const Point A, const Point B) {
    if (Point::div(vecto(A, a), vecto(A, B)) < 0) return Dist2_P2P(A, a);
    if (Point::div(vecto(B, a), vecto(B, A)) < 0) return Dist2_P2P(B, a);
    return Dist2_P2Line(a, A, B);
}


void Process() {
    res = 0;
    for(maxn i = 1; i < n; i++) for(maxn ip = 0; ip < P; ip++) {
        if (Dist2_P2Seg(p[ip], a[i - 1], a[i]) > sqr(R[ip] + D)) continue;
        res += v[ip], v[ip] = 0;
    }
    std::cout << res;
}


int main() {
    freopen("space.inp", "r", stdin);
    freopen("space.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
