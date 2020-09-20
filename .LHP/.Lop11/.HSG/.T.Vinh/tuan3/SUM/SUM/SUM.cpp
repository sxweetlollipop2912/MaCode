#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

#pragma warning(disable:4996)

#define maxN 300003
#define dum -1

typedef long long maxn, maxa;

maxn n;
maxa a[maxN], smx[maxN], smn[maxN], sumx, sumn, res;
std::vector <maxn> mx, mn;


void Prepare() {
	std::cin >> n;
	for (maxn i = 1; i <= n; i++) std::cin >> a[i];
	a[0] = dum;
}


void Process() {
	mx.push_back(0); mn.push_back(0);
	res = smn[0] = smx[0] = sumx = sumn = 0;

	for (maxn i = 1; i <= n; i++) {
		while (a[mn.back()] != dum && a[mn.back()] >= a[i]) {
			maxn j = mn.back(); mn.pop_back();
			sumn -= smn[j];
			smn[i] += smn[j] + (a[j] - a[i]) * (j - mn.back());
		}
		res += sumn + smn[i]; mn.push_back(i); sumn += smn[i];

		while (a[mx.back()] != dum && a[mx.back()] <= a[i]) {
			maxn j = mx.back(); mx.pop_back();
			sumx -= smx[j];
			smx[i] += smx[j] + (a[i] - a[j]) * (j - mx.back());
		}
		res += sumx + smx[i]; mx.push_back(i); sumx += smx[i];
	}

	std::cout << res;
}


int main() {
	freopen("sum.inp", "r", stdin);
	//freopen("sum.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}