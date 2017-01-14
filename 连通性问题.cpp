#include <iostream>
using namespace std;

int group[100001];

int findRoot(int p) {
	if (group[p] == p) {
		return p;
	} else {
		group[p] = findRoot(group[p]);
	}
}

int main() {
	int i, j;
	for (int k = 0; k < 100001; k++) {
		group[k] = k;
	}
	while (cin >> i >> j) {
		if (findRoot(i) != findRoot(j)) {
			cout << i << " " << j << endl;
			group[group[i]] = group[j];
		}
	}
	return 0;
}