#include <iostream>
#include <cstdio>
#include <algorithm>

#define maxn 1001

using namespace std;

typedef pair<int, int> pii;

int td[] = { 1,1,2,2,-1,-1,-2,-2 };
int tc[] = { 2,-2,1,-1,2,-2,1,-1 };
int n, m, X, Y;
int a[maxn][maxn];
pii kq[10000000];

bool fine(int x, int y)
{
	if (x <= n && x >= 1 && y <= m && y >= 1 && a[x][y] == -1) return 1;
	return 0;
}

int degree(int x, int y)
{
	int res = 0;
	for (int i = 0; i < 8; i++) {
		int xx = x + td[i];
		int yy = y + tc[i];
		if (fine(xx, yy)) res++;
	}
	return res;
}

bool nextMove(int& x, int& y)
{
	int xx, yy, mn = 9, tmp;
	pii ok;
	xx = x;
	for (int i = 0; i < 8; i++) {
		xx = x + td[i];
		yy = y + tc[i];
		if (fine(xx, yy) && (tmp = degree(xx, yy)) < mn) {
			mn = tmp;
			ok = pii(xx, yy);
		}
	}
	if (mn == 9) return 0;
	a[ok.first][ok.second] = a[x][y] + 1;
	x = ok.first; y = ok.second;
	return 1;
}

bool neighbour(int x, int y, int xx, int yy)
{
	for (int i = 0; i < 8; i++)
		if ((x + td[i] == xx) && y + tc[i] == yy) return 1;
	return 0;
}

bool findClosedTour(int sx, int sy)
{
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		a[i][j] = -1;

	a[sx][sy] = 1;
	int x = sx, y = sy;
	for (int i = 0; i < n * n - 1; i++)
		if (nextMove(x, y) == 0)
			return 0;

	if (!neighbour(x, y, sx, sy)) return 0;

	int k = a[X][Y];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		a[i][j] -= (k - 1);
		if (a[i][j] < 0) a[i][j] += n * m;
		if (a[i][j] == 0) a[i][j] = n * m;
		kq[a[i][j]] = pii(i, j);
	}

	for (int i = 1; i <= n * m; i++)
		cout << kq[i].first << ' ' << kq[i].second << '\n';
	return 1;
}

int main()
{
	//freopen("WSDORFF.INP", "r", stdin);
	//freopen("WSDORFF.OUT", "w", stdout);

	cin >> n >> m >> X >> Y;
	//n<=m
	if (n % 2 && m % 2) { cout << -1; return 0; }
	if ((n == 1 || n == 2 || n == 4) && (m != 1)) { cout << -1; return 0; }
	if (n == 3 && (m == 4 || m == 6 || m == 8)) { cout << -1; return 0; }
	//OK
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (findClosedTour(i, j)) return 0;

	cout << -1;
	return 0;
}
