#include <iostream>
#include <cstdio>
#include <vector>

#define maxN 10
#define maxR 123456789
#define operators 3
#define blank 0
#define plus 1
#define minus 2

typedef int maxn, op_t;
typedef long long maxr;

maxn n = 1;
std::vector <maxr> term;
std::vector <op_t> op;


void Prepare() {
    std::cin >> n;
}


std::string op_num2char(op_t op) {
    return op == plus ? "+" : "-";
}


void Output() {
    for(maxn i = 0; i < term.size() - 1; i++)
        std::cout << term[i] << op_num2char(op[i]);

    std::cout << term[term.size() - 1] << "=0\n";
}


maxr cal(maxn x, maxn y, op_t op) {
    return op == plus ? x + y : x - y;
}


bool Check() {
    maxr re = term[0];
    for(maxn i = 1; i < term.size(); i++)
        re = cal(re, term[i], op[i - 1]);

    return re == 0;
}


void Try(maxn x) {
    if (x == n + 1) {
        if (Check()) Output();
        return;
    }

    term[term.size() - 1] = term[term.size() - 1] * 10 + x;
    Try(x + 1);
    term[term.size() - 1] /= 10;


    term.push_back(x);

    op.push_back(plus);
    Try(x + 1);

    op[op.size() - 1] = minus;
    Try(x + 1);

    term.pop_back();
    op.pop_back();
}


int main() {
    //freopen("zero.inp","r",stdin);
    //freopen("zero.out","w",stdout);

    Prepare();
    term.push_back(1);
    Try(2);
}
