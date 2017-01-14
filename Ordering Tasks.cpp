#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> vertex[100001];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int inDegree[100001] = {0};
		while (m--) {
			int i, j;
			cin >> i >> j;
			vertex[i].push_back(j);
			inDegree[j]++;
		}

		priority_queue<int, vector<int>, greater<int>> que;  //  range from small to large

		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				que.push(i);
			}
		}

		while (!que.empty()) {     //    topology sort
			int v = que.top();
			que.pop();
			for (int i = 0; i < vertex[v].size(); i++) {
				inDegree[vertex[v][i]]--;
				if (inDegree[vertex[v][i]] == 0) {
					que.push(vertex[v][i]);
				}
			}
			cout << v << " ";
		}
		cout << endl;
		for (int i = 1; i <= n; i++) {
			vertex[i].clear();
		}
	}
	return 0;
}