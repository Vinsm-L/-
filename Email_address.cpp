#include <iostream>
#include <string>
using namespace std;

bool isValid(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-' || ch == '_' || ch == '.' || ch == '/' || (ch >= '0' && ch <= '9') || ch == '@') {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	string str;
	while (cin >> str) {
		int begin = 0;
		int end = -1;
		for (int i = 0; i < str.length(); i++) {
			if (!isValid(str[i])) {
				begin = i+1;
			} else if (str[i] == '.' && i == 0) {
				begin = i+1;
			} else if (str[i] == '.' && i >= 1 && str[i-1] == '.') {
				begin = i+1;
			} else if (str[i] == '.' && i >= 1 && !isValid(str[i-1])) {
				begin = i+1;
			} else if (str[i] == '@' && i >= 1 && str[i-1] == '.') {
				begin = i+1;
			} else if (str[i] == '@' && i < str.length() -1 && str[i+1] == '.') {
				begin = i+2;
			} else if (str[i] == '@') {
				for (int j = i+1; j < str.length(); j++) {
					if (!isValid(str[j])) {
						break;
					} else if (str[j] == '.' && j == str.length() - 1) {
						break;
					} else if (str[j] == '.' && j < str.length() -1 && str[j+1] == '.') {
						break;
					} else if (str[j] == '.' && j < str.length() -1 && !isValid(str[j+1])) {
						break;
					} else if (str[j] == '@') {
						break;
					} else {
						end = j;
					}
				}
				if (begin == i || end == -1) {
					begin = i+1;
					end = -1;
					continue;
				} else {
					string EA = "";
					for (int k = begin; k <= end; k++) {
						EA += str[k];
					}
					cout << EA << endl;
					begin = i+1;
					end = -1;
				}
			} else {
				continue;
			}
		}
	}
	return 0;
}