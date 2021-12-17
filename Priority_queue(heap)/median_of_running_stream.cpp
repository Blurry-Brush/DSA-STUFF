#include <bits/stdc++.h>

using namespace std;


int main()
{

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int median;

	for (int i = 0; i < n; i++) {
		int element = v[i];

		if (i == 0) {
			median = element;
			cout << "Median upto " << i + 1 << "th element is " << median << endl;
			maxHeap.push(element);
		}
		else {

			if (element < maxHeap.top()) {
				//checking if the element belongs in the maxheap
				maxHeap.push(element);
			}
			else {
				minHeap.push(element);
			}


			if (labs(minHeap.size() - maxHeap.size()) > 1) {
				//balance both heaps
				if (minHeap.size() > maxHeap.size()) {
					maxHeap.push(minHeap.top());
					minHeap.pop();
				}
				else {
					minHeap.push(maxHeap.top());
					maxHeap.pop();
				}
			}

			//returning the median
			if (maxHeap.size() == minHeap.size()) {
				//even elements in the stream
				median = (maxHeap.top() + minHeap.top()) / 2;
				cout << "Median upto " << i + 1 << "th element is " << median << endl;

			}
			else if (maxHeap.size() > minHeap.size()) {
				median = maxHeap.top();
				cout << "Median upto " << i + 1 << "th element is " << median << endl;

			}
			else {
				median = minHeap.top();
				cout << "Median upto " << i + 1 << "th element is " << median << endl;

			}
		}

	}

	return 0;

}
