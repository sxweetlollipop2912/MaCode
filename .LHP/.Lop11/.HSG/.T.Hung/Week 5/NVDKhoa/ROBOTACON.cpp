#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#define robot pair<int,int>
#define mp make_pair
#define x first
#define y second
using namespace std;

const int N = 15;
int n, m, r, lim;
char s[N][N];
robot a, b, c, d, e, plot, w[N][N][4];

void Check(robot a, robot &e, robot b)
{
    if (a.x == e.x && b.x == e.x) {
        if (a.y<b.y && b.y<=e.y) e.y = b.y - 1; else
        if (e.y<=b.y && b.y<a.y) e.y = b.y + 1;
    } else
    if (a.y == e.y && b.y == e.y) {
        if (a.x<b.x && b.x<=e.x) e.x = b.x - 1; else
        if (e.x<=b.x && b.x<a.x) e.x = b.x + 1;
    }
}
int Bfs()
{
    set<pair<pair<robot, robot>, pair<robot, robot> > > vis;
    queue<pair<pair<robot, robot>, pair<robot, robot> > > Q;
    queue<int> f; int step;

    f.push(0);
    Q.push(mp(mp(a, b), mp(c, d)));
    vis.insert(mp(mp(a, b), mp(c, d)));
    while (!Q.empty()) {
        a = Q.front().x.x; b = Q.front().x.y;
        c = Q.front().y.x; d = Q.front().y.y;
        step = f.front(); Q.pop(); f.pop();

        /// robot a
        for(int k=0; k<4; ++k) {
            e = w[a.x][a.y][k];
            Check(a, e, b); Check(a, e, c); Check(a, e, d);
            if (!vis.count(mp(mp(e, b), mp(c, d)))) {
                if (e == plot) return step + 1;
                vis.insert(mp(mp(e, b), mp(c, d)));
                if (step + 1 < lim) {
                    f.push(step + 1);
                    Q.push(mp(mp(e, b), mp(c, d)));
                }
            }
        }
        /// robot b
        if (b.x && b.y)
        for(int k=0; k<4; ++k) {
            e = w[b.x][b.y][k];
            Check(b, e, a); Check(b, e, c); Check(b, e, d);
            if (!vis.count(mp(mp(a, e), mp(c, d)))) {
                vis.insert(mp(mp(a, e), mp(c, d)));
                if (step + 1 < lim) {
                    f.push(step + 1);
                    Q.push(mp(mp(a, e), mp(c, d)));
                }
            }
        }
        /// robot c
        if (c.x && c.y)
        for(int k=0; k<4; ++k) {
            e = w[c.x][c.y][k];
            Check(c, e, a); Check(c, e, b); Check(c, e, d);
            if (!vis.count(mp(mp(a, b), mp(e, d)))) {
                vis.insert(mp(mp(a, b), mp(e, d)));
                if (step + 1 < lim) {
                    f.push(step + 1);
                    Q.push(mp(mp(a, b), mp(e, d)));
                }
            }
        }
        /// robot d
        if (d.x && d.y)
        for(int k=0; k<4; ++k) {
            e = w[d.x][d.y][k];
            Check(d, e, a); Check(d, e, c); Check(d, e, b);
            if (!vis.count(mp(mp(a, b), mp(c, e)))) {
                vis.insert(mp(mp(a, b), mp(c, e)));
                if (step + 1 < lim) {
                    f.push(step + 1);
                    Q.push(mp(mp(a, b), mp(c, e)));
                }
            }
        }
    }
    return -1;
}
int main()
{
    freopen("ROBOTACON.inp","r",stdin);
    freopen("ROBOTACON.out","w",stdout);

    scanf("%d%d%d%d",&r,&m,&n,&lim);
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        scanf(" %c",&s[i][j]);
        if ('1' <= s[i][j] && s[i][j] <= '4') {
            if (s[i][j] == '1') a = mp(i, j); else
            if (s[i][j] == '2') b = mp(i, j); else
            if (s[i][j] == '3') c = mp(i, j); else
            if (s[i][j] == '4') d = mp(i, j);
        }
        if (s[i][j] == 'X') plot = mp(i, j);
    }

    for(int i=1; i<=n; ++i) s[i][0] = s[i][m+1] = 'W';
    for(int j=1; j<=m; ++j) s[0][j] = s[n+1][j] = 'W';
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        w[i][j][0] = s[i-1][j] == 'W' ? mp(i, j) : w[i-1][j][0];
        w[i][j][3] = s[i][j-1] == 'W' ? mp(i, j) : w[i][j-1][3];
    }
    for(int i=n; i>=1; --i) for(int j=m; j>=1; --j) {
        w[i][j][1] = s[i][j+1] == 'W' ? mp(i, j) : w[i][j+1][1];
        w[i][j][2] = s[i+1][j] == 'W' ? mp(i, j) : w[i+1][j][2];
    }

    printf("%d",Bfs());
}
