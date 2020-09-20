#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstring>

#define DEBUG 1
#define fi first
#define se second
#define pb push_back
#define INF 1000000000
#define MAX 100

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long LL;

int n, s;
string f[2][MAX * (MAX+1) / 4 - MAX + 1];

string add(string s1, string s2) {
    int len = max(s1.size(), s2.size()) + 1;
    int sum, carry = 0;
    while (s1.size()<len) s1 = '0' + s1;
    while (s2.size()<len) s2 = '0' + s2;
    string kq = "";
    for (int i = len-1; i>=0; --i) {
        sum = s1[i] + s2[i] - 48*2 + carry;
        carry = sum / 10;
        kq = static_cast<char>(sum % 10 + 48) + kq;
    }
    while (kq[0] == '0') kq.erase(0,1);
    return kq;
}

void solve(int n) {
    s = (n * (n+1)) / 2;
    if (s & 1) cout << "0\n";
    else {
        s = s / 2 - n;
        int t = 0;
        f[0][0] = "1";
        for (int i = 0; i <= n-1; ++i) {
            for (int j = 0; j<=s; ++j) {
                if (j == 0) f[t][j] = "1";
                else if (i <= j) f[t][j] = add(f[1 - t][j - i], f[1 - t][j]);
                else f[t][j] = f[1 - t][j];
            }
            t = 1 - t;
        }
        cout << f[1 - t][s] << "\n";
    }
}

int main() {
    if (DEBUG) {
        freopen("ess.inp", "r", stdin);
        freopen("ess.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin >> n;
    solve(n);
    return 0;
}
