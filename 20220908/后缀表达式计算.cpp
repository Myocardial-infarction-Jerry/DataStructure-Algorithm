#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	for (; cin >> s;) {
		stack<double> stk;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') stk.push(s[i] - 'a' + 1);
			else if (s[i] == '+') {double tmp = stk.top(); stk.pop(); tmp = stk.top() + tmp; stk.pop(); stk.push(tmp);}
			else if (s[i] == '-') {double tmp = stk.top(); stk.pop(); tmp = stk.top() - tmp; stk.pop(); stk.push(tmp);}
			else if (s[i] == '*') {double tmp = stk.top(); stk.pop(); tmp = stk.top() * tmp; stk.pop(); stk.push(tmp);}
			else if (s[i] == '/') {double tmp = stk.top(); stk.pop(); tmp = stk.top() / tmp; stk.pop(); stk.push(tmp);}
		}
		printf("%.2lf\n", stk.top());
	}
	return 0;
}