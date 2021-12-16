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

vector<int> klargest(int arr[], int n, int k) {
	vector<int> ans;
	priority_queue<int, vector<int> , greater<int> > p;

	for (int i = 0; i < k; i++) {
		p.push(arr[i]);
	}

	for (int i = k; i < n; i++) {
		if (arr[i] > p.top()) {
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

bool checkMaxHeap(vector<int> arr) {
	bool ans = true;

	for (int i = 0; i < arr.size(); i++) {
		int leftchild = 2 * i + 1;
		int rightchild = 2 * i + 2;
		//cout << ans << endl;
		if (leftchild < arr.size() and arr[leftchild] > arr[i]) {
			ans = false;
		}

		if (rightchild < arr.size() and arr[rightchild] > arr[i]) {
			ans = false;
		}
	}
	return ans;
}
int main()
{
	int k;
	cin >> k;
	vector<int> ans;
	priority_queue<int , vector<int> , greater<int> > pq;
	while (k--) {
		int n;
		cin >> n;
		vector<int> arr(n);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			pq.push(arr[i]);
		}
	}

	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}

	for (auto value : ans) {
		cout << value << " ";
	}
	cout << endl;



}
