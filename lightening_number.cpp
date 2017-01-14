#include <iostream>
using namespace std;

int exp(int i) {
	int rs = 10;
	while (--i) {
		rs = rs * 10;
	}
	return rs;
}

int main() {
	int n = 9;
	int part1, part2, sq;
	while (n < 10000) {
		sq = n*n;
		for (int i = 1; sq / exp(i) != 0; i++) {
			part1 = sq / exp(i);
			part2 = sq % exp(i);
			if (part1 + part2 == n) {
				cout << n << " " << sq << " " << part1 << " " << part2 << endl;
			}
		}
		n++;
	}
	return 0;
}

