#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector<int> hash[13];
		int num;
		while (n--) {
			cin >> num;
			hash[num % 13].push_back(num);
		}
		for (int i = 0; i < 13; i++) {
			if (hash[i].size() == 0) {
				cout << i << "#NULL" << endl;
				continue;
			}
			for (vector<int>::iterator it = hash[i].begin(); it != hash[i].end(); it++) {
				if (it == hash[i].begin()) {
					cout << i << "#" << *it;
				} else {
					cout << " " << *it;
				}
			}
			cout << endl;
		}
	}
	return 0;
}