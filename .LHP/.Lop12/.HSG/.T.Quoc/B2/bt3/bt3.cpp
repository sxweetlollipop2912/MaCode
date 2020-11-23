#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>

#define abs(x) ((x) < 0? -(x) : (x))
#define next(x, n) (((x) + 1) % (n))
#define prev(x, n) (((x) + (n) - 1) % (n))
#define sqr(x) ((x) * (x))
#define maxN 2001

typedef double maxa;
typedef int maxn;

const maxa eps = 1e-9, INF = 9999999999999999;

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


bool Intersect2Line(const Line AB, const Line CD, Point &re) { 
    maxa determinant = AB.a * CD.b - CD.a * AB.b; 
    if (determinant == 0)
        return 0;
    re.x = (CD.b * (-AB.c) - AB.b * (-CD.c)) / determinant; 
    re.y = (AB.a * (-CD.c) - CD.a * (-AB.c)) / determinant;
    return 1;
}


bool PinSeg(const Point M, const Point A, const Point B) {
    Vector vAM = Vector(A, M), vMB = Vector(M, B);
    return (abs(Vector::cross(vAM, vMB)) < eps && Vector::dot(vAM, vMB) >= 0) || M == A || M == B;
}


bool Intersect2Seg(const Point A, const Point B, const Point C, const Point D, Point &re) {
    Point intersect;
    if (!Intersect2Line(Line(A, B), Line(C, D), intersect)) return 0;
    if (!PinSeg(intersect, A, B) || !PinSeg(intersect, C, D)) return 0;
    re = intersect; return 1;
}


bool PinConvexPolygon(const Point x, const Point points[], const maxn num_points) {
    if (num_points < 3) return 0;
    for(maxn i = 1; i < num_points; i++) {
        Point p0 = points[i - 1], p1 = points[i], p2 = points[next(i, num_points)];
        Vector p0p1 = Vector(p0, p1), p1p2 = Vector(p1, p2), p0x = Vector(p0, x), p1x = Vector(p1, x);
        if ((Vector::cross(p0p1, p0x) <= 0) != (Vector::cross(p1p2, p1x) <= 0)) return 0;
    }
    return 1;
}


bool PolyinConvexPolygon(const Point Q[], const maxn num_q, const Point P[], const maxn num_p) {
    for(maxn i = 0; i < num_q; i++)
        if (!PinConvexPolygon(Q[i], P, num_p)) return 0;
    return 1;
}


maxa AreaPolygon(const Point points[], const maxn num_points) {
    if (num_points < 3) return 0;
    maxa re = 0;
    for(maxn i = 0; i < num_points; i++) {
        Point p1 = points[i], p2 = points[next(i, num_points)];
        re += Vector::cross(Vector(p1), Vector(p2));
    }
    return abs(re) / (maxa)2;
}
//***************************************************************************


maxn np, nq, na;
Point P[maxN], Q[maxN], A[maxN];


void Prepare() {
    std::cin >> np >> nq;
    for(maxn i = 0; i < np; i++) std::cin >> P[i].x >> P[i].y, P[i + np] = P[i];
    for(maxn i = 0; i < nq; i++) std::cin >> Q[i].x >> Q[i].y, Q[i + nq] = Q[i];
}


maxa Process() {
    // P chua Q || Q chua P
    if (PolyinConvexPolygon(P, np, Q, nq)) return AreaPolygon(P, np);
    if (PolyinConvexPolygon(Q, nq, P, np)) return AreaPolygon(Q, nq);

    maxn fp = 2 * np, lp = 0, fq = 2 * nq, lq = 0;
    Point p;

    // cac dinh tu fp den lp cua P trong Q && nguoc lai
    for(maxn i = 0; i < 2 * np; i++) {
        if (!PinConvexPolygon(P[i], Q, nq)) continue;
        if (i == 0 || !PinConvexPolygon(P[i - 1], Q, nq)) fp = lp = i;
        else fp = std::min(fp, i), lp = std::max(lp, i);
    }
    for(maxn i = 0; i < 2 * nq; i++) {
        if (!PinConvexPolygon(Q[i], P, np)) continue;
        if (i == 0 || !PinConvexPolygon(Q[i - 1], P, np)) fq = lq = i;
        else fq = std::min(fq, i), lq = std::max(lq, i);
    }
    if (fp == 2 * np && fq == 2 * nq) return 0;

    // cac dinh moi tao ra khi P va Q cat nhau
    for(maxn i = fp; i <= lp; i++) A[na++] = P[i];
    if (fp != 2 * np && fq != 2 * nq && Intersect2Seg(P[lp], P[next(lp, 2 * np)], Q[prev(fq, nq * 2)], Q[fq], p)) A[na++] = p;
    for(maxn i = fq; i <= lq; i++) A[na++] = Q[i];
    if (fp != 2 * np && fq != 2 * nq && Intersect2Seg(Q[lq], Q[next(lq, 2 * nq)], P[prev(fp, np * 2)], P[fp], p)) A[na++] = p;

    if (fp == 2 * np) {
        for(maxn i = 0; i < np; i++) {
            Point p1 = P[i], p2 = P[next(i, np)], first_p, last_p;
            if (!Intersect2Seg(Q[lq], Q[next(lq, 2 * nq)], p1, p2, last_p) || 
                !Intersect2Seg(Q[fq], Q[prev(fq, 2 * nq)], p1, p2, first_p))
                continue;
            A[na++] = last_p, A[na++] = first_p; break;
        }
    }
    if (fq == 2 * nq) {
        for(maxn i = 0; i < nq; i++) {
            Point p1 = Q[i], p2 = Q[next(i, nq)], first_p, last_p;
            if (!Intersect2Seg(P[lp], P[next(lp, 2 * np)], p1, p2, last_p) || 
                !Intersect2Seg(P[fp], P[prev(fp, 2 * np)], p1, p2, first_p))
                continue;
            A[na++] = last_p, A[na++] = first_p; break;
        }
    }

    // kq
    na = std::unique(A, A + na) - A;
    return AreaPolygon(A, na);
}


int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    
    Prepare();
    std::cout << Process();
}