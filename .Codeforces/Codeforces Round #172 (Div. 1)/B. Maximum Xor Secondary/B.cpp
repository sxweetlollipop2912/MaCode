// AC
#include <iostream>
#include <algorithm>
#include <vector>

#define maxN 100001

typedef long maxn, maxa;

maxn n;
maxa a[maxN], res;
std::vector <maxa> st;


void Prepare() {
    std::cin >> n;

    for(maxn i = 0; i < n; i++) {
        std::cin >> a[i];
    }
}


void Process() {
    res = 0;
    
    for(maxn i = 0; i < n; i++) {
        while (!st.empty() && st.back() < a[i]) {
            res = std::max(res, st.back() ^ a[i]);
            st.pop_back();
        }
        if (!st.empty()) res = std::max(res, st.back() ^ a[i]);
        st.push_back(a[i]);
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}