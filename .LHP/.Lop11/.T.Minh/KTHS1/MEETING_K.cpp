#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue>
#define pb push_back
#define be(a) a.begin()
#define en(a) a.end()
#define iter vector<int>::iterator
#define fort(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int maxn=1e3;
int
    n,m,s,t,N,
    cap[maxn][maxn],
    trace[maxn],
    f,ans,
    A[maxn],B[maxn];
vector<int>
    ke[maxn];

void add(int u,int v,int c=1)
{
    ke[u].pb(v);
    ke[v].pb(u);
    cap[u][v]=c;
}
void Input()
{
    int j; string ss;
    scanf("%d%d",&m,&n);
    s=2*(n+m)+1; t=s+1;
    fort(i,1,m) add(i,m+i);
    cin.ignore();
    fort(i,1,n)
    {
        add(s,m+m+i);
        getline(cin,ss);
        stringstream f(ss);
        while (!f.eof())
        {
            f>>j;
            add(m+m+i,j);
        }
    }
    fort(i,1,n)
    {
        add(m+m+n+i,t);
        getline(cin,ss);
        stringstream f(ss);
        while (!f.eof())
        {
            f>>j;
            add(m+j,m+m+n+i);
        }
    }
    N=n;
    n=t;
}
bool FindP()
{
    fort(i,1,n) trace[i]=0;
    trace[s]=n+1;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(iter v=be(ke[u]); v!=en(ke[u]) ; ++v)
            if (trace[*v]==0 && cap[u][*v]>0)
        {
            trace[*v]=u;
            if (*v==t) return true;
            Q.push(*v);
        }
    }
    return false;
}
void IncF(int t,int mf)
{
    if (t==s) {f=mf; ans+=mf; return;}
    IncF(trace[t],min(mf,cap[trace[t]][t]));
    cap[trace[t]][t]-=f;
    cap[t][trace[t]]+=f;
}
void Solve()
{
    while (FindP()) IncF(t,5);
    if (ans==N){
        fort(i,1,m) {
            fort(j,1,N){
                if (cap[i][m+m+j]==1)
                    A[i]=j;
                if (cap[m+m+N+j][m+i]==1)
                    B[i]=j;
            }
        }
        fort(i,1,m) if (A[i]!=0)
            printf("%d %d %d\n",i,A[i],B[i]);
    } else printf("-1");
}
int main()
{
    freopen("MEETING.inp","r",stdin);
    freopen("MEETING.out","w",stdout);
    Input();
    Solve();
}
