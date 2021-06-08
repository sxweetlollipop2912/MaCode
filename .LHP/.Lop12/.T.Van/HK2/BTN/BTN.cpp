#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

#define maxN 2001

typedef int maxn;
typedef std::string str;

maxn n;
str a;


void Prepare() {
    std::cin >> a;
    n = a.size();
}


bool Process() {
    maxn open = n, close = n;
    maxn need_open = 0, need_close = 0, x = 0;

    for(maxn i = 0; i < n; i++) {
        if (a[i] == '(') x += 1;
        if (a[i] == ')') x -= 1;
        if (a[i] == '[' && open == n) open = i;
        
        if (x < 0) {
            if (open == n) return 0;
            need_open += 1, x = 0;
        }
    }

    x = 0;
    for(maxn i = n - 1; i >= 0; i--) {
        if (a[i] == '(') x -= 1;
        if (a[i] == ')') x += 1;
        if (a[i] == ']' && close == n) close = i;
        
        if (x < 0) {
            if (close == n) return 0;
            need_close += 1, x = 0;
        }
    }

    for(maxn i = 0; i < open; i++) 
        std::cout << a[i];
    for(maxn i = 0; i < need_open; i++) 
        std::cout << '(';
    for(maxn i = open + 1; i < close; i++) 
        if (a[i] != ']' && a[i] != '[') 
        std::cout << a[i];
    for(maxn i = 0; i < need_close; i++) 
        std::cout << ')';
    for(maxn i = close + 1; i < n; i++) 
        std::cout << a[i];

    return 1;
}


int main() {
    freopen("btn.inp", "r", stdin);
    freopen("btn.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    
    Prepare();
    if (!Process()) std::cout << "NO";
}