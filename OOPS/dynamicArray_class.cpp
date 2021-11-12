class dynamicArray {
	int * data;
	int nextindex;
	int capacity; //total size of the array


public:
	//default constructor
	dynamicArray() {
		data = new int[5];
		nextindex = 0;
		capacity = 5;
	}
	//copy constructor because changes reflects in shallow copying
	dynamicArray(dynamicArray const &d) {
		this -> nextindex = d.nextindex;
		this -> capacity = d.capacity;
		//deep

		this-> data = new int[d.capacity];
		for (int i = 0; i < d.nextindex; i++) {
			this -> data[i] = d.data[i];
		}

	}

	//copy assignment operator overloading.

	void operator=(dynamicArray const &d) {
		this -> nextindex = d.nextindex;
		this -> capacity = d.capacity;
		//deep

		this-> data = new int[d.capacity];
		for (int i = 0; i < d.nextindex; i++) {
			this -> data[i] = d.data[i];
		}
	}


	void add(int element) {
		if (nextindex == capacity) {
			//make a new array of double the size
			int *newData = new int[2 * capacity];
			//copy from original arary.

			for (int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			//deallocate the memory of original

			delete [] data;
			data = newData;
			capacity *= 2;
			//now rest of the loop will add element.
		}

		data[nextindex] = element;
		nextindex++;
	}

	int get(int i) const {
		if (i < nextindex) {
			return data[i];
		}
		else {
			return -1;
		}
	}

	void add(int i, int element) {
		if (i < nextindex) {
			//no problem
			data[i] = element;
		}
		else if (i == nextindex) {
			add(element);
		}
		else {
			return;
		}
	}

	void print() const {
		for (int i = 0; i < nextindex; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}


};
