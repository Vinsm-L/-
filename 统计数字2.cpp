#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main() {
	bool start = true;
	int n;
	while (cin >> n) {
		if (!start) {
			cout << endl;
		}

		int num;
		map<int, int> num2times;
		while (n--) {
			cin >> num;
			if (num2times.find(num) == num2times.end()) {
				num2times[num] = 1;
			} else {
				num2times[num]++;
			}
		}

		for (map<int, int>::iterator it = num2times.begin(); it != num2times.end(); it++) {
			printf("%d %d\n", it -> first, it -> second);
		}
		start = false;
	}
	return 0;
}