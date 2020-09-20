#include <iostream>
#include <cstdio>
#include <vector>
#define mp make_pair
using namespace std;

int n, sum, x[15], p[15];
vector<pair<int,int> > ans;

int F(int n)
{
    ans.clear();
    if (n < 10) { ans.push_back(mp(0, n-1)); return n; }
    int m = 0, zero = 0, sub = 0;
    for(int a=n; a>0; a/=10) {
        x[++m] = a % 10;
        if (x[m] == 0) zero += 1;
        ///tmp += 11*m - 1;
    }
    if (zero == m-1) {
        sub = F(n-1) + 1;
        ans.back().second += 1;
        return sub;
    }

    int cur = 10, e;
    ans.push_back(mp(0, 9));
    for(int i=2; i<m; ++i) {
        e = 1; cur += 9;
        ans.back().second += 9;
        for(int j=2; j<i; ++j) {
            e *= 10; cur += 9 * e;
            ans.push_back(mp(1, cur-9));
            ans.push_back(mp(0, 9));
        }
        e *= 10; cur = cur+8*e-8;
        ans.push_back(mp(1, cur));
        ans.push_back(mp(0, 9));
        cur += 9;
    }

    p[0] = 1; for(int i=1; i<=m; ++i) p[i] = p[i-1] * 10;

    int last = 1, bol; while (x[last] == 0) ++last;
    int one = (x[m] != 1), first = 1;
    for(int i=m-1; i>=last; --i) if (x[i]) {
        if (one && (x[i] == 1 || i == last)) {
            one = 0;
            cur += (x[m]-1) * p[m-1];
            if (!first)
                ans.push_back(mp(0, x[m])); else
                ans.back().second += x[m], first = 0;

            bol = 0;
            if (x[i] > 1) {
                ans.push_back(mp(1, cur+1));
                ans.push_back(mp(0, x[i]-1));
                bol = 1;
            }
            cur += x[i] * p[i-1];
            ans.push_back(mp(1, cur));
            if (bol && i == 1) ans.pop_back();
        } else {
            cur += x[i] * p[i-1];
            if (!first)
                ans.push_back(mp(0, x[i])); else
                ans.back().second += x[i], first = 0;
            ans.push_back(mp(1, cur));
            if (i == 1) ans.pop_back();
        }
    }
    ///if (last == 1) ans.pop_back();

    sub = 0;
    for(int i=0; i<(int)ans.size(); ++i)
    sub += ans[i].first ? 1 : ans[i].second + 1;
    return sub;
}
int main()
{
    freopen("MGAME.inp","r",stdin);
    freopen("MGAME.out","w",stdout);

    int T; scanf("%d",&T); while (T--) {
        scanf("%d",&n); sum = F(n);
        if (sum >= 1000) {printf("1"); continue;}
        printf("%d\n",1000-sum);
    }
}
