#include <bits/stdc++.h>

using namespace std;



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
		}

		st.push(i);
	}

	return ans;
}
int main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> ans = stockSpan(arr, n);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}



	return 0;
}
