#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define maxN 51
#define maxL 101
#define maxF 2

typedef int maxn;
typedef std::string str;

const str maxA = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

struct pqueue {
	maxn x, y;
	str string;
};

maxn n;
char a[maxN][maxN];
int f[maxF][2] = { { 0,1 },{ 1,0 } };


pqueue newPQ(maxn x, maxn y, str string) {
	pqueue re;
	re.x = x; re.y = y; re.string = string;
	return re;
}


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i < n; i++)
		for (maxn j = 0; j < n; j++) {
			bool c;
			std::cin >> c;
			a[i][j] = c + '0';
		}
}


str minc[maxN][maxN];
bool done[maxN][maxN];

class cmp {
public:
		bool operator() (const pqueue &p1, const pqueue &p2) {
		str s1 = p1.string, s2 = p2.string;

		while (s1.size() < s2.size()) s1 = '0' + s1;
		while (s2.size() < s1.size()) s2 = '0' + s2;

		return s1 > s2;
	}
};
std::priority_queue < pqueue, std::vector <pqueue>, cmp > pq;


bool comp(str s1, str s2) {
	while (s1.size() < s2.size()) s1 = '0' + s1;
	while (s2.size() < s1.size()) s2 = '0' + s2;

	return s1 > s2;
}


bool check(maxn x, maxn y) {
	return x < n && y < n;
}


void Fill(maxn x, maxn y) {
	for (maxn i = 0; i < maxF; i++) {
		maxn x1 = x + f[i][0], y1 = y + f[i][1];

		if (!check(x1, y1) || done[x1][y1] || !comp(minc[x1][y1], minc[x][y] + a[x1][y1])) continue;

		minc[x1][y1] = minc[x][y] + a[x1][y1];
		pq.push(newPQ(x1, y1, minc[x1][y1]));
	}
}


pqueue Find() {
	while (!pq.empty() && done[pq.top().x][pq.top().y]) pq.pop();
	if (pq.empty()) return newPQ(-1, -1, "");

	pqueue re = pq.top();
	pq.pop();

	return re;
}


void Dijkstra() {
	for (maxn i = 0; i < n; i++) std::fill(minc[i], minc[i] + n, maxA);

	minc[0][0] = a[0][0];
	pqueue cur = newPQ(0, 0, minc[0][0]);
	
	while (cur.x != -1 && cur.y != -1) {
		done[cur.x][cur.y] = 1;
		Fill(cur.x, cur.y);
		cur = Find();
	}
}


int main() {
	Prepare();
	Dijkstra();
	std::cout << minc[n - 1][n - 1];
}