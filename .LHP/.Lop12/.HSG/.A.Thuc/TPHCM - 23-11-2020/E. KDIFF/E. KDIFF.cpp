// AC
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <deque>
 
#define maxN 300001
 
typedef long maxn;
typedef long maxa;
 
maxn n, f[maxN], res;
maxa a[maxN], K;
std::deque <maxn> mn, mx;
 
 
void Prepare() {
    std::cin >> n >> K;
    for(maxn i = 0; i < n; i++) std::cin >> a[i];
}
 
 
void Process() {
    for(maxn i = 0, l = 0; i < n; i++) {
        while (!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
        mn.push_back(i);
        while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
        mx.push_back(i);
 
        while (a[mx.front()] - a[mn.front()] > K) {
            ++l;
            while (mn.front() < l) mn.pop_front();
            while (mx.front() < l) mx.pop_front();
        }
 
        f[i] = i == 0? i - l + 1 : std::max(f[i - 1], i - l + 1);
        res = l == 0? f[i] : std::max(res, f[l - 1] + i - l + 1);
    }
 
    std::cout << res;
}
 
 
int main() {
    //freopen("E.inp", "r", stdin);
 
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
 
    Prepare();
    Process();
}