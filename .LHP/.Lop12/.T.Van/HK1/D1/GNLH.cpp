#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#define maxN ((maxn)100001)
#define maxA ((maxa)(1e9 + 1))
#define none ((maxa)9999999)
#define abs(x) ((x) < 0? -(x) : (x))

typedef long maxn, maxa;

maxn n, res[maxN];
maxa a[maxN];
std::vector <maxn> st;


void Prepare() {
	std::cin >> n;
	for (maxn i = 0; i < n; i++) std::cin >> a[i], res[i] = -1;
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
		if (!st.empty()) {
			if (res[i] == -1)
				res[i] = st.back();
			else if (abs(st.back() - i) < abs(res[i] - i))
				res[i] = st.back();
			else if (abs(st.back() - i) == abs(res[i] - i) && a[st.back()] > a[res[i]])
				res[i] = st.back();
		}
		st.push_back(i);
	}
	st.clear();
	for (maxn i = n - 1; i >= 0; i--) {
		while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
		if (!st.empty()) {
			if (res[i] == -1)
				res[i] = st.back();
			else if (abs(st.back() - i) < abs(res[i] - i))
				res[i] = st.back();
			else if (abs(st.back() - i) == abs(res[i] - i) && a[st.back()] > a[res[i]])
				res[i] = st.back();
		}
		st.push_back(i);
	}

	for (maxn i = 0; i < n; i++) {
		if (res[i] == -1) std::cout << none << ' ';
		else std::cout << a[res[i]] << ' ';
	}
}


int main() {
	freopen("gnlh.inp", "r", stdin);
	freopen("gnlh.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}