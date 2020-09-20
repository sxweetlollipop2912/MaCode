#include <iostream>
#include <fstream>

int n, d;
bool a[71];

void swap(int i, int j) {
	bool temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


char Ch(bool a) {
	return a == 1 ? ')' : '(';
}


void Prepare() {
	freopen("GENBR.inp", "r", stdin);
	freopen("GENBR.out", "w", stdout);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		std::cout << Ch(a[i]);
	}
    for (int i = 0; i < n; i++) {
		a[i + n] = 1;
		std::cout << Ch(a[i + n]);
    }
    std::cout << '\n';
    n *= 2;
}

bool Next() {
    d++;

	int one = 0, zero = 0;

	int ii;
	for (ii = n - 1; ii > 0; ii--) {
		one += a[ii];
		zero += 1 - a[ii];
		if (!a[ii - 1] && (one - zero >= 2)) break;
	}

	if (ii == 0) return 0;

	swap(ii, ii - 1);
	zero++; one--;

	for (int i = 0; i < ii; i++) std::cout << Ch(a[i]);
	for (int i = 0; i < zero; i++) {
        a[i + ii] = 0;
        std::cout << Ch(a[i + ii]);
	}
	for (int i = 0; i < one; i++) {
        a[i + ii + zero] = 1;
        std::cout << Ch(a[i + ii + zero]);
	}
    return 1;
}


int main() {
	Prepare();
	d = 1;
	while (d < 30000 && Next()) std::cout << '\n';
}
