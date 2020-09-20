#include <iostream>
#include <algorithm>

#define maxN 52
#define be 1
#define en n

typedef int maxn;

maxn n, f[maxN][maxN][maxN][maxN]; //s[maxN][maxN];
bool done[maxN][maxN][maxN][maxN];


void Prepare() {
	std::cin >> n;

	for (maxn i = be; i <= en; i++) {
		for (maxn j = be; j <= en; j++) {
			char c;
			std::cin >> c;
			f[i][j][i][j] = (c == '#');
			done[i][j][i][j] = 1;
			//s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + f[i][j][i][j];
		}
	}
}


maxn TD(const maxn x1, const maxn y1, const maxn x2, const maxn y2) {
	if (done[x1][y1][x2][y2]) return f[x1][y1][x2][y2];

	done[x1][y1][x2][y2] = 1;
	//if (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] == 0) return (f[x1][y1][x2][y2] = 0);

	f[x1][y1][x2][y2] = std::max(x2 - x1 + 1, y2 - y1 + 1);

	for (maxn i = x1; i < x2; i++) 
		f[x1][y1][x2][y2] = std::min(f[x1][y1][x2][y2], TD(x1, y1, i, y2) + TD(i + 1, y1, x2, y2));

	for (maxn j = y1; j < y2; j++) 
		f[x1][y1][x2][y2] = std::min(f[x1][y1][x2][y2], TD(x1, y1, x2, j) + TD(x1, j + 1, x2, y2));

	return f[x1][y1][x2][y2];
}


void Process() {
	std::cout << TD(be, be, en, en);
}


int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	Prepare();
	Process();
}