#include <iostream>
#include <fstream>

int n, k, a[100001];

void Prepare() {
    freopen("TOHOP.inp","r",stdin);
    freopen("TOHOP.out","w",stdout);
    std::cin >> n >> k;
    for(int i = 0; i < k; i++) std::cin >> a[i];
}

int Next() {
    for(int i = k - 1; i >= 0; i--)
        if (a[i] < n - k + i + 1)return i;
    return -1;
}

int main() {
    Prepare();
    int ii = Next();

    if (ii == -1) {
        std::cout << ii;
        return 0;
    }
    for(int i = 0; i < ii; i++) std::cout << a[i] << " ";
    a[ii]++;
    std::cout << a[ii] << " ";
    for(int i = ii + 1; i < k; i++) {
        a[i] = a[i-1] + 1;
        std::cout << a[i] << " ";
    }
}
