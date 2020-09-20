#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

#define maxN 14
#define N 11
#define real 1
#define unsure 0
#define light -1
#define heavy 1
#define num(x) ((x) - 'A')

typedef int t;
typedef std::string str;

bool isReal[maxN];
t sta[maxN], cnt[maxN], CNT;


void Real(const str& s) {
	for (t i = 0; i < s.size(); i++) 
		isReal[num(s[i])] = real;
}
void Light(const str& s) {
	for (t i = 0; i < s.size(); i++) {
		if (sta[num(s[i])] == heavy) isReal[num(s[i])] = real;
		sta[num(s[i])] = light, ++cnt[num(s[i])];
	}
}
void Heavy(const str& s) {
	for (t i = 0; i < s.size(); i++) {
		if (sta[num(s[i])] == light) isReal[num(s[i])] = real;
		sta[num(s[i])] = heavy, ++cnt[num(s[i])];
	}
}


void Prepare() {
	std::fill(isReal, isReal + maxN, unsure);
	std::fill(sta, sta + maxN, unsure);
	std::fill(cnt, cnt + maxN, 0);
	CNT = 0;

	for (int i = 0; i < 3; i++) {
		str s1, s2, re;
		std::cin >> s1 >> s2 >> re;

		if (re == "bang") {
			Real(s1); Real(s2);
		}
		else if (re == "nhe") {
			++CNT;
			Light(s1); Heavy(s2);
		}
		else {
			++CNT;
			Light(s2); Heavy(s1);
		}
	}
}


void Process() {
	t i, res = N + 1;
	for (i = 0; i <= N; i++) {
		if (isReal[i] == real || cnt[i] < cnt[res]) continue;
		res = i;
	}
	std::cout << (char)(res + 'A');
	if (sta[i] == light) std::cout << ", nhe hon\n";
	else std::cout << ", nang hon\n";
}


int main() {
	freopen("xugia.inp", "r", stdin);
	freopen("xugia.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}