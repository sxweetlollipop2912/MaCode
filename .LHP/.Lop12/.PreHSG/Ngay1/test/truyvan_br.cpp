#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <cmath>
#define maxn 100005
using namespace std;
int n,m,cnt,val,id,a[maxn];
void nhap()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
int COUNT()
{
    cnt=1;
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1]) cnt++;
    return cnt;
}
void xuly()
{
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>id>>val;
        a[id]=val;
        cout<<COUNT()<<'\n';
    }
}
int main()
{
    freopen("TRUYVAN.INP","r",stdin);
    freopen("TRUYVAN.ans","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    nhap();
    xuly();
    return 0;
}
