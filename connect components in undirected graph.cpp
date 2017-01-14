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
	int component = 0;
	for (int i = 1; i <= n; i++) {
		if (vertex_visit[i] == 1) {
			continue;
		}
		queue<int> que;
		que.push(i);
		while (!que.empty()) {
			int num = que.front();
			que.pop();
			vertex_visit[num] = 1;
			for (int j = 1; j <= n; j++) {
				if (edge[num][j] == 1 && vertex_visit[j] == 0) {
					que.push(j);
				}
			}
		}
		component++;
	}
	cout << component << endl;
	return 0;
}