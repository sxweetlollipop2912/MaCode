// didnt check
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define maxN 100002

typedef long maxn, maxa;

const maxa INF = 1e9 + 1;

maxn n, cnt[maxN], sum[maxN];
maxa a[maxN], b[maxN];
std::vector <maxn> st;


maxa str2num(const std::string& s) {
    maxa re = 0;
    for(maxn i = (maxn)s.size() - 1; i >= 0; i--) {
        re = re * 10 + (s[i] - '0');
    }
    return re;
}


void Prepare() {
    std::cin >> n;
    
    for(maxn i = 1; i <= n; i++) {
        std::string s; std::cin >> s;

        if (s == "?") b[i] = -1;
        else b[i] = str2num(s);
    }
}


void Update(maxa bit[], const maxn idx, const maxa val) {
    for(maxn i = idx; i <= n; i += (i & (-i))) {
        bit[i] += val;
    }
}


maxa Sum(maxa bit[], const maxn idx) {
    maxn re = 0;
    for(maxn i = idx; i > 0; i -= (i & (-i))) {
        re += bit[i];
    }
    return re;
}


void Process() {
    std::fill(a, a + n + 1, -INF);

    for(maxn x = 1; x <= n; x++) {
        if (b[x] == -1) {
            st.push_back(x);
            continue;
        }

        maxn len = x & (-x);

        bool flag = 0;
        maxa s = 0;
        for(maxn i = len - 1; i > 0; i -= (i & (-i))) {
            maxn j = x - (len - i);
            //std::cout << "ss " << x << ' ' << len << ' ' << i << ' ' << j << ' ' << b[j] << ' ' << s << '\n';
            if (b[j] == -1) {
                flag = 1;
                break;
            }
            s += b[j];
            //std::cout << "s " << x << ' ' << i << ' ' << j << ' ' << b[j] << ' ' << s << '\n';
        }

        if (flag == 1) {
            st.push_back(x);
            continue;
        }

        a[x] = b[x] - s;
        //std::cout << "a " << x << ' ' << a[x] << '\n';
        Update(cnt, x, 1);
        Update(sum, x, a[x]);

        if (len == 1 || Sum(cnt, x) - Sum(cnt, x - len) != (maxa)len - 1) continue;
        maxn idx = st.back();
        st.pop_back();

        a[idx] = b[x] - (Sum(sum, x) - Sum(sum, x - len));
        Update(cnt, x, 1);
        Update(sum, x, a[x]);
    }

    for(maxn i = 1; i <= n; i++) {
        if (a[i] == -INF) std::cout << "? ";
        else std::cout << a[i] << ' ';
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}