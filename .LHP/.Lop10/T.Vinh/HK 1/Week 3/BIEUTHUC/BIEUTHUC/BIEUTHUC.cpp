#include <iostream>
#include <string>

std::string a[20], s, re;
int n = 0;


int main() {

	getline(std::cin, s);

	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a') && (s[i] <= 'z')) a[n] += s[i];

		else if (s[i] == ',') {
			if ((s[i + 1] == 'a') || (s[i + 1] == 'm')) n++;
		}

		else if (s[i] == '(') {
			if ((s[i + 1] == 'a') || (s[i + 1] == 'm')) n++;
		}

		else if (s[i] == ')') {
		        std::cout << a[n];
			if (n > 0) std::cout << " ";
			a[n--] = "";
		}

		else {
			std::cout << s[i];
			if ((s[i + 1] == ')') || (s[i + 1] == ',')) std::cout << " ";
		}
	}
}
