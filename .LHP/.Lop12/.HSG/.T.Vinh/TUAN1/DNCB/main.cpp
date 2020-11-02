#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

#define maxN 200001

typedef long maxn;

maxn n, N, L[maxN], res[maxN];
std::string s;
char a[maxN];
std::vector <maxn> st;


void Prepare() {
    std::cin >> s;
    n = s.size();

    std::fill(L, L + maxN, -1);
    std::fill(res, res + maxN, -1);
}


void Process() {
    maxn l;
    for(l = 0; l < n && s[l] != '('; l++);
    for(maxn i = 0; i < n; i++) {
        if (s[i] == '-') {
            --N;
            if (a[N] == ')' && L[N] != -1) st.push_back((L[N]));
            if (a[N] == '(') st.pop_back();
        }
        else {
            a[N] = s[i];
            res[N] = !N? 0 : res[N - 1];

            if (s[i] == '(') st.push_back(N);
            if (s[i] == ')' && !st.empty()) {
                ++res[N];
                maxn idx = st.back(); st.pop_back();
                L[N] = idx;
                if ((st.empty() && idx != l) || (!st.empty() && st.back() != idx - 1))
                    ++res[N];
            }
            ++N;
        }
        std::cout << res[N - 1] << '\n';
    }
}


int main() {
    freopen("dncb.inp", "r", stdin);
    freopen("dncb.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}
