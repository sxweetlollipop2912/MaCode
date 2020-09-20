#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#define maxn 105
#define fi first
#define se second
using namespace std;
const int oo=1000001100;
typedef pair<int,int> pii;
typedef pair<int,pii> tii;
int n,m,p,l,t,q;
int si,sj,keyi,keyj,dami,damj,cami,camj,hoi,hoj;
int d[maxn][maxn];
char a[maxn][maxn];
int td[]={-1,0,0,1};
int tc[]={0,-1,1,0};
void nhap()
{
    cin>>n>>m>>p>>l>>t>>q; //chia khoa - dam lay - cam bay - ho sau
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            if (a[i][j]=='S') si=i, sj=j;
            if (a[i][j]=='K') keyi=i,keyj=j;
            if (a[i][j]=='D') dami=i,damj=j;
            if (a[i][j]=='C') cami=i,camj=j;
            if (a[i][j]=='H') hoi=i,hoj=j;
        }
}


int TG(pii v)
{
    if (a[v.fi][v.se]=='K') return 1+p;
    if (a[v.fi][v.se]=='D') return 1+l;
    if (a[v.fi][v.se]=='C') return 1+t;
    if (a[v.fi][v.se]=='H') return 1+q;
    return 1;
}
bool check(pii v)
{
    if (v.fi>=1&&v.fi<=n&&v.se>=1&&v.se<=m) return 1;
    return 0;
}
void dijkstrakey(){
    priority_queue <tii, vector<tii>, greater<tii> > pq;
    int du;
    pii u,v;
    for (int i=1; i<=n; i++)
        for (int j=1;j<=m;j++)
            d[i][j] = oo;
    d[si][sj] = 0;
    pq.push(tii(0, pii(si,sj)));

    while (!pq.empty()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();

        if (du!=d[u.fi][u.se]) continue;
        if (a[u.fi][u.se]=='K') return;
        for (int i=0;i<4;i++){
            v.fi=u.fi+td[i];
            v.se=u.se+tc[i];
            if (check(v)){
                if (a[v.fi][v.se]!='#'&&d[v.fi][v.se]>du+TG(v)){
                    d[v.fi][v.se]=du+TG(v);
                    pq.push(tii(d[v.fi][v.se],v));
                }
            }
        }
    }
    d[keyi][keyj]=-1;
}
bool OUT(pii v)
{
    if (v.fi==1||v.fi==n||v.se==1||v.se==m) return 1;
    return 0;
}
int dijkstraout(){
    priority_queue <tii, vector<tii>, greater<tii> > pq;
    int du;
    pii u,v;
    for (int i=1; i<=n; i++)
        for (int j=1;j<=m;j++)
            d[i][j] = oo;
    d[keyi][keyj] = 0;
    pq.push(tii(0, pii(keyi,keyj)));

    while (!pq.empty()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();

        if (du!=d[u.fi][u.se]) continue;
        if (OUT(u)) return du+5;
        for (int i=0;i<4;i++){
            v.fi=u.fi+td[i];
            v.se=u.se+tc[i];
            if (check(v)){
                if (a[v.fi][v.se]!='#'&&d[v.fi][v.se]>du+TG(v)){
                    d[v.fi][v.se]=du+TG(v);
                    pq.push(tii(d[v.fi][v.se],v));
                }
            }
        }
    }
    return -1;
}
int main()
{
    freopen("RUN.INP","r",stdin);
    freopen("RUN.OUT","w",stdout);
    nhap();
    dijkstrakey();
    int timeKey=d[keyi][keyj];
    if (timeKey==-1) cout<<"-1\n";
    else {
        int tmp=dijkstraout();
        if (tmp!=-1) cout<<timeKey+tmp;
        //cout<<tmp;
    }
    return 0;
}
