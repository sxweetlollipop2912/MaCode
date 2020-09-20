// AC Kattis
#include <iostream>
#include <algorithm>

#define maxN 103
#define x first
#define y second
#define st 0
#define en (n + 1)
#define MAX (20 * 50)

typedef int maxn, maxa;
typedef std::pair <maxa, maxa> co;

maxn n;
co Co[maxN];
bool reach[maxN][maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = 0; i <= n + 1; i++) {
		maxa X, Y;
		std::cin >> X >> Y;
		Co[i].x = X, Co[i].y = Y;
	}
}


void Floyd() {
	for (maxn k = 0; k <= n + 1; k++) {
		for (maxn i = 0; i <= n + 1; i++) {
			for (maxn j = 0; j <= n + 1; j++) {
				reach[i][j] = reach[i][j] | (reach[i][k] & reach[k][j]);
			}
		}
	}
}


void Process() {
	for (maxn i = 0; i <= n + 1; i++) {
		for (maxn j = 0; j <= n + 1; j++) {
			reach[i][j] = reach[j][i] = abs(Co[i].x - Co[j].x) + abs(Co[i].y - Co[j].y) <= MAX;
		}
	}
	Floyd();

	if (reach[st][en]) std::cout << "happy\n";
	else std::cout << "sad\n";
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int q;
	std::cin >> q;

	while (q--) {
		Prepare();
		Process();
	}
}