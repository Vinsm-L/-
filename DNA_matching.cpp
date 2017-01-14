#include <iostream>
#include <string>
using namespace std;

int main() {
	int text_case;
	cin >> text_case;
	string strand[100];
	while (text_case--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> strand[i];
		}
		int pair = 0;
		for (int i = 0; i < n; i++) {
			if (strand[i] == "NULL")
				continue;
			int len = strand[i].length();
			for (int j = i + 1; j < n; j++) {
				if (strand[j] == "NULL") {
					continue;
				}
				if (len != strand[j].length()) {
					continue;
				}
				bool flag = 1;
				for (int k = 0; k < len; k++) {
					if (strand[i][k] == 'A' && strand[j][k] != 'T') {
						flag = 0;
						break;
					}
					if (strand[i][k] == 'T' && strand[j][k] != 'A') {
						flag = 0;
						break;
					}
					if (strand[i][k] == 'G' && strand[j][k] != 'C') {
						flag = 0;
						break;
					}
					if (strand[i][k] == 'C' && strand[j][k] != 'G') {
						flag = 0;
						break;
					}
				}
				if (flag) {
					pair++;
					strand[j] = "NULL";
					break;
				}
			}
		}
		cout << pair << endl;
	}
	return 0;
}