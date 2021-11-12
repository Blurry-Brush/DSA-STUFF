class polynomial {

public:
	int * degcoeff;
	int capacity;

	//default constructor

	polynomial() {
		degcoeff = new int[5];

		capacity = 5;

		for (int i = 0; i < capacity; i++) {
			degcoeff[i] = 0;
		}
	}

	//copy constructor

	polynomial(polynomial const &p2) {
		this->capacity = p2.capacity;
		//deep copy
		this-> degcoeff = new int[p2.capacity];
		for (int i = 0; i < p2.capacity; i++) {
			this->degcoeff[i] = p2.degcoeff[i];
		}
	}

	//copy assignment operator overloading

	void operator=(polynomial const &p2) {
		this->capacity = p2.capacity;
		//deep copy
		this-> degcoeff = new int[p2.capacity];
		for (int i = 0; i < p2.capacity; i++) {
			this->degcoeff[i] = p2.degcoeff[i];
		}
	}

	void setCoefficient(int degree, int coefficient) {
		while (degree >= capacity) {
			//double the array and set.
			int * newdegcoeff = new int[2 * capacity];
			for (int i = 0; i < capacity; i++) {
				newdegcoeff[i] = degcoeff[i];
			}
			for (int j = capacity; j < 2 * capacity; j++) {
				newdegcoeff[j] = 0;
			}

			delete [] degcoeff;
			degcoeff = newdegcoeff;
			capacity *= 2;

		}

		degcoeff[degree] = coefficient;
	}
	void setCoefficient2(int degree, int coefficient) {
		while (degree >= capacity) {
			//double the array and set.
			int * newdegcoeff = new int[2 * capacity];
			for (int i = 0; i < capacity; i++) {
				newdegcoeff[i] = degcoeff[i];
			}
			for (int j = capacity; j < 2 * capacity; j++) {
				newdegcoeff[j] = 0;
			}

			delete [] degcoeff;
			degcoeff = newdegcoeff;
			capacity *= 2;

		}

		degcoeff[degree] += coefficient;
	}


	void print() const {
		for (int i = 0; i < capacity; i++) {
			if (degcoeff[i] != 0) {
				cout << degcoeff[i] << "x" << i << " ";
			}
		}
		cout << endl;
	}

	//+ operator overloading
	polynomial operator+(polynomial  &p2) {
		int Max = max(capacity, p2.capacity);

		if (Max == capacity) {
			//setting zero at remaining index of smaller array

			for (int i = p2.capacity; i < capacity; i++) {
				p2.setCoefficient(i, 0);
			}
		}

		if (Max = p2.capacity) {
			for (int i = capacity; i < p2.capacity; i++) {
				setCoefficient(i, 0);
			}
		}


		polynomial p3;
		for (int i = 0; i < Max; i++) {
			p3.setCoefficient(i, degcoeff[i] + p2.degcoeff[i]);
		}

		return p3;
	}


	polynomial operator-(polynomial  &p) {
		polynomial p3;
		for (int i = 0; i < this->capacity; i++) {
			p3.setCoefficient(i, degcoeff[i] - p.degcoeff[i]);
		}

		return p3;
	}

	polynomial operator*(polynomial  &p)  {
		polynomial p3;
		for (int i = 0; i < this->capacity  ; i++) {
			//polynomial p2;

			for (int j = 0; j < p.capacity ; j++) {
				p3.setCoefficient2(i + j, degcoeff[i] * p.degcoeff[j]);
			}
			//p3 = p3 + p2;
		}

		return p3;
	}
};
