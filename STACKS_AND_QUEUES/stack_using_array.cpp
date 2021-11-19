#include <bits/stdc++.h>

using namespace std;

class stackUsingArray {
private:
	int *data; //we don't know the size of stack.
	int nextIndex;
	int capacity;
public:
	//constructor
	stackUsingArray() {
		data = new int[4];
		nextIndex = 0;
		capacity = 4;
	}
	//return the no of elements present in the stack

	int size() {
		return nextIndex;
	}

	//check if the stack is empty
	bool isEmpty() {
		return (nextIndex == 0);
	}

	//insert an element in the stack
	void push(int element) {
		if (nextIndex == capacity) {
			//vector class method
			int  * newData = new int[2 * capacity];
			for (int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			delete data;
			data = newData;
			capacity *= 2;
		}


		data[nextIndex] =  element;
		nextIndex++;
	}
	//delete and return the element
	int pop() {
		if (nextIndex == 0) {
			cout << "Stack is empty boi" << endl;
			return INT_MIN;
		}

		nextIndex--;
		return data[nextIndex];
		//will overwrite the value in next push move
		//treat as garbage value.
	}

	int top() {
		if (isEmpty()) {
			cout << "Stack is empty boi" << endl;
			return INT_MIN;
		}

		return data[nextIndex - 1];
	}
};
int main() {
	

	return 0;
}
