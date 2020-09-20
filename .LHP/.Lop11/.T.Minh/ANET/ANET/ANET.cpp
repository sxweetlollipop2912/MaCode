#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define x first
#define y second
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define MaxN 1001
#define d(u, v) ((co[u].x - co[v].x)*(co[u].x - co[v].x) + (co[u].y - co[v].y)*(co[u].y - co[v].y))
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, long long> il;
typedef pair<long long, long long> ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<il> vil;
#define INF 10000

using namespace std;


int n, S;
ll co[MaxN];
il gr[MaxN];
vil edge;

bool cmp(ii e1, ii e2)
{
	return d(e1.x, e1.y) < d(e2.x, e2.y);
}

void enter()
{
	cin >> n >> S;
	for (int i = 0; i < n; i++)
	{
		cin >> co[i].x >> co[i].y;
		gr[i].first = i, gr[i].second = 0;
		rep(j, 0, i - 1) edge.push_back(ii(i, j));
	}
	sort(edge.begin(), edge.end(), cmp);
}

bool Union(int u, int v)
{
	while (u != gr[u].first) u = gr[u].first;
	while (v != gr[v].first) v = gr[v].second;
	if (u != v) {
		if (gr[u].second < gr[v].second) gr[u].first = v;
		else
		{
			if (gr[u].second == gr[v].second) ++gr[v].second;
			gr[v].first = u;
		}
		return 1;
	}
	else return 0;
}

void solve()
{
	int CNT = n - Union(edge[0].x, edge[0].y);
	for (int i = 1; i < edge.size(); i++) {
		if (CNT <= S && d(edge[i].x, edge[i].y) != d(edge[i - 1].x, edge[i - 1].y))
			break;
		if (Union(edge[i].x, edge[i].y)) --CNT;
	}
	cout << CNT << '\n';
	for (int i = 0; i < n; i++) if (gr[i].first == i) cout << i + 1 << ' ';
}

int main()
{
	freopen("ANET.INP", "r", stdin);
	freopen("ANET.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	enter();
	solve();
	return 0;
}

