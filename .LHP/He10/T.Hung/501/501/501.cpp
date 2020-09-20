// AC UVa
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 30000
#define maxA 2000000000
#define minA -maxA

typedef int maxn;
typedef long long maxa;

maxa a[maxN];
maxn u[maxN], na, nu, I;
std::priority_queue <maxa, std::vector <maxa> > px;
std::priority_queue <maxa, std::vector <maxa>, std::greater<maxa> > pn;


void Prepare() {
	std::cin >> na >> nu;

	for (maxn i = 0; i < na; i++)
		std::cin >> a[i];
	for (maxn i = 0; i < nu; i++)
		std::cin >> u[i];
}


void Adjust(const maxn &I) {
	while (px.size() < I) {
		px.push(pn.top());
		pn.pop();
	}
	while (px.size() > I) {
		pn.push(px.top());
		px.pop();
	}
}


void Add(const maxa &x) {
	if (px.empty() || x < px.top()) px.push(x);
	else pn.push(x);
	Adjust(I);
}


void Get() {
	Adjust(I++);
	std::cout << px.top() << '\n';
}


void Init() {
	px = std::priority_queue <maxa, std::vector <maxa> >();
	pn = std::priority_queue <maxa, std::vector <maxa>, std::greater<maxa> >();
	I = 1;
}


void Process() {
	maxn ia = 0;
	for (maxn iu = 0; iu < nu; iu++) {
		while (px.size() + pn.size() < u[iu]) Add(a[ia++]);
		Get();
	}
}


int main() {
	std::ios_base::sync_with_stdio(0);

	long K;
	std::cin >> K;

	do {
		Init();
		Prepare();
		Process();
	} while (--K && std::cout << '\n');
}