// AC, Author: Truc
#include <bits/stdc++.h>
#define N 55
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
pii ver[4],a[N];
int cnt,n;

void Push(int i,int j, int k, int l){
    ver[0]=a[i];
    ver[1]=a[j];
    ver[2]=a[k];
    ver[3]=a[l];
}
pii cal(pii a, pii b){
    return pii(b.first-a.first,b.second-a.second);
}
int mul(pii vec1, pii vec2){
    long long ans=vec2.x*1LL*vec1.y-vec2.y*1LL*vec1.x;
    if (ans>0)return 1;
    else if (ans<0)return -1;
    else return 0;
}
bool isConvex(){
    // 0->1->2->3
    pii vec1=cal(ver[0],ver[1]);
    pii vec2=cal(ver[1],ver[2]);
    pii vec3=cal(ver[2],ver[3]);
    pii vec4=cal(ver[3],ver[0]);
    bool ans=0;
    int sign=mul(vec1,vec2);
    if (mul(vec2,vec3)*sign>0&&mul(vec3,vec4)*sign>0&&mul(vec4,vec1)*sign>0)ans=1;
    if (ans)return 1;
    // 0->1->3->2
    vec2=cal(ver[1],ver[3]);
    vec3=cal(ver[3],ver[2]);
    vec4=cal(ver[2],ver[0]);
    sign=mul(vec1,vec2);
    if (mul(vec2,vec3)*sign>0&&mul(vec3,vec4)*sign>0&&mul(vec4,vec1)*sign>0)ans=1;
    if (ans)return 1;
    //0->2->1->3
    vec1=cal(ver[0],ver[2]);
    vec2=cal(ver[2],ver[1]);
    vec3=cal(ver[1],ver[3]);
    vec4=cal(ver[3],ver[0]);
    sign=mul(vec1,vec2);
    if (mul(vec2,vec3)*sign>0&&mul(vec3,vec4)*sign>0&&mul(vec4,vec1)*sign>0)ans=1;
    return ans;
}
int main()
{
    //freopen("K.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (cin>>n){
            if (n==0)return 0;
        int cnt=0;
        for (int i=1;i<=n;i++)
            cin>>a[i].x>>a[i].y;
        for (int i=1;i<=n-3;i++)
            for (int j=i+1;j<=n-2;j++)
                for (int k=j+1;k<=n-1;k++)
                    for (int l=k+1;l<=n;l++){
                        Push(i,j,k,l);
                        if (isConvex())cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}