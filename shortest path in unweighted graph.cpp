#include <iostream>
#include <queue>
using namespace std;

int main() {
	bool vertex_visit[1005] = {0};
	bool edge[1005][1005];
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edge[i][j] = 0;
		}
	}
	int v, y;
	while (m--) {
		cin >> v >> y;
		edge[v][y] = 1;
		edge[y][v] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		int distance = 0;
		bool flag = 0;
		queue<int> que;
		que.push(1);
		while (!que.empty()) {
			queue<int> temp;
			while (!que.empty()) {
				int num = que.front();
				if (num == i) {
					flag = 1;
					cout << distance << " ";
					break;
				}
				que.pop();
				vertex_visit[num] = 1;
				for (int j = 1; j <= n; j++) {
					if (edge[num][j] == 1 && vertex_visit[j] == 0) {
						temp.push(j);
					}
				}
			}
			if (flag) {
				break;
			}
			que = temp;
			distance++;
		}
		
		if (flag == 0) {
			cout << "-1 ";
		}
		for (int k = 1; k <= n; k++) {
			vertex_visit[k] = 0;
		}
	}
	cout << endl;
	return 0;
}