#define LOCAL
//#define BUG
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " /";
    __f(comma + 1, args...);
}
#endif

template <class T> bool mini(T& a, T b) { return a > b ? (a = b, 1) : 0; }
template <class T> bool maxi(T& a, T b) { return a < b ? (a = b, 1) : 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

const int INF = (int)1e9 + 7;
const int N = 4003;
const ll M = 1000003;

int n, m, a[N], mx[N], vis[N], ans, Min = INF, Max;

void input() {
    cin >> n >> m;
    fort(i, 1, 2 * n) {
        cin >> a[i];
        mini(Min, a[i]);
        maxi(Max, a[i]);
    }
}

void prep() {
    int j = 1;
    fort(i, 1, 2 * n) {
        while (j <= 2 * n && a[j] <= a[i] + m) ++j;
        --j;
        mx[i] = j;
    }
//    fort(i, 1, 2 * n) cout << mx[i] << ' ';
}

void Try(int i) {
    if (i > n) ++ans;
    else {
        int cur = 1;
        while (vis[cur]) ++cur;
        for (int j = cur + 1; j <= min(mx[cur], 2 * n); ++j) if (!vis[j]) {
            if ((j - cur) % 2 == 1) {
                vis[cur] = 1;
                vis[j] = 1;
                Try(i + 1);
                vis[j] = 0;
                vis[cur] = 0;
            }
        } else break;
//        for (int j = cur + 1; j <= min(mx[cur], 2 * n); j += 2) if (!vis[j]) {
//            vis[cur] = 1;
//            vis[j] = 1;
//            Try(i + 1);
//            vis[j] = 0;
//            vis[cur] = 0;
//        }
    }
}

void solve() {
    prep();
    Try(1);
    cout << ans % M << '\n';
}

int main() {
#ifdef LOCAL
    freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    if (Max - Min <= m) {
        vector<ll> a(n + 1);
        a[0] = 1;
        fort(i, 1, n) fore(j, 0, i) (a[i] += a[j] * a[i - j - 1]) %= M;
//        fort(i, 1, n) cout << a[i] << ' ';
        cout << a[n] << '\n';
    } else solve();
    return 0;
}
