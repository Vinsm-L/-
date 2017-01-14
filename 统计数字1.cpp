#include <set>
#include <map>
#include <iostream>
using namespace std;

int main() {
	bool flag = 1;
	int n;
	while (cin >> n && n != 0) {
		if (flag) {
			flag = 0;
		} else {
			cout << endl;
		}
		set<int> myset;
		map<int, int> mymap;
		int num;
		while (n--) {
			cin >> num;
			if (myset.find(num) == myset.end()) {
				mymap[num] = 1;
				myset.insert(num);
			} else {
				mymap[num]++;
			}
		}
		for (set<int>::iterator it = myset.begin(); it != myset.end(); it++) {
			cout << *it << " " << mymap[*it] << endl;
		}
	}
	return 0;
}