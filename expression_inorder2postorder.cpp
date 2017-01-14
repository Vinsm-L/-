#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string epr;
	cin >> epr;
	stack<char> sta;
	for (int i = 0; i < epr.length(); i++) {
		if (epr[i] == '(') {
			sta.push(epr[i]);
		} else if (epr[i] == '+'||epr[i] == '-') {
			while (!sta.empty() && sta.top() != '(') {
				cout << sta.top();
				sta.pop();
			}
			sta.push(epr[i]);
		} else if (epr[i] == '*'||epr[i] == '/'||epr[i] == '%') {
			while (!sta.empty() && sta.top() != '(' && sta.top() != '+' && sta.top() != '-') {
				cout << sta.top();
				sta.pop();
			}
			sta.push(epr[i]);
		} else if (epr[i] == ')') {
			while (sta.top() != '(') {
				cout << sta.top();
				sta.pop();
			}
			sta.pop();
		} else {
			cout << epr[i];
		}
	}
	while (!sta.empty()) {
		cout << sta.top();
		sta.pop();
	}
	return 0;
}