#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>

#define num 0
#define op 1
#define obr 2
#define cbr 3
#define alp 4
#define maxV 3

typedef long maxn;
typedef double maxa;
typedef std::string str;

std::vector <char> stack_con;
std::vector <maxa> stack_cal;
maxa var[maxV];


// ********** CONVERT *******************************
int prior_con(char c) {
	if (c == '+' || c == '-') return 0;
	if (c == '*' || c == '/') return 1;
	return -1;
}


int classi_con(char c) {
	if (prior_con(c) != -1) return op;
	if (c == '(') return obr;
	if (c == ')') return cbr;
	return num;
}


void PopBr(str &bt) {
	while (!stack_con.empty() && classi_con(stack_con.back()) != obr) {
		bt += stack_con.back();
		stack_con.pop_back();
	}
	stack_con.pop_back();
}


void PushOp(char c, str &bt) {
	while (!stack_con.empty() && prior_con(c) <= prior_con(stack_con.back())) {
		bt += stack_con.back();
		stack_con.pop_back();
	}
	stack_con.push_back(c);
}


str Convert(str &s) {
	str bt = "";
	stack_con.clear();

	for (maxn i = 0; i < s.size(); i++) {
		int x = classi_con(s[i]);

		if (x == num) bt += s[i];
		if (x == op) PushOp(s[i], bt);
		if (x == obr) stack_con.push_back(s[i]);
		if (x == cbr) PopBr(bt);
	}

	while (!stack_con.empty()) {
		bt += stack_con.back();
		stack_con.pop_back();
	}

	return bt;
}

// ********** CONVERT_END ***************************


// ********** CALCULATE *****************************


double str2num(str &s) {
	double re = 0;
	for (maxn i = 0; i < s.size(); i++) re = re * 10 + (s[i] - '0');
	return re;
}


int classi_cal(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return op;
	if (c >= '0' && c <= '9') return num;
	return alp;
}
 

void Operate(char c) {
	maxn len = stack_cal.size();

	if (c == '+') stack_cal[len - 2] += stack_cal[len - 1];
	if (c == '-') stack_cal[len - 2] -= stack_cal[len - 1];
	if (c == '*') stack_cal[len - 2] *= stack_cal[len - 1];
	if (c == '/') stack_cal[len - 2] /= stack_cal[len - 1];

	stack_cal.pop_back();
}


maxa Calculate(str &bt) {

	stack_cal.clear();
	str number = "";

	for (maxn i = 0; i < bt.size(); i++) {
		int x = classi_cal(bt[i]);

		if (x == num) number += bt[i];
		else if (number != "") {
			stack_cal.push_back(str2num(number));
			number = "";
		}

		if (x == alp) stack_cal.push_back(var[bt[i] - 'a']);
		if (x == op) Operate(bt[i]);
	}

	return stack_cal.back();
}

// ********** CALCULATE_END *************************


int main() {
	str s, bt;
	std::cin >> s;
	bt = Convert(s);

	std::cout << bt << '\n';
	std::cout << std::fixed << std::setprecision(4);

	while (std::cin >> var[0] >> var[1] >> var[2])
		std::cout << Calculate(bt) << '\n';
}