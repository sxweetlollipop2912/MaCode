//full test

#include "pch.h"
#include <iostream>

unsigned long num[100001], re, top= -1;
char op[100001];

void inp() {
	do {
		std::cin >> op[++top] >> num[top];
	} while (op[top] != '=');
	re = num[top];
}


void operate(unsigned long num, char op) {
	if (op == '+') re -= num;
	if (op == '-') re += num;
	if (op == '*') re /= num;
}


int main() {
	inp();
	for (int i = top - 1; i >= 0; i--) operate(num[i], op[i]);
	std::cout << re;
}

