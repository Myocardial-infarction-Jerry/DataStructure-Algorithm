#include <bits/stdc++.h>
using namespace std;

struct Student {
	int a, b, c, tot, id;
	Student(int _a, int _b, int _c, int _id) : a(_a), b(_b), c(_c), tot(_a + _b + _c), id(_id) {}
	friend bool operator < (const Student &p, const Student &q) {
		if (p.tot == q.tot)
			if (p.a == q.a) return p.id > q.id;
			else return p.a < q.a;
		else return p.tot < q.tot;
	}
};

int main(int argc, char const *argv[]) {
	// freopen("init.in", "r", stdin);
	for (int n; cin >> n;) {
		priority_queue<Student> hep;
		for (int i = 0; i < n; i++) {
			int a, b, c; cin >> a >> b >> c;
			hep.push(Student(a, b, c, i + 1));
		}
		for (int i = 0; i < 5; i++) {
			auto tmp = hep.top(); hep.pop();
			cout << tmp.id << " " << tmp.tot << endl;
		}
	}
	return 0;
}