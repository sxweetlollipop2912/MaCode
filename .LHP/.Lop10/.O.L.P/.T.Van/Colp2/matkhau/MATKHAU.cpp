#include <iostream>
#include <cstdio>
#include <string>

#define maxN 1000001
#define maxC 3
#define so 0
#define thg 1
#define hoa 2
#define minL 6

typedef char maxa;
typedef std::string str;
typedef long long maxn, maxr;
typedef int maxc;

str a;
maxn f[maxN][maxC], n;
maxr res = 0;


void Prepare() {
    std::cin >> a;
    n = a.size();
}


maxc classi(char c) {
    if (c < 'A') return so;
    if (c < 'a') return hoa;
    return thg;
}


bool check(maxn i, maxn j) {
    return (j - i + 1 >= minL) && (f[j][so] - f[i][so] > 0) && (f[j][hoa] - f[i][hoa] > 0) && (f[j][thg] - f[i][thg] > 0);
}


void Process() {
    f[0][classi(a[0])] = 0;
    maxn i = 0, j = 1;

    while (j < n) {
        maxc x = classi(a[j]);

        f[j][so] = f[j - 1][so];
        f[j][thg] = f[j - 1][thg];
        f[j][hoa] = f[j - 1][hoa];

        f[j][x]++;
        f[j][classi(a[j - 1])]++;


        while (check(i, j)) {
            res += n - j;
            i++;
        }

        f[j][x]--;
        j++;
    }
}


int main() {
    //std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    freopen("matkhau.inp","r",stdin);
    //freopen("matkhau.out","w",stdout);

    Prepare();
    Process();
    std::cout << res;
}
