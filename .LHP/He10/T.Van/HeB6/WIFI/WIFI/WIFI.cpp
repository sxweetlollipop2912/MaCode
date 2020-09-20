#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>

#define maxN 2001
//#define maxA 1000001
//#define maxR 99999999999999999
#define left second
#define distance first

typedef int maxn;
typedef double maxa;
typedef std::pair <maxn, maxa> dist_t;

maxn n;
maxa A, B, x[maxN], rec, res;
std::vector <dist_t> dist;
std::vector <maxn> ms;


bool cmp(const dist_t &x, const dist_t &y) {
	return x.distance > y.distance;
}


void Prepare() {
	std::cin >> n >> A >> B;

	for (maxn i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	std::sort(x, x + n);

	for (maxn i = 1; i < n; i++) {
		dist.push_back(dist_t(x[i] - x[i - 1], i - 1));
	}
	std::sort(dist.begin(), dist.end(), cmp);

	ms.push_back(0);
	ms.push_back(n - 1);
}


maxn findleft(const maxn a) {
	maxn re = 0;
	for (maxn i = 1; i < ms.size(); i++) {
		if (ms[i] <= a && ms[i] > ms[re]) re = i;
	}
	return re;
}

maxn findright(const maxn a) {
	maxn re = ms.size() - 1;
	for (maxn i = 0; i < ms.size() - 1; i++) {
		if (ms[i] >= a && ms[i] < ms[re]) re = i;
	}
	return re;
}

maxa cost(const maxn l, const maxn r) {
	return A + B * ((x[r] - x[l]) / (double)2);
}


void MoreWifi(const dist_t d) {
	maxn L = d.left, R = L + 1;
	maxn LL = findleft(L), RR = findright(R);

	rec = rec - cost(LL, RR) + cost(LL, L) + cost(R, RR);
	ms.push_back(L); ms.push_back(R);

	res = std::min(res, rec);
}


void Process() {
	res = rec = cost(0, n - 1);

	for (maxn i = 0; i < dist.size(); i++)
		MoreWifi(dist[i]);
}


int main() {
	//freopen("wifi.inp", "r", stdin);
	//freopen("wifi.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();

	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << res;
}