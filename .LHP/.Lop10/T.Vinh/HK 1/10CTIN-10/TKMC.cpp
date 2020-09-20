#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>


#define maxN 301

typedef int maxn;

struct Pos {
	maxn x;
	maxn y;
};

std::queue <Pos> Queue;

char a[maxN][maxN];
long step[maxN][maxN];

Pos Tele[27], des;

maxn m, n;


bool isAlpha(char a) {
	return a >= 'A' && a <= 'Z';
}


Pos newPos(maxn x, maxn y) {
	Pos re;
	re.x = x;
	re.y = y;
	return re;
}


void addElement(maxn i, maxn j) {
	if (a[i][j] == '@') {
		Queue.push(newPos(i, j));
		step[i][j] = 1;
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
	freopen("TKMC.inp", "r", stdin);
	freopen("TKMC.out", "w", stdout);

	std::cin >> m >> n;

	for (maxn i = 0; i < m; i++)
		for (maxn j = 0; j < n; j++) {
			std::cin >> a[i][j];
			addElement(i, j);
		}
}


void Push(maxn x, maxn y, Pos prev) {

	if (isAlpha(a[x][y])) {
		char c = a[x][y];
		x = Tele[c - 'A'].x - x;
		y = Tele[c - 'A'].y - y;
	}

	step[x][y] = step[x][y] == 0 ? step[prev.x][prev.y] + 1 : std::min(step[x][y], step[prev.x][prev.y] + 1);

	Queue.push(newPos(x, y));
}


bool Fit(maxn i, maxn j) {
	return i >= 0 && i < m && j >= 0 && j < n && ((a[i][j] != '#' && step[i][j] == 0) || (isAlpha(a[i][j])));
}


void Add(Pos prev) {

	maxn x = prev.x;
	maxn y = prev.y;

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
