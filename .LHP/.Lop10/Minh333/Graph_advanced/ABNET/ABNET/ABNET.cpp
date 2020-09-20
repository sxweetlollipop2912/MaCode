#include "pch.h"
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

#define N 10005
#define fort(i,a,b) for(int i=a;i<=b;++i)
#define form(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int n, a[N], b[N], par[N],
num[N], low[N], cnt,
ind[N], da[N], db[N], A[N], B[N],
vis[N], ans1, ans2;
vector<int> ke[N], adj[N];
stack<int> S;

void dfs(int u) {
	int v; S.push(u);
	num[u] = low[u] = ++cnt;

	form(i, 0, (int)ke[u].size()) 
		if (ke[u][i] != par[u]) {
			v = ke[u][i];
			if (num[v] == 0) {
				par[v] = u; dfs(v);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], num[v]);
		}

	if (low[u] == num[u]) 
		do {
			v = S.top(); S.pop();
			ind[v] = u;
			da[u] += a[v];
			db[u] += b[v];
		} while (u != v);
}


int Par(int u) {
	return par[u] == 0 ? u : par[u] = Par(par[u]);
}


void dsu(int u, int v) {
	if ((u = Par(u)) == (v = Par(v))) return;
	par[u] = v;
	A[v] += A[u];
	B[v] += B[u];
}


void dfs2(int u) {
	int v, na = A[Par(u)], nb = B[Par(u)], a, b;
	vis[u] = 1;
	form(i, 0, (int)adj[u].size()) if (!vis[adj[u][i]]) {
		v = adj[u][i];
		dfs2(v);

		a = max(da[v], na - da[v]);
		b = max(db[v], nb - db[v]);
		ans1 += (a == na || b == nb);
		ans2 += (a > na / 2 || b > nb / 2);

		da[u] += da[v];
		db[u] += db[v];
	}
}


int main() {
	//freopen("ABNET.inp", "r", stdin);
	//freopen("ABNET.out", "w", stdout);

	int na = 0, nb = 0, m = 0, u = 0, v = 0;
	scanf("%d%d%d%d", &n, &m, &na, &nb);
	while (na--) scanf("%d", &u), a[u] = 1;
	while (nb--) scanf("%d", &u), b[u] = 1;
	while (m--) {
		scanf("%d%d", &u, &v);
		ke[u].push_back(v);
		ke[v].push_back(u);
	}

	fort(i, 1, n) if (num[i] == 0) dfs(i);

	fort(i, 1, n)
		par[i] = 0,
		A[ind[i]] = da[ind[i]],
		B[ind[i]] = db[ind[i]];

	fort(u, 1, n) form(i, 0, (int)ke[u].size()) {
		v = ke[u][i];
		if (ind[u] != ind[v]) {
			adj[ind[u]].push_back(ind[v]);
			adj[ind[v]].push_back(ind[u]);
			dsu(ind[u], ind[v]);
		}
	}

	fort(i, 1, n) if (!vis[ind[i]]) dfs2(ind[i]);
	printf("%d %d", ans1, ans2);
}
