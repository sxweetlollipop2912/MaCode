#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

#ifdef RICARDO
	#define bug(x) cerr << #x << " = " << (x) << endl;
	#define block if(1)
#else
	#define bug(x) "IDINGO"
	#define block if(0)
#endif
	
template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

//=================================================CODE=================================================//

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#else
	freopen("XEPHANG.inp", "r", stdin);
	freopen("XEPHANG.out", "w", stdout);
#endif
    struct Node {
    	Node *front, *back;
    	int lenfront, id;
    };

    int n; cin >> n;
    vi vals;
    vpi q(n);

    for(pii &x : q) {
    	cin >> x.fi >> x.se;
    	vals.pb(x.fi);
    	vals.pb(x.se); 
    }

    int m; cin >> m;
    vector<pair<bool, int>> ques(m);
	for(auto &x : ques) {
		char c;
		cin >> c >> x.se;
		x.fi = c == 'P';
		if(x.fi) vals.pb(x.se);
	}

	vals.pb(0);	
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	map<int, int> id;
	forn(i, vals.size()) id[vals[i]] = i;		

	vector<Node> node(vals.size());
	forn(i, vals.size()) { 
		node[i] = {0, 0, 0, id[vals[i]]};
		if(i > 0) node[i].front = &node[i - 1], node[i].lenfront = vals[i] - vals[i - 1];
		if(i < (int) vals.size() - 1) node[i].back = &node[i + 1];
	}

	for(pii p : q) if(p.fi != p.se) {
		Node &x = node[id[p.fi]], &y = node[id[p.se]];
		if(x.back != NULL) x.back->lenfront += x.lenfront - 1, x.back->front = x.front;
		x.front->back = x.back;	
		x.front = y.front;
		y.front = &x;
		x.lenfront = y.lenfront;
		y.lenfront = 1;
		x.back = &y;
		x.front->back = &x;
	}

	int sum = 0;
	vi stt(vals.size());
	for(Node *i = &node[0]; i->back != NULL; i = i->back) {
		sum += i->back->lenfront;
		stt[i->back->id] = sum;
	}

	map<int, int> ans1;
	forn(i, vals.size()) ans1[stt[i]] = vals[i];
	vi pos = stt;
	sort(all(pos));

	//for(int v : vals) cout << v << ' '; cout << endl;
	//for(int v : pos) cout << v << ' '; cout << endl;

	for(pii e : ques) {
		if(e.fi) cout << stt[id[e.se]] << endl;
		else {
			if(ans1.count(e.se)) cout << ans1[e.se] << endl;
			else {
				int target = e.se - (upper_bound(all(pos), e.se) - pos.begin()) - 1;
				int l = 1, r = 1e9;
				while(l < r) {
					int mid = (l + r) >> 1;
					if(mid - (upper_bound(all(vals), mid) - vals.begin()) - 1 < target) l = mid + 1;
					else r = mid;
				}
				cout << l << endl;
			}
		}
	}
#ifdef RICARDO
	cerr << "\nManh: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif                                                              
}
	