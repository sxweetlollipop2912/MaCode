// 7/7
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <iomanip>

#define abs(x) ((x) < 0? -(x) : (x))
#define next(x) (((x) + 1) % 3)
#define sqr(x) ((x) * (x))

typedef double maxa;

const maxa eps = 1e-9;

struct Point {
    maxa x, y;
    Point(const maxa x = 0, const maxa y = 0) {
        this->x = x, this->y = y;
    }
    Point static sub(const Point a, const Point b) { /// a-b
        return Point(a.x - b.x, a.y - b.y);
    }
    maxa static mul(const Point a, const Point b) {
        return a.x*b.y - a.y*b.x;
    }
    maxa static div(const Point a, const Point x) { /// a/x
        return a.x * x.x + a.y * x.y;
    }
    maxa static dist(const Point a, const Point b) {
        return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }
    bool static equal(const Point p1, const Point p2) {
        return abs(p1.x - p2.x) < eps && abs(p1.y - p2.y) < eps;
    }
};

struct Line {
    maxa a, b, c;

    Line() {}
    Line(const Point A, const Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = -a * A.x - b * A.y;
    }
    maxa dist(const Point p) const { return a * p.x + b * p.y + c; }
};

Point a[3], M, N;


void Prepare() {
    std::cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> M.x >> M.y >> N.x >> N.y;
}


Point Vector(const Point A, const Point B) {
    return Point::sub(B, A);
}


bool Intersect2L(const Line AB, const Line CD, Point &re) { 
    maxa determinant = AB.a * CD.b - CD.a * AB.b; 
  
    if (determinant == 0)
        return 0;

    re.x = (CD.b * (-AB.c) - AB.b * (-CD.c)) / determinant; 
    re.y = (AB.a * (-CD.c) - CD.a * (-AB.c)) / determinant;
    return 1;
}


bool isOverlap(const Line AB, const Line CD) {
    maxa D  =  AB.a *   CD.b  - AB.b *  CD.a;
    maxa Dx = -AB.c *   CD.b  - AB.b * (-CD.c);
    maxa Dy =  AB.a * (-CD.c) - CD.a * (-AB.c);
    return D == 0 && Dx == 0 && Dy == 0;
}


bool PinSeg(const Point M, const Point A, const Point B) {
    Point vAM = Vector(A, M), vMB = Vector(M, B);
    return (abs(Point::mul(vAM, vMB)) < eps && Point::div(vAM, vMB) >= 0) || Point::equal(M, A) || Point::equal(M, B);
}


bool PinTriangle(const Point x, const Point A, const Point B, const Point C) {
    if (PinSeg(x, A, B) || PinSeg(x, A, C) || PinSeg(x, B, C)) return 1;
    Point vAx = Vector(A, x), vAB = Vector(A, B), vAC = Vector(A, C), vBC = Vector(B, C), vBx = Vector(B, x);

    bool x_ab = Point::mul(vAB, vAx) > 0;
    if((Point::mul(vAC, vAx) > 0) == x_ab) return false;
    if((Point::mul(vBC, vBx) > 0) != x_ab) return false;
    return true;
}


maxa Process() {
    Line MN = Line(M, N), AB = Line(a[0], a[1]), BC = Line(a[1], a[2]), CA = Line(a[2], a[0]);

    // trung
    for(int i = 0; i < 3; i++) {
        Point A = a[i], B = a[next(i)];
        if (isOverlap(MN, Line(A, B))) {
            if (PinSeg(N, A, B)) std::swap(M, N);
            if (!PinSeg(M, A, B))
                return Point::dist(A, B);
            if (PinSeg(N, A, B))
                return Point::dist(M, N);
            if (PinSeg(A, M, N))
                return Point::dist(A, M);
            else
                return Point::dist(B, M);
        }
    }

    if (PinTriangle(N, a[0], a[1], a[2])) {
        std::swap(M, N); MN = Line(M, N);
    }

    // MN ben ngoai tg
    if (!PinTriangle(M, a[0], a[1], a[2])) {
        Point p1, p2;
        if (!Intersect2L(MN, AB, p1) && !Intersect2L(MN, BC, p1) && !Intersect2L(MN, CA, p1)) 
            return 0;
        if ((!Intersect2L(MN, CA, p2) || Point::equal(p1, p2)) && (!Intersect2L(MN, BC, p2) || Point::equal(p1, p2)))
            Intersect2L(MN, AB, p2);
        if (!PinSeg(p1, M, N) || !PinSeg(p2, M, N)) 
            return 0;
        return Point::dist(p1, p2);
    }
    // MN ben trong tg
    if (PinTriangle(N, a[0], a[1], a[2]))
        return Point::dist(M, N);
    // M ben trong, N ben ngoai tg
    else {
        Point p1, p2;
        if (!Intersect2L(MN, AB, p1) && !Intersect2L(MN, BC, p1)) Intersect2L(MN, CA, p1);
        if (!Intersect2L(MN, CA, p2) && !Intersect2L(MN, BC, p2)) Intersect2L(MN, AB, p2);
        if (PinSeg(p1, M, N)) return Point::dist(p1, M);
        return Point::dist(p2, M);
    }

    return -1;
}


int main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    
    Prepare();
    std::cout << Process();
}
