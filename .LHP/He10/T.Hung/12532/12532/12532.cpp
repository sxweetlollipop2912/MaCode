// AC UVa
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxN 100002
//#define maxK 100001
//#define maxA 100
//#define minA -100
//#define maxR 10000001
#define change 'C'
#define product 'P'

typedef long maxn, maxk, maxa;

struct operator_t {
	maxn plus, minus, zero;
};

maxn n;
maxk k;
operator_t a[maxN], bit[maxN], tmp[maxN];


operator_t wut(const maxa &x) {
	operator_t re;
	re.plus = re.zero = re.minus = 0;

	if (!x) re.zero = 1;
	else if (x > 0) re.plus = 1;
	else re.minus = 1;

	return re;
}

operator_t substract(operator_t re, const operator_t &a) {
	re.plus -= a.plus; re.minus -= a.minus; re.zero -= a.zero;
	return re;
}

operator_t add(operator_t re, const operator_t &a) {
	re.plus += a.plus; re.minus += a.minus; re.zero += a.zero;
	return re;
}


void Prepare() {
	for (maxn i = 1; i <= n; i++) {
		maxa tmp;
		std::cin >> tmp;
		a[i] = wut(tmp);
	}
}


void Build() {
	tmp[0].plus = tmp[0].zero = tmp[0].minus = 0;

	for (maxn i = 1; i <= n; i++) {
		tmp[i] = add(a[i], tmp[i - 1]);
		bit[i] = substract(tmp[i], tmp[i - (i & (-i))]);
	}
}


void Update(maxn id, const operator_t &c) {
	while (id <= n) {
		bit[id] = add(bit[id], c);
		id += id & (-id);
	}
}


operator_t GetSum(maxn id) {
	operator_t re;
	re.plus = re.zero = re.minus = 0;

	while (id > 0) {
		re = add(re, bit[id]);
		id -= id & (-id);
	}
	return re;
}


char Result(const operator_t &re) {
	if (re.zero) return '0';
	if (re.minus % 2 != 0) return '-';
	return '+';
}


void Process() {
	maxn tmp[3];

	while (k--) {
		char opt;
		std::cin >> opt;

		if (opt == change) {
			maxn x; maxa v;
			std::cin >> x >> v;

			Update(x, substract(wut(v), a[x]));
			a[x] = wut(v);
		}
		else {
			maxn i, j;
			std::cin >> i >> j;
			std::cout << Result(substract(GetSum(j), GetSum(i - 1)));
		}
	}
	std::cout << '\n';
}


int main() {
	//freopen("12532.inp", "r", stdin);
	//freopen("12532.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	while (std::cin >> n >> k) {
		Prepare();
		Build();
		Process();
	}
}