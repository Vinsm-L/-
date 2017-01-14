#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string isbn;
	while (cin >> isbn) {
		int sum = 0;
		int k = 0;
		for (int i = 0; i < 11; i++) {
			if (isbn[i] == '-') {
				continue;
			}
			sum += (isbn[i] - '0') * (10 - k);
			k++;
		}
		int hyphen = 0;
		while ((sum + hyphen) % 11 != 0) {
			hyphen++;
		}
		if (hyphen == 10) {
			isbn += "-X";
		} else {
			stringstream ss;
			string str;
			ss << hyphen;
			ss >> str;
			isbn += "-" + str;
		}
		cout << isbn << endl;
	}
	return 0;
}
