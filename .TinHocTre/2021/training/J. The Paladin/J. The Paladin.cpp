// AC
// Dùng Dijkstra.
//
// Giải thích:
// Giả sử kq = s: abcba, K = 5
// Vì là palindrome nên thuật chia đôi s ra và tách thành: ab - bc
// "ab" và "bc" đc xem là 2 đỉnh trong graph, với "ab" nối 1 chiều tới "bc".
//
// Về việc dặt tên đỉnh: vì "ab" có thể xuất hiện nhiều lần, thuật sẽ đặt tên đỉnh là "ab-1", "ab-2",...,
// với các số là vị trí đặt ab trong xâu kq.
//
// Do đã chia đôi s nên thuật phải tính toán lại cost, cụ thể cost("ab") = cost("ab") + cost("ba").
// Lưu ý: cost này là trọng số của đỉnh, k phải của cạnh.
//
// Chạy Dijkstra, với depth = K / 2, sau đó lấy kq (tính toán kq trong trg hợp K chẵn và lẻ có thể khác nhau).
//
// (Số đỉnh tối đa = 676 * (100 / 2) = 33800).

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>

#define maxP 677
#define maxK 101
#define maxN 33801
#define V first
#define C second
#define idx(p, step) (P * (step) + (p))
#define p_idx(idx) ((idx) % P)
#define cal_step(idx) ((idx) / P)

typedef long maxn, maxa;
typedef std::string str;
typedef std::pair <maxn, maxa> pq_t;

const maxa INF = 1e9;

maxn P, K, n;
maxa cost[maxP], mn[maxN], res;
str s[maxP];
std::map <str, maxn> map;
std::vector <maxn> ad[maxN];


str rev(str s) {
    std::swap(s[0], s[1]);
    return s;
}


void Prepare() {
    std::cin >> P >> K;
    n = P * (K / 2);

    for(maxn i = 0; i < P; i++) {
        std::cin >> s[i] >> cost[i];
        map[s[i]] = i;
    }

    for(maxn i = 0; i < P; i++) {
        if (map.find(rev(s[i])) != map.end()) {
            maxn j = map[rev(s[i])];
            maxa sum_cost = cost[i] + cost[j];
            cost[i] = cost[j] = sum_cost;
        }
        else {
            cost[i] = -1;
        }
    }
    for(maxn i = 0; i < P; i++) {
        if (cost[i] != -1 && s[i][0] != s[i][1]) cost[i] /= 2;
    }

    for(maxn i = 0; i < P; i++) for(maxn j = 0; j < P; j++) {
        if (cost[i] == -1 || cost[j] == -1) continue;
        if (s[i][1] != s[j][0]) continue;

        ad[i].push_back(j);
    }
}


class cmp {
public:
    bool operator()(const pq_t p1, const pq_t p2) {
        return p1.C > p2.C;
    }
};
std::priority_queue <pq_t, std::vector <pq_t>, cmp > pq;


void Dijkstra(const maxn len) {
    std::fill(mn, mn + n, INF);

    for(maxn i = 0; i < P; i++) {
        if (cost[i] == -1) continue;

        pq.push(pq_t(idx(i, 0), cost[i]));
        mn[i] = cost[i];
    }

    while (!pq.empty()) {
        pq_t cur = pq.top(); pq.pop();
        maxn step = cal_step(cur.V);
        maxn u = cur.V, p_u = p_idx(u);

        if (step == len - 1) continue;

        for(maxn i = 0; i < ad[p_u].size(); i++) {
            maxn p_v = ad[p_u][i];
            maxn v = idx(p_v, step + 1);

            if (mn[v] <= mn[u] + cost[p_v]) continue;
            mn[v] = mn[u] + cost[p_v];
            pq.push(pq_t(v, mn[v]));
        }

        while (!pq.empty() && mn[pq.top().V] != pq.top().C) pq.pop();
    }
}


void Process() {
    maxn len = K / 2;
    Dijkstra(len);

    res = INF;
    for(maxn i = 0; i < P; i++) {
        if (cost[i] == -1) continue;

        if (K % 2 != 0) {
            res = std::min(res, mn[idx(i, len - 1)]);
        }
        else {
            if (s[i][0] != s[i][1]) continue;
            res = std::min(res, mn[idx(i, len - 1)] - cost[i] / 2);
        }
    }

    if (res == INF) std::cout << "-1";
    else std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}