#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define mp make_pair
#define l first
#define r second
using namespace std;

const int N = 5e4+5;
int n, a[N], b[N], m, c[N], sum, last;
char type[N];

map<int, pair<int,int> > Link;
vector<pair<int,int> > point;
map<int, int> ans, pos;

int main()
{
    freopen("XEPHANG.inp","r",stdin);
    freopen("XEPHANG.out","w",stdout);

    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d%d",&a[i],&b[i]);
        Link[a[i]] = mp(-1, -1);
        Link[a[i]+1] = mp(-1, -1);
        Link[a[i]-1] = mp(-1, -1);

        Link[b[i]] = mp(-1, -1);
        Link[b[i]-1] = mp(-1, -1);
    }
    scanf("%d",&m);
    for(int i=1; i<=m; ++i) {
        scanf(" %c %d",&type[i],&c[i]);
        if (type[i] == 'P') Link[c[i]] = mp(-1, -1);
    }
    for(auto &tmp: Link) {
        if (Link.count(tmp.first-1)) tmp.second.l = tmp.first-1;
        if (Link.count(tmp.first+1)) tmp.second.r = tmp.first+1;
    }

    for(int i=1; i<=n; ++i) if (a[i] != b[i]) {
        Link[Link[a[i]].r].l = Link[a[i]].l;
        Link[Link[a[i]].l].r = Link[a[i]].r;

        Link[a[i]].r = b[i];
        Link[a[i]].l = Link[b[i]].l;
        Link[Link[b[i]].l].r = a[i];
        Link[b[i]].l = a[i];
    }

    point.push_back(mp(0, 0));
    for(auto tmp: Link) if (tmp.second.l == -1) {
        if (tmp.first) sum += tmp.first-1 - last;
        for(last=tmp.first; Link[last].r != -1; last=Link[last].r) {
            if (!last) continue;
            ans[last] = ++sum; pos[sum] = last;
        }
        ans[last] = ++sum; pos[sum] = last;
        point.push_back(mp(sum, last));
    }

    vector<pair<int,int> >::iterator it;
    for(int i=1; i<=m; ++i) if(type[i] == 'P') {
        printf("%d\n",ans[c[i]]);
    } else {
        if (pos.count(c[i])) printf("%d\n",pos[c[i]]); else {
            it = lower_bound(point.begin(), point.end(), mp(c[i], 0));
            --it; printf("%d\n",c[i] - it->first + it->second);
        }
    }
}
