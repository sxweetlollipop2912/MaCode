#include <iostream>
#include <cstdio>

#define maxN 301

typedef int maxn;
typedef char maxa;

maxa a[maxN][maxN];
bool done[maxN][maxN];
maxn m,n;

bool f[8][4]= {{1,0,1,1},{1,1,0,1},{0,1,1,1},{1,1,1,0},{0,0,1,1},{0,1,0,1},{1,1,0,0},{1,0,1,0}};

void Prepare() {
    freopen("TROCHOI.inp","r",stdin);
    freopen("TROCHOI.out","w",stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin >> m >> n;
    for(maxn i = 0; i < m; i++)
        for(maxn j = 0; j < n; j++) {
            std::cin >> a[i][j];
            a[i][j] -= 'A';
        }
}


void Try(maxn i, maxn j) {

    done[i][j] = 1;

    if (j + 1 < n && !done[i][j + 1]) {
        maxa x = a[i][j];
        maxa y = a[i][j + 1];
        if ((f[x][1] && f[y][0]) || (f[x][3] && f[y][2])) Try(i, j + 1);
    }

    if (i + 1 < m && !done[i + 1][j]) {
        maxa x = a[i][j];
        maxa y = a[i + 1][j];
        if ((f[x][2] && f[y][0]) || (f[x][3] && f[y][1])) Try(i + 1, j);
    }

    if (j - 1 >= 0 && !done[i][j - 1]) {
        maxa x = a[i][j];
        maxa y = a[i][j - 1];
        if ((f[y][1] && f[x][0]) || (f[y][3] && f[x][2])) Try(i, j - 1);
    }

    if (i - 1 >= 0 && !done[i - 1][j]) {
        maxa x = a[i][j];
        maxa y = a[i - 1][j];
        if ((f[y][2] && f[x][0]) || (f[y][3] && f[x][1])) Try(i - 1, j);
    }

}

int main() {
     Prepare();

     long re = 0;
     for(maxn i = 0; i < m; i++)
        for(maxn j = 0; j < n; j++) {
            if (done[i][j]) continue;
            Try(i,j);
            re++;
        }

     std::cout << re;
}
