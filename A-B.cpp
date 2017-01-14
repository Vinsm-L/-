#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		int a, b;
		cin >> n;
		set<int> setA;
		while (n--) {
			cin >> a;
			setA.insert(a);
		}
		cin >> m;
		while (m--) {
			cin >> b;
			setA.erase(b);
		}
		
		for (set<int>::iterator it = setA.begin(); it != setA.end(); it++) {
			if (it == setA.begin()) {
				cout << *it;
			} else {
				cout << " " << *it;
			}
		}
		cout << endl;
	}
	return 0;
}