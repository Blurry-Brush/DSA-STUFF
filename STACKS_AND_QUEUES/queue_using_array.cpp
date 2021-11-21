#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Queue {
	T * data;
	int nextindex;
	int firstindex;
	int capacity;
	int size;
public:
	Queue(int size) {
		data = new T[size];
		nextindex = 0;
		firstindex = -1;
		this->size = 0;
		capacity = size;
	}

	int getsize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void enqueue(T element) {
		if (size == capacity) {
			//in array 30 40 50 10 20.
			//to copy in the new array 10 20 30 40 50.
			T * newdata = new T[2 * capacity];
			int j = 0;

			for (int i = firstindex; i < capacity; i++) {
				newdata[j] = data[i];
				j++;
			}

			for (int i = 0; i < firstindex; i++) {
				newdata[j] = data[i];
				j++;
			}
			delete [] data;
			data = newdata;

			nextindex = capacity;
			firstindex = 0;
			capacity *= 2;

		}
		data[nextindex] = element;
		nextindex = (nextindex + 1) % capacity;

		if (firstindex == -1) {
			//first index.
			firstindex = 0;
		}
		size++;
	}

	T front() {
		if (isEmpty()) {
			cout << "queue is empty boi" << endl;
			return 0;
		}
		return data[firstindex];
	}

	T dequeue() {
		if (isEmpty()) {
			cout << "queue is empty boi" << endl;
			return 0;
		}
		T ans = data[firstindex];
		firstindex = (firstindex + 1) % capacity;
		size--;

		if (size == 0) {
			nextindex = 0;
			firstindex = -1;
			//not necessary but ok
		}
		return ans;
	}
};

int main() {

	Queue<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;



	cout << q.getsize() << endl;
	cout << q.isEmpty() << endl;

	return 0;
}
