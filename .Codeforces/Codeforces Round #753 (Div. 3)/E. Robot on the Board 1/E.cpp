// AC

#include <iostream>
#include <algorithm>
#include <string>

#define maxN 1000001
#define abs(x) ((x) < 0 ? -(x) : (x))

typedef long maxn;
typedef std::string str;

maxn row, col;
str cmd;


void Prepare() {
    std::cin >> row >> col >> cmd;
}


void Process() {
    maxn minH = 0, maxH = 0, minW = 0, maxW = 0;

    for(maxn i = 0, h = 0, w = 0; i < cmd.size(); i++) {
        if (cmd[i] == 'L') --w;
        if (cmd[i] == 'R') ++w;
        if (cmd[i] == 'U') --h;
        if (cmd[i] == 'D') ++h;

        if (abs(minH - h) + 1 > row || abs(maxH - h) + 1 > row || abs(minW - w) + 1 > col || abs(maxW - w) + 1 > col)
            break;

        minH = std::min(minH, h);
        maxH = std::max(maxH, h);
        minW = std::min(minW, w);
        maxW = std::max(maxW, w);
    }

    std::cout << abs(minH) + 1 << ' ' << abs(minW) + 1 << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t; std::cin >> t;
    while (t--) {
        Prepare();
        Process();
    }
}