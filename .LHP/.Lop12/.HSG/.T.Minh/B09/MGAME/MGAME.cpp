#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define maxN 12
#define N 10
#define sub 0
#define srt 1
#define fi first
#define se second

typedef long long maxa;
typedef int maxn;
typedef std::vector <int> num_t;
typedef std::pair <bool, maxa> p_t;

maxa A, res, f[maxN], res_cnt;
num_t num;
std::vector <p_t> resv;


void Prepare() {
    std::cin >> A;
    f[0] = 0, f[1] = 9;
    for(maxn len = 2; len <= N; len++) f[len] = f[len - 1] + 19 + 1 + (len - 2) * (10 + 1);
}


void Output(num_t &num) {
    for(maxn i = 0; i < num.size(); i++) std::cout << num[i];
    std::cout << '\n';
}


void Num2Vec(maxa x, num_t &num) {
    num.clear();
    for(; x != 0; x /= 10) num.push_back(x % 10);
    std::reverse(num.begin(), num.end());
}


maxa Vec2Num(num_t &num) {
    maxa nx = 0;
    for(maxn i = 0; i < num.size(); i++) nx = nx * 10 + num[i];
    return nx;
}


maxa Sort(num_t &num) {
    maxn idx = -1;
    for(maxn i = 0; i < num.size(); i++)
        if (num[i] != 0 && (idx == -1 || num[i] < num[idx])) idx = i;
    maxa x = num[0]; num[0] = num[idx], num[idx] = x;
    std::sort(num.begin() + 1, num.begin() + num.size());
    return 1;
}


maxa Sub(num_t &num, const maxa x) {
    maxa nx = Vec2Num(num);
    nx -= x;
    Num2Vec(nx, num);
    return x + 1;
}


void analyze(num_t &num, bool &isSorted, maxn &cnt0, maxn &cnt1) {
    isSorted = (num[0] == 1), cnt0 = 0, cnt1 = 0;
    for(maxn i = 0; i < num.size(); i++)
        cnt0 += (num[i] == 0), cnt1 += (num[i] == 1), isSorted &= i < 2? 1 : (num[i] >= num[i - 1]);
}


maxa Trans(num_t &num) {
    bool isSorted = (num[0] == 1); maxn cnt0 = 0, cnt1 = 0;
    analyze(num, isSorted, cnt0, cnt1);
    //Output(num); std::cout << has1 << ' ' << isSorted << ' ' << cnt0 << '\n';

    if (cnt1 == 1 && cnt0 == num.size() - 1) return 0;

    maxn re = 0;

    if (cnt0 == num.size() - 1) {
        resv.push_back(p_t(sub, 1));
        re += Sub(num, 1);
        return re + Trans(num);
    }
    if (num.back() == 0 || (num.back() == 1 && cnt1 == 1)) {
        resv.push_back(p_t(srt, 0));
        re += Sort(num);
        return re + Trans(num);
    }
    if (!cnt1) {
        resv.push_back(p_t(sub, num.back() - 1));
        re += Sub(num, num.back() - 1);
        return re + Trans(num);
    }
    resv.push_back(p_t(sub, num.back()));
    re += Sub(num, num.back()); return re + Trans(num);
}


maxa Process() {
    if (A <= 10) return 1000 - A;
    Num2Vec(A, num);
    res = Trans(num);

    std::reverse(resv.begin(), resv.end());
    res -= (resv[0].fi == sub);
    for(maxn i = 1; i < resv.size(); i++) res -= (resv[i].fi == sub && resv[i].se == sub);

    res = 1000 - (res + f[num.size() - 1] + 1);

    if (res < 1) return 1;
    return res;
}


int main() {
    freopen("mgame.inp", "r", stdin);
    freopen("mgame.out", "w", stdout);

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    Prepare();
    std::cout << Process();
}
