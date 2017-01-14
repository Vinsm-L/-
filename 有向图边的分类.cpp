#include <iostream>
#include <string>
using namespace std;

int n;
bool edge[105][105];
bool found;

bool offspring_visited(int vertex, bool* vertex_visit) {
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		if (edge[vertex][i] == 1 && vertex_visit[i] == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

void dfs(int vertex, bool* vertex_visit, int start, int end) {
	if (found) {
		return;
	}

	vertex_visit[vertex] = 1;
	for (int i = 1; i <= n; i++) {
		if (found) {
			return;
		}

		if (edge[vertex][i] == 1) {
			if (vertex_visit[i] == 0) {
				if (vertex == start && i == end) {
					cout << "edge (" << vertex << "," << i << ") is Tree Edge" << endl;
					found = 1;
					return;
				} else {
					dfs(i, vertex_visit, start, end);
				}
			} else {
				if (vertex != start || i != end) {
					continue;
				} else {
					if (!offspring_visited(i, vertex_visit)) {
						cout << "edge (" << vertex << "," << i << ") is Back Edge" << endl;
						found = 1;
						return;
					} else {
						if (vertex == 1) {
							cout << "edge (" << vertex << "," << i << ") is Down Edge" << endl;
							found = 1;
							return;
						} else {
							cout << "edge (" << vertex << "," << i << ") is Cross Edge" << endl;
							found = 1;
							return;
						}
					}
				}
			}
		}
	}
}

int main() {
	int m, u, v;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edge[i][j] = 0;
		}
	}
	while (m--) {
		cin >> u >> v;
		edge[u][v] = 1;
	}
	int k;
	cin >> k;
	int start;
	int end;
	while (k--) {
		bool vertex_visit[105] = {0};
		found = 0;
		cin >> start >> end;
		dfs(1, vertex_visit, start, end);
	}
	return 0;
}