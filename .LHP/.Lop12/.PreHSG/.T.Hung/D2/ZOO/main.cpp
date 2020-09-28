#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define maxN 1001
#define maxMN 1000001
#define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)
#define Empty ((char)(E))

typedef int maxn;
typedef std::string str;
typedef std::pair <maxn, maxn> co_t;

maxn m, n, f[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } }, root[maxMN], rank[maxMN], root2[maxN], rank2[maxN], num[maxN][maxN], NUM, res;
str a[maxN];


void Prepare() {
    std::cin >> m >> n;

    std::cin.ignore();
    for(maxn i = 0; i < m; i++) std::getline(std::cin, a[i]);
}


maxn Root(maxn x, maxn root[]) {
    while (x != root[x]) x = root[x];
    return x;
}


bool Union(maxn x, maxn y, maxn root[], maxn rank[]) {
    x = Root(x), y = Root(y);

    if (x == y) return 0;

    if (rank[x] < rank[y]) root[y] = x;
    else root[x] = y, ++rank[x];
}


void DFS(const maxn ux, const maxn uy, const maxn Num) {
    num[ux][uy] = Num;
    std::cout << ux << ' ' << uy << ' ' << Num << '\n';
    NUM = std::max(NUM, Num);

    for(int k = 0; k < 4; k++) {
        maxn vx = ux + f[k][0], vy = uy + f[k][1];

        if (!valid(vx, vy) || a[vx][vy] == '*') continue;

        if (!num[vx][vy]) {
            if (a[vx][vy] != a[ux][uy]) {
                root[Num + 1] = Num + 1;
                DFS(vx, vy, Num + 1);
            }
            else DFS(vx, vy, Num);
        }
        else if (a[vx][vy] == a[ux][uy])
            Union(num[ux][uy], num[vx][vy]);
    }
}


void Process() {
    root[1] = 1;
    DFS(0, 0, 1);

    for(maxn i = 0; i < m; i++, std::cout << '\n') for(maxn j = 0; j < n; j++) std::cout << num[i][j] << ' ';

    for(maxn i = 1; i <= NUM; i++)
        if (root[i] == i) ++res;
    std::cout << res;
}


int main() {
    freopen("zoo.inp", "r", stdin);
    Prepare();
    Process();
}
