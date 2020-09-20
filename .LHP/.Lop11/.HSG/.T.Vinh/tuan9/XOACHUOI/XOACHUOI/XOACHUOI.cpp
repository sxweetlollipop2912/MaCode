#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 1000001
#define maxM 41
#define last b[b.size() - 1]

typedef long maxn;
typedef std::string str;

str a, b;
char prev[200];
maxn fprev[maxN];
bool del[maxN], res;
std::vector <maxn> st;


void Prepare() {
	std::cin >> a >> b;
	for (maxn i = 1; i < b.size(); i++) prev[b[i]] = b[i - 1];
}


void Process() {
	std::fill(fprev, fprev + a.size(), -1);

	for (maxn ia = 0; ia < a.size(); ia++) {
		if (a[ia] == b[0]) fprev[ia] = 0;
		if (!st.empty() && a[st.back()] == prev[a[ia]] && fprev[st.back()] != -1) {
			fprev[ia] = st.back() + 1;
			st.pop_back();
		}
		if (a[ia] != last || fprev[ia] == -1) st.push_back(ia);
		else for (maxn j = ia; j != -1; j = fprev[j] - 1) del[j] = 1;
	}

	res = 0;
	for (maxn ia = 0; ia < a.size(); ia++)
		if (!del[ia]) std::cout << a[ia], res = 1;

	if (!res) std::cout << "EMPTY";
}


int main() {
	//freopen("xoachuoi.inp", "r", stdin);
	//freopen("xoachuoi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}