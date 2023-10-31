#include <bits/stdc++.h>
using namespace std;

bool Judge(string s) {
	stack<char> stk;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stk.push(s[i]);
		if (s[i] == ')')
			if (!stk.empty() && stk.top() == '(')
				stk.pop();
			else
				return false;
		if (s[i] == ']')
			if (!stk.empty() && stk.top() == '[')
				stk.pop();
			else
				return false;
		if (s[i] == '}')
			if (!stk.empty() && stk.top() == '{')
				stk.pop();
			else
				return false;
	}
	if (!stk.empty()) return false;
	return true;
}

int main(int argc, char const *argv[]) {
	string s;
	for (; cin >> s;)
		cout << (Judge(s) ? "Yes" : "No") << endl;
	return 0;
}