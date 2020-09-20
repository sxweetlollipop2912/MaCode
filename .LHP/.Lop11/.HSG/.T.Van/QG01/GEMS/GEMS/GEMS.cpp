#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define maxN 100001
#define maxAlp 27
#define num(x) ((x) - 'a')

typedef long maxn;
typedef int maxk, maxa;
typedef long long maxr;
typedef std::string str;

maxn n;
str s;
maxr cnt[maxAlp], res;
std::vector <maxa> ad[maxAlp];


void Prepare() {
	maxk K;
	std::cin >> n >> K >> s;

	while (K--) {
		char a, b;
		std::cin >> a >> b;
		ad[num(b)].push_back(num(a));
	}
}


void Process() {
	for (maxn i = 0; i < n; i++) {
		for (maxk j = 0; j < ad[num(s[i])].size(); j++) 
			res += cnt[ad[num(s[i])][j]];
		++cnt[num(s[i])];
	}
	std::cout << res;
}


int main() {
	//freopen("gems.inp", "r", stdin);
	//freopen("gems.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}