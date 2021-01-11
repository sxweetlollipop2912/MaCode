#include <iostream>
#include <cstdio>
//#include <string.h>
#include <algorithm>
#include <queue>
#include <math.h>

#define maxN 255
#define maxA 50001
//#define MaxInt 9999999
#define x first
#define y second
#define d(x1, y1, x2, y2) sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
#define up n
#define down (n + 1)
#define N (n + 2)
//#define delta 1

typedef int maxn;
typedef double maxa;
typedef std::pair <maxn, maxn> co_t;

maxn n;
maxa R, C;
bool c[maxN][maxN];
maxn f[maxN][maxN], trace[maxN];
co_t co[maxN];


void Prepare() {
    std::cin >> C >> R >> n;
    for(maxn i = 0; i < n; i++) std::cin >> co[i].x >> co[i].y;

    for(maxn i = 0; i < n; i++) {
        for(maxn j = i + 1; j < n; j++) c[i][j] = c[j][i] = (d(co[i].x, co[i].y, co[j].x, co[j].y) <= 200);
        if (co[i].y <= 100) c[i][down] = c[down][i] = 1;
        if (R - co[i].y <= 100) c[i][up] = c[up][i] = 1;
    }
    /*for(maxn i = 0; i < N; i++) {
        for(maxn j = 0; j < N; j++) std::cout << c[i][j] << ' ';
        std::cout << '\n';
    }*/
}


bool findpath() {
    maxn u;
    std::queue<maxn> q;
    std::fill(trace, trace + maxN, -1);
    q.push(down);
    trace[down] = down; //Trace[v]=- <=> v chua tham
    do {
        u = q.front(); q.pop();
        for (maxn v = 0; v < N; v++) {
            if (trace[v] == -1 && (maxn)c[u][v] > f[u][v]) {
                trace[v] = u;
                if (v == up) return 1;
                q.push(v);
            }
        }
    }while (!q.empty());
    return 0;
}


void incflow() {
    maxn u, v, delta = 1;
    //Tinh delta=ΔP
    /*delta=999999999;
    v=up;
    do{ u=trace[v]; //Xet cung (u,v) tren duong di P, voi u la dinh tham truoc v
        if (c[u][v]-f[u][v]<delta)
            delta=c[u][v]-f[u][v]; //Tim gia tri cf[u,v] nho nhat
        v=u;
    } while (v!=down);*/
    v = up;
    do { u = trace[v];
         f[u][v] = f[u][v] + delta;
         f[v][u] = f[v][u] - delta;
         v = u;
    } while (v != down);
}


void printresult() {
    maxn m = 0;
    for (maxn u = 0; u < N; u++)
        for (maxn v = 0; v < N; v++)
            if (f[u][v] > 0) {
                //std::cout<<"f["<<u<<", "<<v<<"]="<<f[u][v]<<'\n';
                if (u == down) m += f[down][v];
            }
    std::cout << m;
}


void Process() {
    while (findpath()) incflow();
    printresult();
}


int main() {
    //freopen("MAXFLOW.INP","r",stdin);
    //freopen("MAXFLOW.OUT","w",stdout);

    Prepare();
    Process();
}
