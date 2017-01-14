#include <iostream>
using namespace std;

struct vertex {
	int num;
	vertex* next;
};

bool flag;
bool isVisit[100001];
vertex* point[100001];

void dfs(vertex* v, int target) {
	if (flag) {
		return;
	}
	if (v == NULL) {
		return;
	}
	vertex* temp = v;
	while (temp != NULL) {
		if (flag) {
			break;
		}
		if (temp->num == target) {
			flag = 1;
			break;
		}
		else if (isVisit[temp->num] == 0) {
			isVisit[temp->num] = 1;
			dfs(point[temp->num], target);
		}
		temp = temp->next;
	}
}

int main() {
	for (int i = 0; i < 100001; i++) {
		point[i] = NULL;
	}

	int i, j;
	while (cin >> i >> j) {
		flag = 0;
		for (int k = 0; k < 100001; k++) {
			isVisit[k] = 0;
		}
		isVisit[i] = 1;
		dfs(point[i], j);
		if (flag) {
			continue;
		}
		cout << i << " " << j << endl;
		vertex* tmp1 = point[i];
		vertex* tmp2 = point[j];
		if (tmp1 == NULL) {
			point[i] = new vertex;
			point[i]->num = j;
			point[i]->next = NULL;
		}
		else {
			while (tmp1->next != NULL) {
				tmp1 = tmp1->next;
			}
			tmp1->next = new vertex;
			(tmp1->next)->num = j;
			(tmp1->next)->next = NULL;
		}

		if (tmp2 == NULL) {
			point[j] = new vertex;
			point[j]->num = i;
			point[j]->next = NULL;
		}
		else {
			while (tmp2->next != NULL) {
				tmp2 = tmp2->next;
			}
			tmp2->next = new vertex;
			(tmp2->next)->num = i;
			(tmp2->next)->next = NULL;
		}
	}

	for (int i = 0; i < 100001; i++) {
		vertex* temp = point[i];
		while (temp != NULL) {
			vertex* a = temp;
			temp = temp->next;
			delete a;
		}
	}
	return 0;
}