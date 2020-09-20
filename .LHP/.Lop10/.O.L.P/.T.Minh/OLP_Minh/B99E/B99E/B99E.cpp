#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>

#define maxL 50
#define maxLs 48
#define Div 89

typedef std::string str;
typedef int overa, maxl;

overa b, e;
str s, N;


bool isDivisor(str s) {
	overa left = b;
	maxl begin = 0;
	N = "";


	while (begin < s.size() && left < Div) {
		left = left * 10 + (s[begin] - '0');
		begin++;
	}
	N += (char)(left / Div + '0');
	left = left % Div;


	while (begin < s.size()) {
		left = left * 10 + (s[begin] - '0');
		begin++;

		N += (char)(left / Div + '0');
		left = left % Div;
	}


	return left == 0;
}



void Process() {
	s = "";
	N = "";

	maxl i;
	for (i = 1; i <= maxLs; i++) {
		s += "0";
		if (isDivisor(s + (char)(e + '0'))) break;
	}

	if (i <= maxLs) std::cout << N << '\n';
	else std::cout << "0\n";
}


int main() {
	while (std::cin >> b >> e) Process();
	//b = 8; e = 5;
	//Process();
}