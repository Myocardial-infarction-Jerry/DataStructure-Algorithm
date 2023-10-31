#include <bits/stdc++.h>
using namespace std;

int pos;
string s;

string Transfer() {
	stack<string> stk, opt;
	if (s[pos] == '(') {
		pos++; stk.push(Transfer());
	}
	else {
		stk.push(s.substr(pos, 1)); pos++;
	}
	for (; s[pos] != ')';) {
		opt.push(s.substr(pos, 1));
		if (s[pos + 1] == '(') {
			pos += 2;
			stk.push(Transfer());
		}
		else {stk.push(s.substr(pos + 1, 1)); pos += 2;}
		for (; !opt.empty() && (opt.top() == "*" || opt.top() == "/"); opt.pop()) {
			string tmp = stk.top(); stk.pop();
			tmp = stk.top() + tmp + opt.top(); stk.pop();
			stk.push(tmp);
		}
	}
	pos++;
	string tmp = "";
	for (; !opt.empty(); opt.pop(), stk.pop())
		tmp = stk.top() + opt.top() + tmp;
	return stk.top() + tmp;
}

int main(int argc, char const *argv[]) {
	cin >> s; s += ")";
	// s = "a+((b-c)*d+e)/f)";
	cout << Transfer() << endl;
	return 0;
}