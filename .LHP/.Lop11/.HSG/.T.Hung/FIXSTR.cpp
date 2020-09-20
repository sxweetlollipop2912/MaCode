#include <bits/stdc++.h>
#define N 1000005
using namespace std;
struct node{
    int close,open,sum;
};
node IT[N*4];
string s,num[N];
int n,u,v,pos,k,m;
char op;
void update(int p, int l, int r, int pos){
    if (l==r){
        IT[p].close=1-IT[p].close;
        IT[p].open=1-IT[p].open;
        return;
    }
    int mid=(l+r)>>1;
    if (pos<=mid)update(p<<1,l,mid,pos);
    else update(p<<1|1,mid+1,r,pos);
    int tmp=min(IT[p<<1].open,IT[p<<1|1].close);
    IT[p].sum=tmp*2+IT[p<<1].sum+IT[p<<1|1].sum;
    IT[p].close=IT[p<<1].close+IT[p<<1|1].close-tmp;
    IT[p].open=IT[p<<1].open+IT[p<<1|1].open-tmp;
}
node query(int p, int l, int r, int u, int v){
    if (l>r)return {0,0,0};
    if (u>r||v<l)return {0,0,0};
    if (u<=l&&r<=v)return IT[p];
    int mid=(l+r)>>1;
    node Left=query(p<<1,l,mid,u,v);
    node Right=query(p<<1|1,mid+1,r,u,v);
    node ans;
    int tmp=min(Left.open,Right.close);
    ans.sum=tmp*2+Left.sum+Right.sum;
    ans.close=Left.close+Right.close-tmp;
    ans.open=Left.open+Right.open-tmp;
    return ans;
}
void build(int p, int l, int r, const string &s){
    if (l==r){
        IT[p].sum=0;
        if (s[l]==')')IT[p].close=1,IT[p].open=0;
        else IT[p].open=1,IT[p].close=0;
        return;}
    int mid=(l+r)>>1;
    build(p<<1,l,mid,s);
    build(p<<1|1,mid+1,r,s);
    int tmp=min(IT[p<<1].open,IT[p<<1|1].close);
    IT[p].sum=tmp*2+IT[p<<1].sum+IT[p<<1|1].sum;
    IT[p].close=IT[p<<1].close+IT[p<<1|1].close-tmp;
    IT[p].open=IT[p<<1].open+IT[p<<1|1].open-tmp;
}
int main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s;
    n=s.size();
    s='0'+s;
    build(1,1,n,s);
    scanf("%d",&m);
    num[0]=s;
    for (int i=1;i<=m;i++){
        scanf("%s",&op);
        if (op=='C'){
            scanf("%d",&pos);
            update(1,1,n,pos);
            if (s[pos]==')')s[pos]='(';
            else s[pos]=')';
            num[i]=s;
        }
        else if (op=='Q'){
            scanf("%d%d",&u,&v);
            node ans=query(1,1,n,u,v);
            cout<<v-u+1-ans.sum<<endl;
            num[i]=num[i-1];
        }
        else if (op=='U'){
            scanf("%d",&k);
            s=num[k-1];
            build(1,1,n,s);
            //cout<<s<<endl;
            num[i]=s;
        }
    }
    //for (int i=1;i<=m;i++)cout<<num[i]<<endl;
    return 0;
}
