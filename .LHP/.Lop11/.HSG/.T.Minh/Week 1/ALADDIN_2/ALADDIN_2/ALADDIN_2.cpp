#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>

#define maxN 10001
#define BASE 1000000000
#define DIGITS 9

typedef long long maxa;
typedef std::vector <maxa> v_t;

maxa m, n;


void make_place(v_t& v, maxa pos, maxa def = 0) {
	while (v.size() <= pos) v.push_back(def);
}


void NùmToArray10(maxa a, v_t& re) {
	re.clear();
	while (a != 0) {
		re.push_back(a % 10);
		a /= 10;
	}
}


void ConvertTo10(v_t const &v, v_t& re) {
	re.clear();
	for (maxa i = 0; i < v.size(); i++) {
		maxa cur = v[i];
		while (cur != 0) {
			re.push_back(cur % 10);
			cur /= 10;
		}
		while (re.size() % DIGITS != 0) re.push_back(0);
	}
}


void ConvertTo1e9(v_t const& v, v_t& re) {
	re.clear();
	maxa cur = 0;
	for (maxa i = 0; i < v.size(); i++) {
		cur = cur * 10 + v[i];
		if (cur < BASE) continue;
		re.push_back(cur % BASE); cur /= BASE;
	}
	if (cur) re.push_back(cur);
}


void Multi_1e9(v_t v1, v_t v2, v_t& re) {
	re.clear();

	for (maxa i = 0; i < v1.size(); i++) for (maxa j = 0; j < v2.size(); j++) {
		make_place(re, i);  re[i] += v1[i] * v2[i];
		if (re[i] < BASE) continue;
		make_place(re, i + 1);
		re[i + 1] = re[i] % BASE, re[i] /= BASE;
	}

	for (maxa i = v1.size(); i < re.size(); i++) {
		if (re[i] < BASE) continue;
		make_place(re, i + 1);
		re[i + 1] = re[i] % BASE, re[i] /= BASE;
	}
}


void Pow(v_t v, maxa power, v_t& re) {
	re.push_back(1);
	while (power) {
		if (power % 2) Multi_1e9(re, v, re);
		Multi_1e9(v, v, v);
		power /= 2;
	}
}


void Prepare() {
	std::cin >> n >> m;
}


void Process() {

}


int main() {
	
}