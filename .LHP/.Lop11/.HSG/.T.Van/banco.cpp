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
const int dr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int N = 10;

int a[N][N], p[N][N][N][N];
bool vis[N][N];
ii pos[N * N];

void input() {
    fort(i, 1, 8) fort(j, 1, 8) {
        cin >> a[i][j];
        pos[a[i][j]] = ii(i, j);
    }
}

void prep() {
    memset(p, -1, sizeof p);
    fort(sr, 1, 8) fort(sc, 1, 8) {
        memset(vis, 0, sizeof vis);
        queue<ii> q;
        vis[sr][sc] = 1;
        q.push({sr, sc});
        while (!q.empty()) {
            int r = q.front().fi;
            int c = q.front().se;
            q.pop();
            fore(i, 0, 8) {
                int u = r + dr[i];
                int v = c + dc[i];
                if (u < 1 || v < 1 || u > 8 || v > 8 || vis[u][v]) continue;
                vis[u][v] = 1;
                p[sr][sc][u][v] = i;
                q.push({u, v});
            }
        }
    }
}

vii getPath(int sr, int sc, int tr, int tc) {
    vii res;
    for (int r = tr, c = tc, t; ~p[sr][sc][r][c]; t = p[sr][sc][r][c], r -= dr[t], c -= dc[t]) res.pb({r, c});
    res.pb({sr, sc});
    reverse(all(res));
    return res;
}

void solve() {
    prep();
    fort(i, 1, 8) fort(j, 1, 8) if (a[i][j] != (i - 1) * 8 + j) {
        int t = (i - 1) * 8 + j;
        vii path(getPath(i, j, pos[t].fi, pos[t].se));
        fore(i, 0, sz(path) - 1) {
            cout << char(path[i].se - 1 + 'a') << 8 - path[i].fi + 1 << ' ';
            cout << char(path[i + 1].se - 1 + 'a') << 8 - path[i + 1].fi + 1 << '\n';
        }
        ford(i, sz(path) - 2, 1) {
            cout << char(path[i].se - 1 + 'a') << 8 - path[i].fi + 1 << ' ';
            cout << char(path[i - 1].se - 1 + 'a') << 8 - path[i - 1].fi + 1 << '\n';
        }
        ii tmp = pos[t];
        pos[a[i][j]] = tmp;
        pos[t] = ii(i, j);
        a[tmp.fi][tmp.se] = a[i][j];
        a[i][j] = t;
    }
}

int main() {
#ifdef LOCAL
    freopen("banco.inp", "r", stdin);
    freopen("banco.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();
    solve();
    return 0;
}
