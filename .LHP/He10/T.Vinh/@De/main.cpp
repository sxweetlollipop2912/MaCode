#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
#define maxx 1000
#define MaxInt 9999999
using namespace std;
int c[maxx][maxx],f[maxx][maxx],trace[maxx];
int n,s,t;
void enter()
{
    int m,u,v,tam;
    memset(c,0,sizeof(c));
    cin>>n>>m;
    cin>>s>>t;
    for (int i=1;i<=m;i++){
        cin>>u>>v;
        cin>>tam;
        c[u][v]=tam;
    }
}
bool findpath()
{
    int u;
    queue<int> q;
    memset(trace,0,sizeof(trace));
    q.push(s);
    trace[s]=n+1;  //Trace[v]=- <=> v chua tham
    do {
        u=q.front(); q.pop();
        for (int v=1;v<=n;v++){
            if (trace[v]==0&&c[u][v]>f[u][v]){
                trace[v]=u;
                if (v==t) return true;
                q.push(v);
            }
        }
    }while (!q.empty());
    return 0;
}
void incflow()
{
    int delta,u,v;
    //Tinh delta=ΔP
    delta=MaxInt;
    v=t;
    do{ u=trace[v]; //Xet cung (u,v) tren duong di P, voi u la dinh tham truoc v
        if (c[u][v]-f[u][v]<delta)
            delta=c[u][v]-f[u][v]; //Tim gia tri cf[u,v] nho nhat
        v=u;
    } while (v!=s);
    v=t;
    do{ u=trace[v]; //Xet cung (u,v) tren duong di P, voi u la dinh tham truoc v
        f[u][v]=f[u][v]+delta;
        f[v][u]=f[v][u]-delta;
        v=u;
    } while (v!=s);
}
void printresult()
{
    int m;
    m=0;
    for (int u=1;u<=n;u++)
        for (int v=1;v<=n;v++)
            if (f[u][v]>0){
                cout<<"f["<<u<<", "<<v<<"]="<<f[u][v]<<'\n';
                if (u==s) m=m+f[s][v];
            }
   cout<<"Max flow: "<<m<<'\n';
}
int main()
{
    freopen("MAXFLOW.INP","r",stdin);
    freopen("MAXFLOW.OUT","w",stdout);
    enter();
    memset(f,0,sizeof(f));
    do{
        if (!findpath()) break;
        incflow();
    }while (1);
    printresult();
    return 0;
}
