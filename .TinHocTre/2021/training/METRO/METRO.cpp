// 49/50

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define maxN 100001
#define IDX second
#define VAL first

typedef long maxn;
typedef long long maxa;
typedef std::pair <maxa, maxn> p_t;

maxn n, seat, K;
bool sitting[maxN], onb[maxN];
std::vector <maxn> enter[maxN], ext[maxN];
maxa res, sit[maxN], stand[maxN];
std::priority_queue <p_t, std::vector <p_t>, std::greater<p_t> > on;
std::priority_queue <p_t, std::vector <p_t>> queue;



void Prepare() {
    std::cin >> n >> seat >> K;

    for(maxn i = 0; i < n; i++) {
        maxn st, en;
        std::cin >> sit[i] >> stand[i] >> st >> en;
        --st, --en;

        enter[st].push_back(i);
        ext[en].push_back(i);
    }
}


void Process() {
    res = 0;

    maxa cur = 0; maxn sit_cnt = 0;
    for(maxn k = 0; k < K; k++) {
        for(maxn i = 0; i < ext[k].size(); i++) {
            maxn idx = ext[k][i];
            onb[idx] = 0;

            if (!sitting[idx]) {
                cur -= stand[idx];
            }
            else {
                cur -= sit[idx]; --sit_cnt;
            }
        }
        for(maxn i = 0; i < enter[k].size(); i++) {
            maxn idx = enter[k][i];
            onb[idx] = 1;

            if (stand[idx] >= sit[idx]) {
                cur += stand[idx];
            }
            else {
                on.push(p_t(sit[idx] - stand[idx], idx));
                ++sit_cnt;

                sitting[idx] = 1;
                cur += sit[idx];
            }
        }

        while (!queue.empty() && !onb[queue.top().IDX]) queue.pop();
        while (!on.empty() && !onb[on.top().IDX]) on.pop();

        while (sit_cnt > seat) {
            maxn idx = on.top().IDX;
            on.pop();
            queue.push(p_t(sit[idx] - stand[idx], idx));
            --sit_cnt;

            sitting[idx] = 0;
            cur += stand[idx] - sit[idx];

            while (!on.empty() && !onb[on.top().IDX]) on.pop();
        }

        while (!queue.empty() && sit_cnt < seat) {
            maxn idx = queue.top().IDX;
            queue.pop();
            on.push(p_t(sit[idx] - stand[idx], idx));
            ++sit_cnt;

            sitting[idx] = 1;
            cur += sit[idx] - stand[idx];

            while (!queue.empty() && !onb[queue.top().IDX]) queue.pop();
        }

        //std::cout << k << ' ' << cur << '\n';
        res += cur;
    }

    std::cout << res;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    Process();
}