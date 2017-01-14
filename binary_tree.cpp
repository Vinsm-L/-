#include <iostream>
#include <string>
using namespace std;

struct tree {
	string letter;
	int left;
	int right;
};

tree* ptr[2000];
int parent[2000];

int find_root(int num) {
	if (parent[num] == 0) {
		return num;
	}
	return find_root(parent[num]);
}

void print(int num) {
	cout << ptr[num] -> letter;
	if (ptr[num] -> left != 0) {
		print(ptr[num] -> left);
	}
	if (ptr[num] -> right != 0) {
		print(ptr[num] -> right);
	}
}

int main() {
	int num, left_num, right_num, node_num;
	string lt;
	while (cin >> node_num) {
		for (int i = 1; i < 2000; i++) {
			parent[i] = 0;
			ptr[i] = NULL;
		}
		if (node_num == 1) {
			cin >> num;
			cin >> lt;
			cin >> left_num;
			cin >> right_num;
			cout << lt << endl;
			continue;
		}
		for (int i = 0; i < node_num; i++) {
			cin >> num;
			cin >> lt;
			cin >> left_num;
			cin >> right_num;
			parent[left_num] = num;
			parent[right_num] = num;
			ptr[num] = new tree;
			ptr[num] -> letter = lt;
			ptr[num] -> left = left_num;
			ptr[num] -> right = right_num;
		}
		int root;
		for (int i = 1; i < 2000; i++) {
			if (parent[i] != 0) {
				root = parent[i];
				break;
			}
		}
		root = find_root(root);
		print(root);
		cout << endl;
		for (int i = 1; i < 2000; i++) {
			if (ptr[i] != NULL) {
				delete ptr[i];
			}
		}
	}
	return 0;
}