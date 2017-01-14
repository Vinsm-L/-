#include <iostream>
#include <queue>
using namespace std;

bool isValid;
int deep, n;
bool edge[105][105];

void find_repeatVertex(int vertex, bool* vertex_visit) {
	vertex_visit[vertex] = 1;
	for (int i = 1; i <= n; i++) {
		if (edge[vertex][i] == 1 && vertex_visit[i] == 1) {
			isValid = 0;
			break;
		} else if (edge[vertex][i] == 1) {
			find_repeatVertex(i, vertex_visit);
		}
	}
}

void dfs(int vertex, int level) {
	for (int i = 1; i <= n; i++) {
		if (edge[vertex][i] == 1) {
			dfs(i, level+1);
		}
	}
	if (level > deep) {
		deep = level;
	}
}

int main() {
	while (true) {
		int m;
		bool vertex_visit[105] = {0};
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				edge[i][j] = 0;
			}
		}
		int u, v;
		while (m--) {
			cin >> u >> v;
			edge[u][v] = 1;
		}
		deep = 0;
		isValid = 1;

		for (int i = 1; i <= n; i++) {
			find_repeatVertex(i, vertex_visit);
			for (int j = 1; j <= n; j++) {
				vertex_visit[j] = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			int count = 0;
			for (int j = 1; j <= n; j++) {
				if (edge[j][i] == 1) {
					count++;
				}
			}
			if (count > 1) {
				isValid = 0;
			}
		}
		if (!isValid) {
			cout << "INVALID" << endl;
			continue;
		}

		int root;
		int width[105] = {0};
		for (int i = 1; i <= n; i++) {
			bool flag = 0;
			for (int j = 1; j <= n; j++) {
				if (edge[j][i] == 1) {
					flag = 1;
				}
			}
			if (!flag) {
				root = i;
				dfs(root, 0);
				
				int level = 0;
				queue<int> que;
				que.push(root);
				while (!que.empty()) {
					queue<int> temp;
					int count = que.size();
					width[level] += count;
					level++;

					while (!que.empty()) {
						int num = que.front();
						que.pop();
						for (int i = 1; i <= n; i++) {
							if (edge[num][i] == 1) {
								temp.push(i);
							}
						}
					}

					que = temp;
				}
			}
		}
		int max_width = 0;
		for (int i = 0; i < 101; i++) {
			if (width[i] > max_width) {
				max_width = width[i];
			}
		}

		cout << deep << " " << max_width << endl;
	}
	return 0;
}