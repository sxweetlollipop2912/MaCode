#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define DEBUG 1

using namespace std;

int n, d;
string s;

bool next() {
    bool p;
    int i;
    cout << s << '\n';
    p = 1;
    i = 2*n-1;
    while (s[i] == 40+p) {
        --i;
        p = !p;
    }
    if (i>=0) {
        for (i; i>0; --i)
            if (s[i] == 41 && s[i-1] == 40) break;
        swap(s[i], s[i-1]);
        sort(s.begin()+i+1,s.end());
        return 1;
    } else return 0;
}
int main() {
    if (DEBUG) {
        freopen("genbr.inp", "r", stdin);
        freopen("genbr.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i<n; ++i) s += '(';
    for (int i = 0; i<n; ++i) s += ')';
    while (next() && ++d<30000);
    return 0;
}
