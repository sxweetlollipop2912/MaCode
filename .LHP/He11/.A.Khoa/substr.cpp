#include <bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
const ll MOD=1e9+7;
const ll base=31;
ll ans,lenA,lenB;
ll ha[maxn],hb[maxn],Pow[maxn];
string a,b;
ll getHash(int l, int r)
{
    return (ha[r]-ha[l-1]*Pow[r-l+1]+MOD*MOD)%MOD; //MOD*MOD để tránh ra số âm dẫn đến lấy dư sai
}
void xuly()
{
    for (int i=1;i<lenA;i++)
        ha[i]=(a[i]-'a'+1+ha[i-1]*base)%MOD;
    for (int i=1;i<lenB;i++)
        hb[i]=(b[i]-'a'+1+hb[i-1]*base)%MOD;
    Pow[0]=1;
    for (int i=1;i<=lenA;i++)
        Pow[i]=(Pow[i-1]*base)%MOD;

    for (int i=1;i<=lenA-lenB+1;i++)
        if (getHash(i,i+lenB-2)==hb[lenB-1]) cout<<i<<' ';
}
int main()
{
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    cin>>a>>b;
    a='0'+a; b='0'+b;
    lenA=a.size();
    lenB=b.size();
    if (lenA>=lenB)
        xuly();
    return 0;
}
