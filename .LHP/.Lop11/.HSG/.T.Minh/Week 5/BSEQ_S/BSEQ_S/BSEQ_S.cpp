#define LOCAL 1
//#define BUG
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back
#define ins insert
#define rsz resize
#define lb lower_bound
#define ub upper_bound
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&& ... args) {
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
const int N = 20;

int n, vis1[N], vis2[N << 1], vis3[N << 1], b[N];
vvi a;
ll ans, sf[N];

void backtrack(int pos) {
	fore(i, 0, sz(a[pos])) {
		b[pos] = a[pos][i];
		if (vis1[b[pos]] || (vis2[pos - b[pos] + N] || vis3[pos + b[pos]])
			|| (pos > 0 && abs(b[pos] - b[pos - 1]) == 2) || (pos > 1 && abs(b[pos] - b[pos - 2]) == 1)) {
			ans += sf[pos + 1];
		}
		else if (pos < n) {
			++vis1[b[pos]];
			++vis2[pos - b[pos] + N];
			++vis3[pos + b[pos]];
			backtrack(pos + 1);
			--vis1[b[pos]];
			--vis2[pos - b[pos] + N];
			--vis3[pos + b[pos]];
		}
	}
}

int main() {
#ifdef LOCAL
	//freopen("bseq.inp", "r", stdin);
	//freopen("bseq.out", "w", stdout);
#endif // LOCAL
	ios_base::sync_with_stdio(0); cin.tie(0);
	while ((cin >> n) && n) {
		ans = 0;
		memset(b, 0, sizeof b);
		memset(sf, 0, sizeof sf);
		a = vvi(n);
		string in;
		fore(i, 0, n) {
			cin >> in;
			if (in[0] == '?') fore(j, 0, n) a[i].pb(j);
			else fore(j, 0, sz(in)) a[i].pb((int)(in[j] - 'A'));
		}
		//        fore(i, 0, n) fore(j, 0, sz(a[i])) cout << a[i][j] << " \n"[j == sz(a[i]) - 1];
		sf[n] = 1;
		ford(i, n - 1, 0) sf[i] = sf[i + 1] * sz(a[i]);
		backtrack(0);
		cout << ans << '\n';
	}
	return 0;
}
