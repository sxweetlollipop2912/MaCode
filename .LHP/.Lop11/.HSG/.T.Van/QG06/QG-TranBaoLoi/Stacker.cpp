#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
const int N=220111;
int n,m;
int a[N],s[N],dp[N],op[N];/// dp la ng di trc,op ng di sau
int main(){
    freopen("Stacker.inp","r",stdin);
    freopen("Stacker.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=n;i>0;--i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
        s[i]=a[i]+s[i-1];
    deque<int> q1,q2;
    q1.push_back(0);
    q2.push_back(0);
    for (int i=1;i<=n;++i){
        while(!q1.empty()&&q1.front()<i-m) q1.pop_front();
        while(!q2.empty()&&q2.front()<i-m) q2.pop_front();
        //cerr<<q1.front()<<' '<<q2.front()<<endl;
        dp[i]=s[i]-s[q1.front()]-op[q1.front()];
        op[i]=s[i]-s[q2.front()]-dp[q2.front()];
        //cerr<<i<<' '<<dp[i]<<' '<<op[i]<<endl;
        //cerr<<"ANS  "<<(s[i]+dp[i])/2<<' '<<(s[i]-op[i])/2<<endl;
        while(!q1.empty()&&op[q1.back()]-s[i]+s[q1.back()]>=op[i]) q1.pop_back();
        q1.push_back(i);
        while(!q2.empty()&&dp[q2.back()]-s[i]+s[q2.back()]>=dp[i]) q2.pop_back();
        q2.push_back(i);
    }
    printf("%d",(s[n]+dp[n])/2);
    //cerr<<' '<<(s[n]-op[n])/2;
}
