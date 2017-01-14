#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int n, m;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> m;
		set<string> namelist;
		string name;
		while (n--) {
			cin >> name;
			for (int i = 0; i < name.length(); i++) {
				if (name[i] <= 'z' && name[i] >= 'a') {
					continue;
				} else {
					name[i] = name[i] - ('A' - 'a');
				}
			}
			namelist.insert(name);
		}
		while (m--) {
			cin >> name;
			for (int i = 0; i < name.length(); i++) {
				if (name[i] <= 'z' && name[i] >= 'a') {
					continue;
				} else {
					name[i] = name[i] - ('A' - 'a');
				}
			}
			namelist.erase(name);
		}
		cout << namelist.size() << endl;
	}
	return 0;
}