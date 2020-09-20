#include "pch.h"
#include <iostream>
#include <queue>

#define maxN 51

typedef int maxn;

struct QueueQ {
	maxn q1, q2, q3, time;
};

maxn n, res;
QueueQ start;
char a[maxN][maxN];
std::queue <QueueQ> Queue;
bool done[maxN][maxN][maxN], halt;


QueueQ newQ(maxn q1, maxn q2, maxn q3, maxn time) {
	QueueQ re;
	re.q1 = q1; re.q2 = q2; re.q3 = q3; re.time = time;
	return re;
}


void Prepare() {
	std::cin >> n >> start.q1 >> start.q2 >> start.q3;
	start.q1--; start.q2--; start.q3--; start.time = 0;

	for (maxn i = 0; i < n; i++)
		for (maxn j = 0; j < n; j++) std::cin >> a[i][j];
}


void Done(QueueQ Q) {
	done[Q.q1][Q.q2][Q.q3] = 1;
	done[Q.q1][Q.q3][Q.q2] = 1;
	done[Q.q2][Q.q1][Q.q3] = 1;
	done[Q.q2][Q.q3][Q.q1] = 1;
	done[Q.q3][Q.q1][Q.q2] = 1;
	done[Q.q3][Q.q2][Q.q1] = 1;
}


bool check(QueueQ Q) {
	return Q.q1 == Q.q2 && Q.q2 == Q.q3;
}


void Try(maxn q, maxn q2, maxn q3, maxn time) {
	char key = a[q2][q3];
	for (maxn i = 0; i < n && !halt; i++)
		if (i != q && a[q][i] == key && !done[i][q2][q3]) {
			Queue.push(newQ(i, q2, q3, time + 1));
			Done(Queue.back());
			
			if (!check(Queue.back())) continue;
			halt = 1;
			res = Queue.back().time;
		}
}


void Add(QueueQ Q) {
	Try(Q.q1, Q.q2, Q.q3, Q.time);
	Try(Q.q2, Q.q1, Q.q3, Q.time);
	Try(Q.q3, Q.q2, Q.q1, Q.time);
}


void BFS() {
	Queue.push(start);
	halt = check(Queue.back());
	res = 0;
	
	while (!Queue.empty() && !halt) {
		Add(Queue.front());
		Queue.pop();
	}
}


int main() {
	Prepare();
	BFS();
	if (halt) std::cout << res;
	else std::cout << "NO";
}