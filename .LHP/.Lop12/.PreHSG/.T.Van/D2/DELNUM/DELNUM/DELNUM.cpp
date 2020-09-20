#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN 400001

typedef long maxn;
typedef long long maxa;

maxn n, res;
maxa a[maxN];
std::vector <maxa> st;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		while (!st.empty() && ((st.size() == 1) || (st.size() >= 2 && st.back() != st[st.size() - 2])) && st.back() < a[i]) {
			st.pop_back();
			if (!st.empty()) ++res;
		}
		st.push_back(a[i]);
	}
	std::cout << n - res;
}


int main() {
	//freopen("delnum.inp", "r", stdin);
	//freopen("delnum.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}