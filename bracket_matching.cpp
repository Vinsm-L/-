#include <iostream>
#include <string>
using namespace std;

template <typename T>
class stack {
public:
	stack() {
		top_ele = NULL;
	}

	~stack() {
		while (!isEmpty()) {
			pop();
		}
	}

	void push(T ele) {
		if (isEmpty()) {
			top_ele = new elem(ele, NULL);
		} else {
			elem* temp = new elem(ele, top_ele);
			top_ele = temp;
		}
	}

	void pop() {
		if (!isEmpty()) {
			elem* temp = top_ele;
			top_ele = top_ele->next;
			delete temp;
		} else {
			return;
		}
	}

	bool isEmpty() {
		return (top_ele == NULL);
	}

	T top() {
		return top_ele->ele;
	}
private:
	struct elem {
		T ele;
		elem* next;
		elem(T e, elem* n) {
			ele = e;
			next = n;
		}
	};
	elem* top_ele;
};

int main() {
	int num;
	cin >> num;
	string epn;
	while (num--) {
		cin >> epn;
		stack<char> sta;
		bool flag = 0;
		for (int i = 0; i < epn.length(); i++) {
			if (epn[i] == '('||epn[i] == '['|| epn[i] == '{') {
				sta.push(epn[i]);
			}
			if (epn[i] == ')') {
				if (!sta.isEmpty()&& sta.top() == '(') {
					sta.pop();
				} else {
					flag = 1;
				}
			}
			if (epn[i] == ']') {
				if (!sta.isEmpty()&&sta.top() == '[') {
					sta.pop();
				} else {
					flag = 1;
				}
			}
			if (epn[i] == '}') {
				if (!sta.isEmpty()&&sta.top() == '{') {
					sta.pop();
				} else {
					flag = 1;
				}
			}
		}
		if (flag == 0&&sta.isEmpty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}