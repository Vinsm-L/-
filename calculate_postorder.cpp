#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		string epr;
		stack<double> sta;
		cin >> epr;
		int x = 'a' - 1;
		for (int i = 0; i < epr.length(); i++) {
			if (epr[i] == '+') {
				double part1 = sta.top();
				sta.pop();
				double part2 = sta.top();
				sta.pop();
				sta.push(part1+part2);
			} else if (epr[i] == '-') {
				double part1 = sta.top();
				sta.pop();
				double part2 = sta.top();
				sta.pop();
				sta.push(part2-part1);
			} else if (epr[i] == '*') {
				double part1 = sta.top();
				sta.pop();
				double part2 = sta.top();
				sta.pop();
				sta.push(part1*part2);
			} else if (epr[i] == '/') {
				double part1 = sta.top();
				sta.pop();
				double part2 = sta.top();
				sta.pop();
				sta.push(part2/part1);
			} else {
				double ele = (double)(epr[i] - x);
				sta.push(ele);
			}
		}
		std::cout << std::fixed;
 	    std::cout << std::setprecision(2) << sta.top() << endl;
	}
	return 0;
}