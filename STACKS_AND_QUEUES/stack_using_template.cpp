#include <bits/stdc++.h>

using namespace std;
template <typename T>

class stackUsingArray {
private:
	T *data; //we don't know the size of stack.
	int nextIndex;
	int capacity;
public:
	//constructor
	stackUsingArray() {
		data = new T[4];
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
	void push(T element) {
		if (nextIndex == capacity) {
			//vector class method
			T  * newData = new T[2 * capacity];
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
	T pop() {
		if (nextIndex == 0) {
			cout << "Stack is empty boi" << endl;
			return 0;
			//0 value works for every data type

		}

		nextIndex--;
		return data[nextIndex];
		//will overwrite the value in next push move
		//treat as garbage value.
	}

	T top() {
		if (isEmpty()) {
			cout << "Stack is empty boi" << endl;
			return 0;
			//0 value works for every data type
		}

		return data[nextIndex - 1];
	}
};
int main() {
	stackUsingArray<int> s;

	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	s.push(106);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;


	return 0;
}
