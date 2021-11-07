class Fraction {
private:
	int numerator;
	int denominator;
public :

	Fraction(int numerator, int denominator) {
		this -> numerator = numerator;
		this -> denominator = denominator;
	}

	void print() {
		cout << this -> numerator << " / " << denominator << endl;
	}

	void add(Fraction const &f2) {

		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;

		int num = x * numerator + y * (f2.numerator);

		numerator = num;
		denominator = lcm;

		simplify(); //by default this

	}

	void multiply(Fraction const &f2) {
		numerator *= f2.numerator;
		denominator *= f2.denominator;

		simplify();
	}

	void simplify() {
		int gcd = 1;
		int j = min(numerator, denominator);

		for (int i = 1 ; i <= j; i++) {
			if (numerator % i == 0 and denominator % i == 0)
				gcd = i;
		}
		numerator /= gcd;
		denominator /= gcd;
	}
};
