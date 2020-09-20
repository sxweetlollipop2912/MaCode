#include <iostream>
#include <fstream>

int n, a[100001];

void Prepare() {
    freopen("HOANVI.inp","r",stdin);
    freopen("HOANVI.out","w",stdout);
    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> a[i];
}

void swap(int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Prev() {
    int ii;
    for(ii = n - 2; ii >= 0; ii--)
        if (a[ii] > a[ii+1]) break;

    if (ii < 0) {
        std::cout << -1;
        return;
    }

    int jj;
    for(jj = n - 1; jj > ii; jj--)
        if (a[jj] < a[ii]) break;
    swap(ii,jj);

    for(int i = 0; i <= ii; i++) std::cout << a[i] << " ";
    for(int i = n - 1; i > ii; i--) std::cout << a[i] << " ";

    swap(ii,jj);
}


void Next() {
    int ii;
    for(ii = n - 2; ii >= 0; ii--)
        if (a[ii] < a[ii + 1]) break;

    if (ii < 0) {
        std::cout << -1;
        return;
    }

    int jj;
    for(jj = n - 1; jj > ii; jj--)
        if (a[jj] > a[ii]) break;
    swap(ii,jj);

    for(int i = 0; i <= ii; i++) std::cout << a[i] << " ";
    for(int i = n - 1; i > ii; i--) std::cout << a[i] << " ";

    swap(ii,jj);
}

int main() {
    Prepare();
    Prev();
    std::cout << '\n';
    Next();
}
