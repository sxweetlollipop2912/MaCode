#if 0
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
bitset<100000>bs;
vector<ll>prime;
int l,r;
map<int,vector<int> >m;
vector<pii>ans;
void sieve (int N){
    for (int i=2;i<=N;i++)
    if (bs[i]==0){
        prime.push_back(i);
        for (int j=i*i;j<=N;j+=i)
            bs[j]=1;
    }
}
ll fact(const int &x){
    int y=x;
    ll re=1LL;
    for (int i=0;i<prime.size()&&prime[i]*prime[i]<=y;i++)
        if (y%prime[i]==0){
            ll tmp=prime[i];
            while (y%prime[i]==0){
                tmp*=prime[i];
                y/=prime[i];
            }
            re*=((tmp-1)/(prime[i]-1LL));
        }
    if (y!=1)re*=((y*y-1)/(y-1));
    re-=x;
    return re;
}
int main()
{
    freopen("AMI.inp","r",stdin);
    freopen("AMI.out","w",stdout);
    cin>>l>>r;
    sieve(sqrt(r));
    bool check[1000005];
    for (ll i=l;i<=r;i++){
        if (!check[i]){
        ll tmp=fact(i);

        if (tmp>r||tmp<l||tmp==i)continue;
        if (fact(tmp)==i){
            cout<<i<<","<<tmp<<","<<endl;

        check[tmp]=1;
        }

    }
    }
    return 0;
}
#else
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int a[76]={220,284,
1184,1210,
2620,2924,
5020,5564,
6232,6368,
10744,10856,
12285,14595,
17296,18416,
63020,76084,
66928,66992,
67095,71145,
69615,87633,
79750,88730,
100485,124155,
122265,139815,
122368,123152,
141664,153176,
142310,168730,
171856,176336,
176272,180848,
185368,203432,
196724,202444,
280540,365084,
308620,389924,
319550,430402,
356408,399592,
437456,455344,
469028,486178,
503056,514736,
522405,525915,
600392,669688,
609928,686072,
624184,691256,
635624,712216,
643336,652664,
667964,783556,
726104,796696,
802725,863835
};
int l,r;
int main()
{
    freopen("AMI.inp","r",stdin);
    freopen("AMI.out","w",stdout);
    cin>>l>>r;
    for (int i=0;i<=74;i+=2)
        if (a[i]<=r&&a[i]>=l&&a[i+1]>=l&&a[i+1]<=r)
        cout<<a[i]<<" "<<a[i+1]<<endl;
    return 0;
}
#endif
