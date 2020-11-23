#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>

#define abs(x) ((x) < 0? -(x) : (x))
#define next(x, n) (((x) + 1) % (n))
#define sqr(x) ((x) * (x))
#define maxN 1001

typedef double maxa;
typedef int maxn;

const maxa eps = 1e-9;

struct Point {
    maxa x, y;
    Point(const maxa x = 0, const maxa y = 0) {
        this->x = x, this->y = y;
    }
    Point operator -(const Point &p) const { return Point(x - p.x, y - p.y); }
    bool operator ==(const Point &p) const { return abs(x - p.x) < eps && abs(y - p.y) < eps; }
    maxa static dist(const Point &a, const Point &b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
};

struct Vector {
    maxa x, y;
    Vector(const maxa x = 0, const maxa y = 0) { this->x = x, this->y = y; }
    Vector(const Point &p) { *this = Vector(p.x, p.y); }
    Vector(const Point &A, const Point &B) { *this = Vector(B - A); }

    Vector operator -(const Vector &v) const { return Vector(x - v.x, y - v.y); }
    bool operator ==(const Vector &p) const { 
        return abs(abs(x / p.x) - abs(y / p.y)) < eps && (x < 0) == (p.x < 0) && (y < 0) == (p.y < 0); 
    }
    maxa static dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
    maxa static cross(const Vector &a, const Vector &b) { return a.x*b.y - a.y*b.x; }
    maxa static length(const Vector &a, const Vector &b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
};

struct Line {
    maxa a, b, c;

    Line() {}
    Line(const Point &A, const Point &B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -a * A.x - b * A.y;
    }
    maxa dist(const Point &p) const { return a * p.x + b * p.y + c; }
};


bool PinConvexPolygon(const Point x, const Point points[], const maxn num_points) {
    if (num_points < 3) return 0;
    for(maxn i = 1; i < num_points; i++) {
        Point p0 = points[i - 1], p1 = points[i], p2 = points[next(i, num_points)];
        Vector p0p1 = Vector(p0, p1), p1p2 = Vector(p1, p2), p0x = Vector(p0, x), p1x = Vector(p1, x);
        if ((Vector::cross(p0p1, p0x) <= 0) != (Vector::cross(p1p2, p1x) <= 0)) return 0;
    }
    return 1;
}
//***************************************************************************


maxn np, nq;
Point P[maxN], Q[maxN];


void Prepare() {
    std::cin >> np >> nq;
    for(maxn i = 0; i < np; i++) std::cin >> P[i].x >> P[i].y;
    for(maxn i = 0; i < nq; i++) std::cin >> Q[i].x >> Q[i].y;
}


bool Process() {
    for(maxn i = 0; i < nq; i++)
        if (!PinConvexPolygon(Q[i], P, np)) return 0;
    std::cout << "YES";
    return 1;
}


int main() {
    Prepare();
    if (!Process()) std::cout << "NO";
}