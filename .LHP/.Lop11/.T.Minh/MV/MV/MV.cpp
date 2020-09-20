#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include <algorithm>

#define maxN 65

typedef int maxn;
typedef long long maxa;

maxn N, K, M;
maxa d[maxN][maxN], f[maxN][maxN][maxN];
std::vector<maxn> V;


void Prepare() {
    std::cin >> N >> K >> M;
}


maxa DFS_STT(maxn I, maxa S, maxn T) {
    if (S == 0) return 1;

    maxa s = 0;
    if (I % 2 == 0)
        for (maxn i = 1; i < V[I]; i++)
            s += f[i][S][T];
    else
        for (maxn i = M; i > V[I]; i--)
            s += f[i][S][T];

    return s + DFS_STT(I + 1, S - V[I], T - 1);
}


void DFS_IDX(maxn I, maxa IDX, maxa S, maxn T) {
    if (T == 1) { 
        for (maxa i = 0; i < S; i++) std::cout << I; 
        return; 
    }
    if (IDX == 0) return;

    maxa s = 0;
    if (I == 1) {
        for (maxn i = 1; i <= M; i++)
            if (s + f[i][S][T] < IDX)
                s += f[i][S][T]; 
            else {
                for (maxn j = 1; j <= i; j++) std::cout << "1";
                DFS_IDX(1 - I, IDX - s, S - i, T - 1);
                break;
            }
    }
    else {
        for (maxn i = M; i >= 1; i--)
            if (s + f[i][S][T] < IDX)
                s += f[i][S][T];
            else{
                for (maxn j = 1; j <= i; j++) std::cout << "0";
                DFS_IDX(1 - I, IDX - s, S - i, T - 1);
                break;
            }
    }
    return;
}


void Process() {
    for (maxn i = 1; i <= M; i++) d[i][1] = 1;
    for (maxn i = 2; i <= N; i++) for (maxn j = 2; j <= std::min(i, K); j++) for (maxn l = i - 1; l >= std::max(1, i - M); l--)
        d[i][j] += d[l][j - 1];
    for (maxn i = 1; i <= M; i++) for (maxn j = 1; j <= N; j++) for (maxn l = 1; l <= K; l++) if (j - i > 0 && l - 1 > 0)
        f[i][j][l] = d[j - i][l - 1];
    std::cout << d[N][K] << '\n';

    maxn cnts;
    std::cin >> cnts;
    std::string s;
    std::cin.ignore();

    while (cnts--) {
        std::getline(std::cin, s);
        V.clear();
        maxn cnt = 1;
        for (maxn i = 1; i < s.size(); i++)
            if (s[i] == s[i - 1]) cnt++; 
            else {
                //std::cout << i << '\n';
                V.push_back(cnt);
                cnt = 1;
            }
        V.push_back(cnt);
        std::cout << DFS_STT(0, N, K) << '\n';
    }

    maxn t;
    std::cin >> t;
    while (t--) {
        maxa idx = 0;
        std::cin >> idx;
        DFS_IDX(1, idx, N, K);
        std::cout << '\n';
    }
}


int main() {
    freopen("mv.inp", "r", stdin);
    freopen("mv.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
