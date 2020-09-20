// AC UVa
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning (disable:4996)

#define maxA 101
//#define maxN 31
//#define P 25
//#define MAXB ((1 << (P + 1)) - 1)

typedef int maxa, maxn;
typedef long long maxb;

int t;
maxa S;
maxn n;
maxb pd[maxA] = { 0,0,1,2,1,4,3,8,1,2,5,16,3,32,9,6,1,64,3,128,5,10,17,256,3,4,33,2,9,512,7,1024,1,18,65,12,3,2048,129,34,5,4096,11,8192,17,6,257,16384,3,8,5,66,33,32768,3,20,9,130,513,65536,7,131072,1025,10,1,36,19,262144,65,258,13,524288,3,1048576,2049,6,129,24,35,2097152,5,2,4097,4194304,11,68,8193,514,17,8388608,7,40,257,1026,16385,132,3,16777216,9,18,5 };
std::vector <maxa> res;


void Prepare() {
	std::cin >> S >> n;
}


void Output(std::vector <maxa>& v) {
	std::cout << '\n';
	bool p = 0;
	for (maxa i = 0; i < v.size(); i++) {
		if (p) std::cout << ' '; p = 1;
		std::cout << v[i];
	}
}


void Try(const maxa x, const maxn left, const maxa s, const maxb b, std::vector <maxa>& v) {
	if (left == 1) {
		if (pd[s] & b) return;
		v.push_back(s); Output(v); v.pop_back();
		return;
	}
	for (maxa i = x; i <= S && (i * left) <= s; i++) {
		if (pd[i] & b) continue;
		v.push_back(i);
		Try(i, left - 1, s - i, b | pd[i], v);
		v.pop_back();
	}
}


void Process() {
	Try(1, n, S, 0, res);
}


int main() {
	//freopen("10637.inp", "r", stdin);
	//freopen("10637.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> t;
	//bool p = 0;
	for (int cnt = 1; cnt <= t; cnt++) {
		//if (p) std::cout << '\n'; p = 1;
		std::cout << "Case " << cnt << ":";
		Prepare();
		Process();
		std::cout << '\n';
	}
}