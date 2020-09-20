#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <deque>
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

int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};

//int dr[] = { 1,-1, 0, 0};
//int dc[] = { 0, 0, 1,-1};

int n,m,k;
int cost,hdist;

int Adj[300][300];

vi pa,ra,sz,num;

vector< pair<int,ii> > Edge;

void init() {
    cin >> n >> m;

    int u,v,w;

    FOR(i,0,n) {
        pa[i] = i;
        ra[i] = 0;
        sz[i] = 1;
    }
    Edge.clear();

    n--; m--;
    FOR(i,0,m) {
        cin >> u >> v >> w;
        u--; v--;
        Edge.pb(make_pair(w,ii(u,v)));
    }
    sort(Edge.begin(),Edge.end());
}

int findSet(int i) {
    if (pa[i] == i) return(i); else return(findSet(pa[i]));
}

int sizeSet(int i) {
    return(sz[findSet(i)]);
}

bool sameSet(int i, int j) {
    return(findSet(i) == findSet(j));
}

void unionSet(int i, int j) {
    if (!sameSet(i,j)) {
        int x = findSet(i); int y = findSet(j);
        sz[x] = sz[y] = sz[x] + sz[y];
        if (ra[x] > ra[y])
            pa[y] = pa[x], sz[y] = 0;
        else {
            pa[x] = pa[y], sz[x] = 0;
            if (ra[x] == ra[y]) ra[y]++;
        }
    }
}

void kruskal() {
    cost = 0;
    vii gayporn;
    FOR(i,0,(int)Edge.size()-1) {
        pair<int,ii> front = Edge[i];
        if (!sameSet(front.y.x,front.y.y)) {
            cost += front.x;
            gayporn.pb(ii(front.y.x,front.y.y));
            unionSet(front.y.x,front.y.y);
        }
    }
    cout << cost << " ";
    int cost2 = INF;

    FOR(j,0,(int)gayporn.size()-1) {
        cost = 0;

        FOR(i,0,n) {
            pa[i] = i;
            ra[i] = 0;
            sz[i] = 1;
        }

        FOR(i,0,(int)Edge.size()-1) {
            pair<int,ii> front = Edge[i];
            if (!sameSet(front.y.x,front.y.y)) {
                if (front.y.x == gayporn[j].x && front.y.y == gayporn[j].y) continue;
                cost += front.x;
                unionSet(front.y.x,front.y.y);
            }
        }
        cost2 = min(cost2, cost);
    }

    cout << cost2 << endl;
}

int main() {
    if (DEBUG) {
        freopen("CUPDIEN.inp", "r", stdin);
        freopen("CUPDIEN.out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);

    FOR(i,0,300) {
        pa.pb(i);
        ra.pb(0);
        sz.pb(1);
    }

    int t;
    cin >> t;

    while (t--) {
        init();
        kruskal();
    }

    return 0;
}
