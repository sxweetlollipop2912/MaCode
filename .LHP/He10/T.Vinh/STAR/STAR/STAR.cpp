#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define maxN 13
#define maxA 13
#define maxF 8
#define none 'x'
#define SUM 26
#define toChar(x) (char)((x) + 'A' - 1)

typedef int maxn, maxa;

//maxa num[maxN];
std::vector <maxa> num(maxN, 0);
std::vector <bool> done(maxA, 0);
maxn line[6][4] = { {0,2,5,7},{0,3,6,10},{1,2,3,4},{7,8,9,10},{1,5,8,11},{4,6,9,11} };
maxn iline[12][2] = { {0,1},{2,4},{0,2},{1,2},{2,5},{0,4},{1,5},{0,3},{3,4},{3,5},{1,3},{4,5} };
//bool done[maxA];


bool Set(const maxn &id, const maxa &x, std::vector <maxa> &num, std::vector <bool> &done) {
	if (x <= 0 || x >= maxA || done[x]) return 0;
	num[id] = x;
	done[x] = 1;
	return 1;
}


bool Fline(const maxn &lid, std::vector <maxa> &num, std::vector <bool> &done) {
	maxn fill = -1;
	maxa sum = 0;

	for (maxn il = 0; il < 4; il++) {
		sum += num[line[lid][il]];

		if (num[line[lid][il]]) continue;
		if (fill == -1) fill = line[lid][il];
		else {
			fill = -1;
			break;
		}
	}
	if (fill != -1 && !Set(fill, SUM - sum, num, done)) return 0;
	return 1;
}


void Prepare() {
	char dot, n1, n2, n3, n4;
	maxn cnt = -1;
	
	std::cin >> dot >> dot >> dot >> dot >> n1 >> dot >> dot >> dot >> dot;
	if (++cnt || n1 != none) Set(cnt, n1 - 'A' + 1, num, done);

	std::cin >> dot >> n1 >> dot >> n2 >> dot >> n3 >> dot >> n4 >> dot;
	if (++cnt && n1 != none) Set(cnt, n1 - 'A' + 1, num, done);
	if (++cnt && n2 != none) Set(cnt, n2 - 'A' + 1, num, done);
	if (++cnt && n3 != none) Set(cnt, n3 - 'A' + 1, num, done);
	if (++cnt && n4 != none) Set(cnt, n4 - 'A' + 1, num, done);

	std::cin >> dot >> dot >> n1 >> dot >> dot >> dot >> n2 >> dot >> dot;
	if (++cnt && n1 != none) Set(cnt, n1 - 'A' + 1, num, done);
	if (++cnt && n2 != none) Set(cnt, n2 - 'A' + 1, num, done);

	std::cin >> dot >> n1 >> dot >> n2 >> dot >> n3 >> dot >> n4 >> dot;
	if (++cnt && n1 != none) Set(cnt, n1 - 'A' + 1, num, done);
	if (++cnt && n2 != none) Set(cnt, n2 - 'A' + 1, num, done);
	if (++cnt && n3 != none) Set(cnt, n3 - 'A' + 1, num, done);
	if (++cnt && n4 != none) Set(cnt, n4 - 'A' + 1, num, done);

	std::cin >> dot >> dot >> dot >> dot >> n1 >> dot >> dot >> dot >> dot;
	if (++cnt || n1 != none) Set(cnt, n1 - 'A' + 1, num, done);

	for (maxn i = 0; i < 6; i++) Fline(i, num, done);
}


void Output(std::vector <maxa> &num) {
	char dot = '.';
	std::cout << dot << dot << dot << dot << toChar(num[0]) << dot << dot << dot << dot << '\n';

	std::cout << dot << toChar(num[1]) << dot << toChar(num[2]) << dot << toChar(num[3]) << dot << toChar(num[4]) << dot << '\n';

	std::cout << dot << dot << toChar(num[5]) << dot << dot << dot << toChar(num[6]) << dot << dot << '\n';

	std::cout << dot << toChar(num[7]) << dot << toChar(num[8]) << dot << toChar(num[9]) << dot << toChar(num[10]) << dot << '\n';

	std::cout << dot << dot << dot << dot << toChar(num[11]) << dot << dot << dot << dot << '\n';
}


bool Try(std::vector <maxa> num, std::vector <bool> done) {
	maxn id = 0;
	while (id < maxN - 1 && num[id]) ++id;
	if (id == maxN - 1) {
		Output(num);
		return 1;
	}
	
	for (maxa i = 1; i < maxA; i++) {
		std::vector <maxa> num2 = num;
		std::vector <bool> done2 = done;
		if (!Set(id, i, num2, done2) || !Fline(iline[id][0], num2, done2) || !Fline(iline[id][1], num2, done2)) continue;
		if (Try(num2, done2)) return 1;
	}
	
	return 0;
}


void Process() {
	Try(num, done);
}


int main() {
	//freopen("star.inp", "r", stdin);
	//freopen("star.out", "w", stdout);

	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}