#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		int edge[501][501];
		int row_min_vertex[501];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> edge[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			int min = 70000;
			for (int j = 1; j <= n; j++) {
				if (edge[i][j] < min && edge[i][j] > 0) {
					row_min_vertex[i] = j;
					min = edge[i][j];
				}
			}
		}

		bool vertex_visit[501] = {0};
		int edge_num = 0;
		int max_edge = 0;
		vertex_visit[1] = 1;
		for (int i = 1; i <= n; i++) {
			if (row_min_vertex[i] == 1) {
				int min = 70000;
				for (int j = 1; j <= n; j++) {
					if (edge[i][j] < min && edge[i][j] > 0 && vertex_visit[j] == 0) {
						row_min_vertex[i] = j;
						min = edge[i][j];
					}
				}
			}
		}

		while (edge_num != n-1) {
			int least_edge = 70000;
			int target;
			for (int i = 1; i <= n; i++) {
				if (vertex_visit[i] == 1 && edge[i][row_min_vertex[i]] < least_edge) {
					least_edge = edge[i][row_min_vertex[i]];
					target = row_min_vertex[i];
				}
			}
			vertex_visit[target] = 1;
			edge_num++;
			if (least_edge > max_edge) {
				max_edge = least_edge;
			}

			for (int i = 1; i <= n; i++) {
				if (row_min_vertex[i] == target) {
					int min = 70000;
					for (int j = 1; j <= n; j++) {
						if (edge[i][j] < min && edge[i][j] > 0 && vertex_visit[j] == 0) {
							row_min_vertex[i] = j;
							min = edge[i][j];
						}
					}
				}
			}
		}
		cout << max_edge << endl;
		if (t != 0) {
			cout << endl;
		}
	}
	return 0;
}