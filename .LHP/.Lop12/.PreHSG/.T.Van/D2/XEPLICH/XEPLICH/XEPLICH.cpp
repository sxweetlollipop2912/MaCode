#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

#pragma warning(disable:4996)

#define maxN 101

typedef int maxn;
typedef long long maxa;

maxn n;
maxa T[maxN], mx_soon[maxN], mx_late[maxN], res;
std::vector <maxn> ad[maxN], adr[maxN];


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> T[i];

	std::cin.ignore();
	std::string s;
	while (std::getline(std::cin, s)) {
		std::stringstream ss(s);
		maxn v, u;
		ss >> v, --v;
		while (ss >> u) {
			--u;
			ad[u].push_back(v);
			adr[v].push_back(u);
		}
	}

	std::fill(mx_soon, mx_soon + n, -1);
	std::fill(mx_late, mx_late + n, -1);
}


void DFS(const maxn u, const std::vector <maxn> ad[maxN], maxa mx[maxN]) {
	mx[u] = 0;
	for (maxn i = 0; i < ad[u].size(); i++) {
		maxn v = ad[u][i];
		if (mx[v] == -1) 
			DFS(v, ad, mx);
		mx[u] = std::max(mx[u], mx[v] + T[v]);
	}
}


void Process() {
	for (maxn i = 0; i < n; i++)
		if (mx_soon[i] == -1) DFS(i, adr, mx_soon);
	for (maxn i = 0; i < n; i++)
		if (mx_late[i] == -1) DFS(i, ad, mx_late);


	for (maxn i = 0; i < n; i++)
		res = std::max(res, mx_soon[i] + T[i]);

	std::cout << res << '\n';
	for (maxn i = 0; i < n; i++)
		std::cout << mx_soon[i] << ' ' << res - mx_late[i] - T[i] << '\n';
}


int main() {
	freopen("xeplich.inp", "r", stdin);
	//freopen("xeplich.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}