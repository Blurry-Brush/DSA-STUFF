#include <bits/stdc++.h>

using namespace std;


void reverseStack(stack<int> &s1, stack<int> &s2) {
	int x;
	while (!s1.empty()) {
		x = s1.top();
		s2.push(x);
		s1.pop();
	}
	//s1 = s2; // now s1 is reversed also instead of empty !!!

	while (!s2.empty()) {
		cout << s2.top() << " ";
		s2.pop();
	}
	cout << endl;
}

void reversequeue(queue<int> q) {
	//not working
	if (q.size() == 1) {
		//cout << q.front() << " ";
		return;
	}
	q.pop();
	reversequeue(q);

	cout << q.front() << " ";

}

void reversequeue2(queue<int> &q) {
	if (q.empty()) {
		return;
	}

	int x = q.front();

	q.pop();

	reversequeue2(q);

	q.push(x);
}
void printQueue(queue<int> &Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

int main() {


	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		queue<int> q;

		while (n--) {
			int x;
			cin >> x;
			q.push(x);
		}
		reversequeue(q);
		//printQueue(q);
		cout << endl;
	}

	return 0;
}
