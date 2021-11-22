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

bool redundant(string str) {
	stack<char>s;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ')') {
			int count = 0;

			while (true) {
				if (s.top() == '(') {
					break;
				}
				else {
					count++;
					s.pop();
				}
			}

			if (count <=  1) {
				//count 1 when unwanted
				//0 when duplicate
				return true;
			}

			s.pop();

		}
		else {
			s.push(str[i]);
		}
	}

	return false;

}
void printStack(stack<char> st) {
	while (st.size() > 0) {
		cout << st.top() << endl;
		st.pop();
	}
}
vector<int> stockSpan(vector<int> &arr, int n) {
	vector<int> ans;

	stack<int> st;
	st.push(0);
	ans.push_back(1);

	for (int i = 1; i < n; i++) {

		//pop
		while (st.size() > 0 and arr[i] > arr[st.top()]) {
			st.pop();
		}

		if (st.size() == 0) {
			ans.push_back(i + 1); //greatest
		}
		else {
			ans.push_back(i - st.top());
			//next greater to the left.
		}

		st.push(i);
	}

	return ans;
}

int minimumReversal(string s) {
	if (s.length() % 2 != 0) {
		return -1;
	}


	//fill up the stack.
	stack<char> st;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] == '{') {
			st.push('{');
		}
		else {
			//}

			if (st.size() == 0) {
				st.push('}');
			}
			else {

				//top element
				if (st.top() == '{') {
					st.pop(); //balance out
				}
				else {
					st.push('}');
				}

			}
		}
	}
	//cout << st.size() << endl;

	char c1, c2;
	int count = 0;

	while (!st.empty()) {
		c1 = st.top();
		st.pop();
		c2 = st.top();
		st.pop();

		//first two

		if (c1 == c2) {
			count++;
			//{{ or }}
			//only one should be reversed
		}
		else {
			count += 2;
			//}{ only this case
			//{} this is balanced and already taken care of
		}
	}
	return count;
}
int main() {


	string s;
	cin >> s;

	cout << minimumReversal(s) << endl;


	return 0;
}
