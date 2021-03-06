// fail on test 3
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <queue>

#pragma warning (disable:4996)

#define maxN 301

typedef int maxn;

struct Pos {
	maxn x;
	maxn y;
};

std::queue <Pos> Queue;

char a[maxN][maxN];
long step[maxN][maxN];

Pos Tele[27];
bool done[27];

maxn m, n;

Pos pos, des;


void addPos(maxn i, maxn j) {
	char c = a[i][j];

	if (c >= 'A' && c <= 'Z') {
		Tele[c - 'A'].x += i;
		Tele[c - 'A'].y += j;
	}

	else if (c == '@') {
		pos.x = i;
		pos.y = j;
	}

	else if (c == '=') {
		des.x = i;
		des.y = j;
	}
}


void Prepare() {
	freopen("TKMC.inp", "r", stdin);
	//freopen("TKMC.out", "w", stdout);

	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			std::cin >> a[i][j];
			addPos(i, j);
		}
	}
}


Pos newPos(maxn i, maxn j) {
	pos.x = i;
	pos.y = j;
	return pos;
}


bool Fit(Pos pos) {
	maxn i = pos.x, j = pos.y;
	return i >= 0 && i < m && j >= 0 && j < n  && ((a[i][j] >= 'A' && a[i][j] <= 'Z') || a[i][j] != '#' && step[i][j] == 0);
}


void Push(Pos prev) {
	step[pos.x][pos.y] = step[prev.x][prev.y] + 1;
	Queue.push(pos);
}


void pushAlpha(maxn i, maxn j) {
	char c = a[i][j];
	maxn x = Tele[c - 'A'].x - i;
	maxn y = Tele[c - 'A'].y - j;


	step[x][y] = step[i][j];
	Queue.push(newPos(x, y));
}

void Add(Pos prev) {
	maxn i = prev.x, j = prev.y;

	if (a[i][j] >= 'A' && a[i][j] <= 'Z') {

		if (!done[a[i][j] - 'A']) {
			pushAlpha(i, j);
			done[a[i][j] - 'A'] = 1;
			return;
		}

		done[a[i][j] - 'A'] = 0;

	}

	if (Fit(newPos(i, j + 1))) 
		Push(prev);

	if (Fit(newPos(i, j - 1)))
		Push(prev);

	if (Fit(newPos(i + 1, j)))
		Push(prev);

	if (Fit(newPos(i - 1, j)))
		Push(prev);
}


void BFS() {
	Queue.push(pos);
	step[pos.x][pos.y] = 1;

	while (step[des.x][des.y] == 0) {
		Add(Queue.front());
		Queue.pop();
	}
}


int main() {
	Prepare();
	BFS();
	std::cout << step[des.x][des.y] - 1;
	/*std::cout << m << n;
	for (maxn i = 0; i < m; i++) {
		for (maxn j = 0; j < n; j++) {
			std::cout << a[i][j];
		}
		std::cout << '\n';
	}*/
}