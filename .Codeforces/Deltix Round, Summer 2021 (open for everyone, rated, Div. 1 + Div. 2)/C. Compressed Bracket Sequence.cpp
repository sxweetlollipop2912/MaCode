// AC
#include <iostream>
#include <algorithm>

#define maxN 1001
#define spare_op first
#define spare_cl second

typedef int maxn;
typedef long long maxa;
typedef std::pair <maxa, maxa> p_t;

maxn n;
maxa a[maxN], res;
p_t f[maxN][maxN];


void Prepare() {
    std::cin >> n;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}


void Process() {
    res = 0;

    for(maxn op = 0; op < n - 1; op += 2) {
        maxn cl = op + 1;
        f[op][cl].spare_op = std::max((maxa)0, a[op] - a[cl]);
        f[op][cl].spare_cl = std::max((maxa)0, a[cl] - a[op]);
        res += std::min(a[op], a[cl]);
    }

    for(maxn len = 4; len <= n; len += 2) {
        for(maxn op = 0; op <= n - len; op += 2) {
            maxn cl = op + len - 1;
            p_t mid = op + 2 < cl - 2? f[op + 2][cl - 2] : p_t(0, 0);
            mid.spare_op += a[cl - 1];
            mid.spare_cl += a[op + 1];

            p_t &cur = f[op][cl];
            cur.spare_op = mid.spare_op - a[cl];
            cur.spare_cl = mid.spare_cl - a[op];

            if (cur.spare_op <= 0 && cur.spare_cl <= 0)
                ++res;

            if (cur.spare_op < 0 && cur.spare_cl < 0) {
                std::swap(cur.spare_op, cur.spare_cl);
                cur.spare_op = -cur.spare_op;
                cur.spare_cl = -cur.spare_cl;

                maxa x = std::min(cur.spare_op, cur.spare_cl);
                res += x;
                cur.spare_op -= x;
                cur.spare_cl -= x;
            }

            else if (cur.spare_op < 0) {
                cur.spare_cl += -cur.spare_op;
                cur.spare_op = 0;
            }
            else if (cur.spare_cl < 0) {
                cur.spare_op += -cur.spare_cl;
                cur.spare_cl = 0;
            }
        }
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}