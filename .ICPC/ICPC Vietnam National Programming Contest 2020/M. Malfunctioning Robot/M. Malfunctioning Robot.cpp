// AC, Author: Truc
#include <bits/stdc++.h>
using namespace std;
int test;
long long a1,a2,b1,b2,tmp1,tmp2,d,ans;
int main()
{
    cin>>test;
    while (test--){
        cin>>a1>>b1>>a2>>b2;
        long long  tmp1=a1-a2; if (tmp1<0) tmp1*=-1;
        long long  tmp2=b1-b2; if (tmp2<0) tmp2*=-1;
        if (tmp1<tmp2)swap(tmp1,tmp2);
        ans=tmp2*2;
        tmp1-=tmp2;
        ans+=tmp1/2*4+tmp1%2;
        cout<<ans<<'\n';

    }
    return 0;
}