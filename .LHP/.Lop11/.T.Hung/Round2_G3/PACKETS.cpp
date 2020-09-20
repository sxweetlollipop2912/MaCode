#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <list>
//#include <bits/stdc++.h>

#define DEBUG 1
#define UNVISITED -1
#define EXPLORED 0
#define VISITED 1
#define INF 1000000000
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sp << ' ' <<
#define FOR(i,l,r)  for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define TRvi(c,it)  for (vi::iterator it=(c).begin(); it!=(c).end(); it++)
#define TRviD(c,it) for (vi::iterator it=(c).rbegin();it!=(c).rend();it++)

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

ll n1,n2,n3,n4,n5,n6;
ll ans;

signed main() {
    if (DEBUG) {
        freopen("PACKETS.inp", "r", stdin);
        freopen("PACKETS.out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);

    while (cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6) {
        if (n1 + n2 + n3 + n4 + n5 + n6 == 0) break;
        ans = ceil((double)n3/4) + n4 + n5 + n6;
        n2 -= (n3*5 + n4*5);

        if (n2 > 0) {
            ll dev = n2/9;
            ans += ceil((double)n2/9);

            dev = n2 - dev*9;

            n1 -= (n3*7 + n5*11 + dev);

            if (n1 > 0) {
                ans += ceil((double)n1/36);
            }

            cout << ans << endl;
        }
        else {
            ll S = 11*n5 + 20*n4 + 27*n3 - 4*n2;

            n1 -= S;
            if (n1 > 0) {
                ans += ceil((double)n1/36);
            }

            cout << ans << endl;
        }
    }

    return 0;
}
