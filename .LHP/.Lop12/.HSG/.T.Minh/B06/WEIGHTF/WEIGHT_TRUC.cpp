#include <bits/stdc++.h>
#define pii pair<int,double>
#define v first
#define w second
#define N 105
using namespace std;
int c,d,k,id,maxv,money;
double weight,put[300005],tmp,ans,Back[300005];
pii coin[N],a[N];
bool visit[300005];
double get(int x){
    if (x<0)return 1e9;
    if (visit[x])return Back[x];
    visit[x]=1;
    int tmp=x;
    double &re=Back[tmp];
    re=0;
    for (int i=d;i>=1;i--){
        int num=x/coin[i].v;
        re+=num*coin[i].w;
        x%=coin[i].v;
    }
    return re;
}
int main()
{
    freopen("WEIGHT.inp","r",stdin);
    freopen("WEIGHT_TRUC.out","w",stdout);
    cin>>c>>d>>k;
    for (int i=1;i<=d;i++)cin>>coin[i].v>>coin[i].w;
    for (int i=1;i<=k;i++){
        cin>>id;
        a[i]=coin[id];
        money+=coin[id].v;
        weight+=coin[id].w;
    }
    if (money<c)return cout<<"too poor",0;
    sort(coin+1,coin+d+1);
    ans=1e9;
    //memset(put,-1,sizeof(put));
    for (int i=1;i<=k;i++)
    for (int j=maxv+a[i].v;j>=a[i].v;maxv=max(maxv,j),j--){
        if (j==a[i].v||(put[j-a[i].v]>0&&put[j]<put[j-a[i].v]+a[i].w)){
            put[j]=put[j-a[i].v]+a[i].w;
            tmp=weight-put[j]+get(j-c);
            ans=min(ans,tmp);
        }
    }
    printf("%.2f",ans);
    return 0;
}
