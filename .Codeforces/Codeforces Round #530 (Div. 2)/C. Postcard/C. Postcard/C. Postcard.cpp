#include "pch.h"
#include <iostream>
#include <string>

#define maxK 201
typedef int maxk;

std::string s;
maxk k, cnt[maxK];


void Prepare() {
	std::cin >> s >> k;
}


bool isAlpha(char c) {
	return c >= 'a' && c <= 'z';
}


bool Process() {

	maxk len = s.size();

	for (maxk i = 0; i < s.size(); i++) {
		if (isAlpha(s[i])) continue;
		cnt[i] = -1;
		len--;
	}

	for (maxk i = s.size() - 1; i > 0 && len != k; i--) {
		if (isAlpha(s[i])) continue;

		if (len < k) {
			if (s[i] != '*') continue;

			cnt[i - 1] += k - len;
			len = k;
			break;
		}

		cnt[i - 1]--;
		len--;
	}

	return len == k;
}


int main() {
	Prepare();
	if (!Process()) {
		std::cout << "Impossible";
		return 0;
	}

	for (maxk i = 0; i < s.size(); i++)
		for (maxk j = 0; j <= cnt[i]; j++) std::cout << s[i];
}