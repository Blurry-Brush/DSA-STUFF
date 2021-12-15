#include <bits/stdc++.h>
using namespace std;

class priorityQueue {
	vector<int> pq;
public:

	priorityQueue() {

	}

	bool isEmpty() {
		return pq.size() == 0;
	}
	int getMin() {
		if (isEmpty()) {
			return 0;
		}
		return pq[0];
	}
	int size() {
		return pq.size();
	}

	void insert(int element) {
		pq.push_back(element);

		int childIndex = pq.size() - 1;

		//root
		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if (pq[childIndex] < pq[parentIndex]) {
				swap(pq[childIndex] , pq[parentIndex]);
			}
			else {
				//correct position other than root
				break;
			}

			childIndex = parentIndex;

		}
	}
	int removeMin() {
		if (isEmpty()) {
			return 0;
		}

		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();
		int n = pq.size();

		int parentIndex = 0;

		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

		while (leftChildIndex < n) {

			int minIndex = parentIndex;
			if (pq[leftChildIndex] < pq[minIndex]) {
				minIndex = leftChildIndex;
			}

			if (rightChildIndex < n and pq[rightChildIndex] < pq[minIndex]) {
				minIndex = rightChildIndex;
			}

			if (minIndex == parentIndex) {
				break;
				//correct position
			}

			swap(pq[minIndex], pq[parentIndex]);
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;

		}

		return ans;

	}

};


void inplaceHeapSort(int pq[], int size) {
	//insert

	for (int i = 1; i < size; i++) {
		int childIndex = i;

		//root
		while (childIndex > 0) {
			int parentIndex = (childIndex - 1) / 2;

			if (pq[childIndex] < pq[parentIndex]) {
				swap(pq[childIndex] , pq[parentIndex]);
			}
			else {
				//correct position other than root
				break;
			}

			childIndex = parentIndex;

		}
	}
	//remove elements

	while (size > 1) {
		swap(pq[0], pq[size - 1]);
		size--;

		int parentIndex = 0;

		int leftChildIndex = 2 * parentIndex + 1;
		int rightChildIndex = 2 * parentIndex + 2;

		while (leftChildIndex < size) {

			int minIndex = parentIndex;
			if (pq[leftChildIndex] < pq[minIndex]) {
				minIndex = leftChildIndex;
			}

			if (rightChildIndex < size and pq[rightChildIndex] < pq[minIndex]) {
				minIndex = rightChildIndex;
			}

			if (minIndex == parentIndex) {
				break;
				//correct position
			}

			swap(pq[minIndex], pq[parentIndex]);
			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;

		}


	}

}
int main() {

	int input[5] = {0, 5, 6, 2, 1};
	inplaceHeapSort(input, 5);

	for (int i = 0; i < 5; i++) {
		cout << input[i] << endl;
	}
	return 0;
}
