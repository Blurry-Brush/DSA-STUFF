class complexNumbers {
private :
	int real;
	int imaginary;

public :

	complexNumbers(int real, int imaginary) {
		this -> real = real;
		this -> imaginary = imaginary;
	}
	void print() {
		cout << real << " + " << imaginary << "i" << endl;
	}

	void plus(complexNumbers const &c2) {
		real += c2.real;
		imaginary += c2.imaginary;
	}

	void multiply(complexNumbers const &c2) {

		int x = real * c2.real - imaginary * c2.imaginary;
		int y = real * c2.imaginary + imaginary * c2.real;
		real = x;
		imaginary = y;
	}

};
