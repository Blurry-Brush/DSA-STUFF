// C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

void kSortedArray(int input[], int n, int k) {
	priority_queue<int>pq;

	for (int i = 0; i < k; i++) {
		pq.push(input[i]);
	}

	for (int i = 0; i < n; i++) {
		input[i] = pq.top();
		pq.pop();

		if (i + k < n) {
			pq.push(input[i + k]);
		}

	}
}

vector<int> ksmallest(int arr[], int n, int k) {
	vector<int> ans;
	priority_queue<int> p;

	for (int i = 0; i < k; i++) {
		p.push(arr[i]);
	}

	for (int i = k; i < n; i++) {
		if (arr[i] < p.top()) {
			p.pop();
			p.push(arr[i]);
		}
	}

	while (!p.empty()) {
		ans.push_back(p.top());
		p.pop();
	}
	return ans;
}
int main()
{
	int n, k;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	vector<int> ans = ksmallest(arr, n, k);
	for (auto value : ans) {
		cout << value << " ";
	}
	cout << endl;
}
