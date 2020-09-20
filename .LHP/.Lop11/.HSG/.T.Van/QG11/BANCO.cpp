#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int r[]={2,1,-1,-2,-2,-1,1,2};
const int c[]={-1,-2,-2,-1,1,2,2,1};
int a[10][10],b[10][10];
map<int,pii>pos;
string convert(int x, int y){
    string re="";
    re=(char)(8-x+1+'0');
    re=(char)(y-1+'a')+re;
    return re;
}
void solve(int si, int sj, int ti, int tj){
    bool visit[9][9]={};
    pii trace[9][9]={};
    queue<pii>q;
    q.push(pii(si,sj));
    visit[si][sj]=1;
    while (!q.empty()){
        int ui=q.front().first;
        int uj=q.front().second;
        q.pop();
        for (int i=0;i<8;i++){
            int vi=ui+r[i];
            int vj=uj+c[i];
            if (vi<=8&&vj<=8&&vi>=1&&vj>=1&&!visit[vi][vj]){
                trace[vi][vj]=pii(ui,uj);
                visit[vi][vj]=1;
                q.push(pii(vi,vj));
            }
        }
        if (visit[ti][tj]==1)break;
    }
    vector<string>ans;
    while (1){
        ans.push_back(convert(ti,tj));
        ans.push_back(convert(trace[ti][tj].first,trace[ti][tj].second));
        pii tmp=trace[ti][tj];
        ti=tmp.first;
        tj=tmp.second;
        if (ti==si&&tj==sj)break;
    }
    for (int i=ans.size()-1;i>=0;i-=2)
        cout<<ans[i]<<" "<<ans[i-1]<<endl;
    for (int i=2;i<ans.size();i+=2)
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
}
int main()
{
    freopen("BANCO.inp","r",stdin);
    freopen("BANCO.out","w",stdout);
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++){
            cin>>a[i][j];
            pos[(i-1)*8+j]=pii(i,j);
            b[i][j]=(i-1)*8+j;
        }
    for (int i=1;i<=8;i++)
        for (int j=1;j<=8;j++)
    if (b[i][j]!=a[i][j]){
        int x=pos[a[i][j]].first,y=pos[a[i][j]].second;
        pos[b[i][j]]=pii(x,y);
        pos[a[i][j]]=pii(i,j);
        solve(i,j,x,y);
        swap(b[i][j],b[x][y]);
    }
    return 0;
}
