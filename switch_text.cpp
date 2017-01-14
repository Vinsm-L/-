#include <iostream>
#include <string>
using namespace std;

bool isPureBlank(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ' ') {
			return 0;
		}
	}
	return 1;
}

int main() {
	string str[2];
	string line;
	int i = 0;
	while (getline(cin, line)) {
		str[i%2] = line;
		if (i%2 == 1) {
			string temp = str[0];
			str[0] = str[1];
			str[1] = temp;
			for (int j = 0; j < 2; j++) {
				if (str[j] == "" || isPureBlank(str[j])) {
					continue;
				}
				int middle;
				if (str[j].length() % 2 == 1) {
					middle = str[j].length() / 2;
				} else {
					middle = str[j].length() / 2 - 1;
				}
				for (int k = middle; k >= 0; k--) {
					cout << str[j][k];
				}
				for (int k = str[j].length() - 1; k > middle; k--) {
					cout << str[j][k];
				}
				cout << endl;
			}
		}
		i++;
	}
	return 0;
}