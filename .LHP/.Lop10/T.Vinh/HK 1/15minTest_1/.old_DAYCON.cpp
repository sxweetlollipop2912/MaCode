#include <iostream>
#include <fstream>

long long a[1000000], m, re;
int n, num, top;

void Prepare() {
    std::cin >> n >> m;
}

void Add() {
    for(int i=0;i<top;i++) {
        a[i]+=num;
        if (a[i]==m) re++;
    }
}

int main() {
    freopen("DAYCON.inp","r",stdin);
    freopen("DAYCON.out","w",stdout);
    Prepare();
    for(top=1;top<=n;top++) {
        std::cin >> num;
        Add();
    }
    std::cout << re;
}
