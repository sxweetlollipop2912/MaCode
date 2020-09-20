#define LOCAL
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <math.h>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <limits>
#include <climits>
#include <map>
#include <ctime>
#define fore(i, a, b) for(ll i = (a), _b = (b); i < (_b); i++)
#define fort(i, a, b) for(ll i = (a), _b = (b); i <= (_b); i++)
#define ford(i, a, b) for(ll i = (a), _b = (b); i >= (_b); i--)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define debug(x) cerr << #x << " -> " << (x) << '\n'
#define getbit(x,i) ((x) & (1ll << (i)))
using namespace std;

template<class T> bool mini(T &a, T b){return a > b ? (a = b, 1) : 0; }
template<class T> bool maxi(T &a, T b){return a < b ? (a = b, 1) : 0; }

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const ll maxN = 1e4 + 5;
const ll maxA = 3e4 + 5;

int states[8] = {
    0b0000,
    0b1000,
    0b1001,
    0b1010,
    0b0001,
    0b0010,
    0b0100,
    0b0101
};
ll res,mx = -maxA;
int n;
bool check;
ll dp[maxN][9];
ll a[5][maxN];

int main(){
    #ifdef LOCAL
        freopen("select.INP","r",stdin);
        freopen("select.OUT","w",stdout);
    #endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    fore(i,0,4)
        fort(j,1,n){
            cin >> a[i][j];
            if(a[i][j] >= 0)
                check = true;
            else
                maxi(mx,a[i][j]);
        }
    if(!check){
        cout << mx << '\n';
        return 0;
    }
    fort(j,1,n)
        fore(x,0,8){
            fore(y,0,8)
                if((states[x] & states[y]) == 0)
                    maxi(dp[j][x],dp[j - 1][y]);

            fore(i,0,4)
                if(getbit(states[x],i) && a[i][j] > 0)
                    dp[j][x] += a[i][j];
        }

    ll res = 0;

    fore(x,0,8)
        maxi(res,dp[n][x]);

    cout << res << '\n';
    return 0;
}
