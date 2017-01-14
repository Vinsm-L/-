#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		set<int> sticks;
		int len;
		while (n--) {
			cin >> len;
			if (sticks.find(len) == sticks.end()) {
				sticks.insert(len);
			} else {
				sticks.erase(len);
			}
		}
		for (set<int>::iterator it = sticks.begin(); it != sticks.end(); it++) {
			cout << *it << endl;
		}
	}
	return 0;
}