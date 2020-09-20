// full test
#include <iostream>
#include <fstream>

#define maxn 12

int a[maxn], n, f[maxn + 1][maxn + 1], min, re[maxn];

void Prepare() {
    freopen("TOUR.inp","r",stdin);
    freopen("TOUR.out","w",stdout);
    std::cin >> n;

    for(int i = 0; i < n; i++)
        std::cin >> f[0][i + 1] >> f[i + 1][0];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            std::cin >> f[i + 1][j + 1];

    for(int i = 0; i < n; i++) a[i] = i + 1;
}

void swap(int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Save() {
    for(int i = 0; i < n; i++) re[i] = a[i];
}

bool Next() {
    int ii;
    for(ii = n - 2; ii >= 0; ii--)
        if (a[ii] < a[ii + 1]) break;

    if (ii < 0) return 0;

    int jj;
    for(jj = n - 1; jj > ii; jj--)
        if (a[jj] > a[ii]) break;
    swap(ii,jj);

    int t = f[0][a[0]];

    for(int i = 1; i <= ii; i++)
        t += f[a[i - 1]][a[i]];

    for(int i = ii + 1; i <= (n + ii) / 2; i++)
        swap(i, n - i + ii);

    for(int i = ii + 1; i < n; i++)
        t += f[a[i - 1]][a[i]];

    t += f[a[n - 1]][0];

    if (t < min) {
        min = t;
        Save();
    }
    return 1;
}


int main() {
    Prepare();
    min = 20000;
    while (Next());
    std::cout << min << '\n';
    for(int i = 0; i < n; i++) std::cout << re[i] << ' ';
}
