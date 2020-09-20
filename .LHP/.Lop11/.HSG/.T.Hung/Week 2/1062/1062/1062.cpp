#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 1002
#define maxC 27
#define num(c) ((c) - 'A')

typedef int maxn, maxc;
typedef std::string str;

maxn n, st[maxC], en[maxC], bit[maxN], res;
bool done[maxC];
std::vector <maxc> con;
str s;


void Prepare() {
	n = s.size();
	std::fill(st, st + maxC, 0);
	std::fill(en, en + maxC, 0);
	std::fill(done, done + maxC, 0);
	con.clear();
}


void Process() {
	std::vector <maxn> v;

	for (maxn i = 0; i < n; i++) {
		maxn iv = std::lower_bound(v.begin(), v.end(), num(s[i])) - v.begin();
		if (iv == v.size()) v.push_back(num(s[i]));
		else v[iv] = num(s[i]);
	}
	
	std::cout << v.size() << '\n';
}


int main() {
	freopen("1062.inp", "r", stdin);
	freopen("1062.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int cntq = 0;
	while (std::cin >> s && s != "end") {
		++cntq, std::cout << "Case " << cntq << ": ";
		Prepare();
		Process();
	}
}