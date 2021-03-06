// full test

#include "pch.h"
#include <iostream>
#include <string>

std::string s;
char a[256];
int  top,  n;

bool check(std::string s) {
	top = -1;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) a[++top] = s[i];
		else {
			switch (s[i]) {
			case ')':
				if (a[top] != '(') return false;
				break;
			case ']':
				if (a[top] != '[') return false;
				break;
			case '}':
				if (a[top] != '{') return false;
				break;
			default:
				return false;
			}
			top--;
		}
	}
	return true;
}


int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		if ((check(s)) && (top == -1)) std::cout << "TRUE\n";
		else std::cout << "FALSE\n";
	}
}