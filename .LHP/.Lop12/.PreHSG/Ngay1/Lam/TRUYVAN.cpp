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
    cnt=1;
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1]) cnt++;
}
void xuly()
{
    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>id>>val;
        if (val==a[id]) {
            cout<<cnt<<'\n';
            continue;
        }
        cnt+=(val!=a[id-1]&&id!=1) + (val!=a[id+1]&&id!=n) - (a[id]!=a[id-1]&&id!=1) - (a[id]!=a[id+1]&&id!=n);
        a[id]=val;
        cout<<cnt<<'\n';
    }
}
int main()
{
    freopen("TRUYVAN.INP","r",stdin);
    freopen("TRUYVAN.OUT","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    nhap();
    xuly();
    return 0;
}
