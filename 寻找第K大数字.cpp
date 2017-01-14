#include <iostream>
#include <queue>
using namespace std;

bool visited[20000002] = {0};

int main() {
	int n, k;
	cin >> n >> k;
	int num;
	priority_queue<int, vector<int>, greater<int>> que;  // range from small to large
	while (n--) {
		cin >> num;
		if (visited[num + 10000000] == 0) {
			visited[num + 10000000] = 1;
			que.push(num);
			if (que.size() > k) {
				que.pop();
			}
		}
	}
	cout << que.top() << endl;
	return 0;
}