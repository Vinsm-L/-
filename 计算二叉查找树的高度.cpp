#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int nodeNum, node;
		cin >> nodeNum;
		int root, currentRoot;
		int level = -1;
		bool isSmaller = true;
		vector<int> left, right;

		for (int i = 0; i < nodeNum; i++) {
			cin >> node;
			if (i == 0) {
				root = node;
				level++;
				continue;
			}
			int currentLevel = 1;
			if (node < root) {
				for (int j = 0; j < left.size(); j++) {
					if (j == 0) {
						currentRoot = left[j];
					}

					if (isSmaller && left[j] < currentRoot) {
						currentRoot = left[j];
					} else if (!isSmaller && left[j] < currentRoot) {
						continue;
					} else if (!isSmaller && left[j] > currentRoot) {
						currentRoot = left[j];
					} else if (isSmaller && left[j] > currentRoot) {
						continue;
					}

					if (node < currentRoot) {
						currentLevel++;
						isSmaller = true;
					}
					if (node > currentRoot) {
						currentLevel++;
						isSmaller = false;
					}
				}
				left.push_back(node);
			} else {
				for (int j = 0; j < right.size(); j++) {
					if (j == 0) {
						currentRoot = right[j];
					}

					if (isSmaller && right[j] < currentRoot) {
						currentRoot = right[j];
					} else if (!isSmaller && right[j] < currentRoot) {
						continue;
					} else if (!isSmaller && right[j] > currentRoot) {
						currentRoot = right[j];
					} else if (isSmaller && right[j] > currentRoot) {
						continue;
					}

					if (node < currentRoot) {
						currentLevel++;
						isSmaller = true;
					}
					if (node > currentRoot) {
						currentLevel++;
						isSmaller = false;
					}
				}
				right.push_back(node);
			}
			if (currentLevel > level) {
				level = currentLevel;
			}
		}
		cout << level << endl;
		for (int i = 0; i < nodeNum; i++) {
			cin >> node;
		}
	}
	return 0;
}