#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define eps 1e-15
#define pi 3.14159265358979323846
#define maxx 1000
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> pdd;

struct co2d
{
    ld x,y;
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
bool intersect(co2d a,co2d b,co2d c,co2d d)
{
    return ( (((b-a)*(c-a))*((b-a)*(d-a))<0.0) &&
             (((d-c)*(a-c))*((d-c)*(b-c))<0.0) );
}
ld perimeter(pgon p)
{
    ld pe=0.0;
    p.a[p.n+1]=p.a[1];
    for(int i=1;i<=p.n;i++)
        pe+=len(p.a[i+1]-p.a[i]);
    return pe;
}
ld area(pgon p)
{
    ld s=0.0;
    p.a[p.n+1]=p.a[1];
    for(int i=1;i<=p.n;i++)
        s=s+p.a[i]*p.a[i+1];
    s=abs(s)/2.0;
    return s;
}
void pgon_angle(pgon p,ld *b)
{
    ld s=0;
    p.a[0]=p.a[p.n];
    for(int i=p.n;i>=1;i--)
    {
        p.a[i].x=p.a[i].x-p.a[i-1].x;
        p.a[i].y=p.a[i].y-p.a[i-1].y;
    }
    p.a[p.n+1]=p.a[1];
    for(int i=1;i<=p.n;i++)
    {
        b[i]=diangle(p.a[i],p.a[i+1]);
        s+=b[i];
    }
    if(s>0.0) for(int i=1;i<=p.n;i++) b[i]=pi-b[i];
    else for(int i=1;i<=p.n;i++) b[i]=pi+b[i];
}
pgon p;
ld ans3[50];
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("KVLHP.inp","r",stdin);
    freopen("KVLHP.out","w",stdout);
    cin>>p.n;
    for(int i=1;i<=p.n;i++)
        cin>>p.a[i].x>>p.a[i].y;
    ld ans1=area(p),ans2=perimeter(p);
    cout<<setprecision(0)<<fixed<<ans1<<endl<<ans2<<endl;
    cout<<setprecision(32);
    pgon_angle(p,ans3);
    for(int i=1;i<=p.n;i++)
    {
        ld tmp=radtodeg(ans3[i]);
        cout<<setprecision(0)<<fixed<<tmp<<endl;
        cout<<setprecision(32);
    }
    return 0;
}
