#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define eps 1e-6
#define pi 3.14159265358979323846
#define maxx 3000
using namespace std;

const long double EPS = 1e-6;
typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pdd;

struct co2d
{
    ld x,y;

    bool operator<(const co2d& p) const
    {
        return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
    }
};
struct pgon
{
    int n;
    co2d a[1001];
};
typedef pair<co2d,int> point;
struct set_point
{
    int n;
    point a[1001];
};
class Compare
{
public:
    bool operator()(point a,point b)
    {
        if(a.first.x==b.first.x) return a.first.y<b.first.y;
        else return a.first.x<b.first.x;
    }
};

co2d operator + (co2d const &a,co2d const &b)
{
    co2d t; t.x=a.x+b.x; t.y=a.y+b.y;
    return t;
}
co2d operator - (co2d const &a,co2d const &b)
{
    co2d t; t.x=a.x-b.x; t.y=a.y-b.y;
    return t;
}
ld operator / (co2d const &a,co2d const &b)
{
    return a.x*b.x+a.y*b.y;
}
ld operator * (co2d const &a,co2d const &b)
{
    return a.x*b.y-a.y*b.x;
}
bool eq(ld const &a,ld const &b)
{
    return abs(a-b)<eps;
}
bool operator == (co2d const &a, co2d const &b)
{
    return a.x==b.x && a.y==b.y;
}
ld len(co2d a)
{
    return sqrt(a/a);
}
ld radtodeg(ld a)
{
    return a*180.0/pi;
}
ld degtorad(ld a)
{
    return a*pi/180.0;
}
ld angle(co2d a,co2d b)
{
    return acos((a/b)/len(a)/len(b));
}
ld diangle(co2d a,co2d b)
{
    if(a*b>0.0) return angle(a,b); else return -angle(a,b);
}
bool collinear(co2d a,co2d b,co2d c)
{
    return eq((a-b)*(a-c),0.0); //vec ba, vec ca
}
bool same_sup(co2d a,co2d b)
{
    return eq(a*b,0.0);
}
bool go_str(co2d a,co2d b)
{
    return eq(a*b,0.0)&&a/b>=0;
}
bool go_left(co2d a,co2d b)
{
    return a*b>0.0;
}
bool go_right(co2d a,co2d b)
{
    return a*b<0.0;
}
bool pgo_str(co2d a,co2d b,co2d c)
{
    return go_str(b-a,c-b); // vec ab, vec bc
}
bool pgo_left(co2d a,co2d b,co2d c)
{
    return go_left(b-a,c-b); // vec ab, vec bc
}
bool pgo_right(co2d a,co2d b,co2d c)
{
    return go_right(b-a,c-b); // vec ab, vec bc
}
bool in_seg(co2d m,co2d a,co2d b) //m, line ab
{
    return go_str(m-a,b-m); // vec am, vec mb
}
bool bw_seg(co2d m,co2d a,co2d b)
{
    return pgo_str(a,m,b)&&(m-a)/(m-b)<0.0; //vec am, vec bm
}
bool in_ray(co2d m, co2d a,co2d b)
{
    return go_str(b-a,m-a);
}
bool intersect(co2d a,co2d b,co2d c,co2d d) //wrong
{
    return ( (((b-a)*(c-a))*((b-a)*(d-a))<0.0) &&
             (((d-c)*(a-c))*((d-c)*(b-c))<0.0) );
}

struct line {
    ld a, b, c;

    line() {}
    line(co2d p, co2d q)
    {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
        norm();
    }

    void norm()
    {
        ld z = sqrt(a * a + b * b);
        if (abs(z) > EPS)
            a /= z, b /= z, c /= z;
    }

    ld dist(co2d p) const { return a * p.x + b * p.y + c; }
};

ld det(ld a, ld b, ld c, ld d)
{
    return a * d - b * c;
}

inline bool betw(ld l, ld r, ld x)
{
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(ld a, ld b, ld c, ld d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool intersect(co2d a, co2d b, co2d c, co2d d, co2d& left, co2d& right)
{
    if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
        return false;
    line m(a, b);
    line n(c, d);
    ld zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS) {
        if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS)
            return false;
        if (b < a)
            swap(a, b);
        if (d < c)
            swap(c, d);
        left = max(a, c);
        right = min(b, d);
        return true;
    } else {
        left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
        left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
        return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
               betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
    }
}

int n;
pgon a[1005];
bool check[1005];
co2d r1;
co2d r2;
co2d dir;
ld x,y,w,h;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("BOXES.inp","r",stdin);
    freopen("BOXES.out","w",stdout);
    cin>>n;
    cin>>dir.x>>dir.y;
    r2.x=r1.x+dir.x*maxx;
    r2.y=r1.y+dir.y*maxx;

    for(int i=0;i<n;i++)
    {
        a[i].n=4;
        cin>>x>>y>>w>>h;
        a[i].a[1].x=x;
        a[i].a[1].y=y;

        a[i].a[2].x=x;
        a[i].a[2].y=y+h;

        a[i].a[3].x=x+w;
        a[i].a[3].y=y+h;

        a[i].a[4].x=x+w;
        a[i].a[4].y=y;

        a[i].a[5].x=x;
        a[i].a[5].y=y;
    }

    while(1)
    {
        ld mi=999999999.0;
        co2d idiom;
        co2d next_dir;
        int id=-1;

        for(int i=0;i<n;i++) if(!check[i])
        {
            // corners
            for(int j=1;j<=4;j++) if(in_ray(a[i].a[j],r1,r2) && mi>len(a[i].a[j]-r1))
            {
                id=i;
                mi=len(a[i].a[j]-r1);
                idiom=a[i].a[j];
                next_dir.x=-dir.x;
                next_dir.y=-dir.y;
            }
            // sides
            for(int j=1;j<=4;j++)
            {
                co2d idiom1,idiom2;
                if(!intersect(r1,r2,a[i].a[j],a[i].a[j+1],idiom1,idiom2)) continue;
                if(!eq(idiom1.x,idiom2.x) || !eq(idiom1.y,idiom2.y)) continue;

                if(mi>len(idiom1-r1))
                {
                    id=i;
                    mi=len(idiom1-r1);
                    idiom=idiom1;

                    if(eq(a[i].a[j].x,a[i].a[j+1].x))
                    {
                        next_dir.x=-dir.x;
                        next_dir.y=dir.y;
                    }
                    else
                    {
                        next_dir.x=dir.x;
                        next_dir.y=-dir.y;
                    }
                }
            }
        }
        if(id==-1) break;

        r1=idiom;
        dir=next_dir;
        r2.x=r1.x+dir.x*maxx;
        r2.y=r1.y+dir.y*maxx;

        check[id]=1;
        cout<<id+1<<endl;
    }
    return 0;
}
