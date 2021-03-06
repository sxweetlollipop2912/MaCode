// more accurate _ fail on test 3
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

#pragma warning (disable:4996)

#define maxN 301

typedef int maxn;

struct Pos {
	maxn x;
	maxn y;
	bool c;
};

std::queue <Pos> Queue;

char a[maxN][maxN];
long step[maxN][maxN];
long stp_ina[maxN][maxN];

Pos Tele[27], des, pos;
bool activ[27];

maxn m, n;


bool isAlpha(char a) {
	return a >= 'A' && a <= 'Z';
}


void addElement(maxn i, maxn j) {
	if (a[i][j] == '@') {
		pos.x = i;
		pos.y = j;
	}
	else if (a[i][j] == '=') {
		des.x = i;
		des.y = j;
	}
	else if (isAlpha(a[i][j])) {
		Tele[a[i][j] - 'A'].x += i;
		Tele[a[i][j] - 'A'].y += j;
	}
}


void Prepare() {
	//freopen("TKMC.inp", "r", stdin);
	//freopen("TKMC.out", "w", stdout);

	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			std::cin >> a[i][j];
			addElement(i, j);
		}
}


Pos newPos(maxn x, maxn y, bool c) {
	Pos re;
	re.x = x;
	re.y = y;
	re.c = c;
	return re;
}


void Push(maxn x, maxn y, Pos prev) {

	if (isAlpha(a[x][y])) 
		stp_ina[x][y] = stp_ina[x][y] == 0 ? step[prev.x][prev.y] + 1 : 
		                                     std::min(stp_ina[x][y], step[prev.x][prev.y] + 1);

	else step[x][y] = step[prev.x][prev.y] + 1;

	Queue.push(newPos(x, y, 0));
}


void pushAlpha(maxn x, maxn y) {
	char c = a[x][y];
	maxn i = Tele[c - 'A'].x - x;
	maxn j = Tele[c - 'A'].y - y;

	step[i][j] = step[i][j] == 0 ? stp_ina[x][y] : std::min(step[i][j], stp_ina[x][y]);

	Queue.push(newPos(i, j, 1));
}


bool Fit(maxn i, maxn j) {
	return i >= 0 && i < m && j >= 0 && j < n && ((a[i][j] != '#' && step[i][j] == 0) || (isAlpha(a[i][j])));
}


void Add(Pos prev) {
	
	maxn x = prev.x;
	maxn y = prev.y;
	bool c = prev.c;

	if (!c && isAlpha(a[x][y])) {
		pushAlpha(x, y);
		return;
	}

	if (Fit(x + 1, y)) 
		Push(x + 1, y, prev);

	if (Fit(x - 1, y))
		Push(x - 1, y, prev);

	if (Fit(x, y + 1))
		Push(x, y + 1, prev);

	if (Fit(x, y - 1))
		Push(x, y - 1, prev);
}


void BFS() {
	Queue.push(pos);
	step[pos.x][pos.y] = 1;

	while (step[des.x][des.y] == 0 && !Queue.empty()) {
		Add(Queue.front());
		Queue.pop();
	}
}


int main() {
	Prepare();
	BFS();
	std::cout << step[des.x][des.y] - 1;
}