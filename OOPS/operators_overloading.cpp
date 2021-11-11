class Fraction {
private:
	int numerator;
	int denominator;
public :



	Fraction() {
		//default constructor
	}
	void setNumerator(int n) {
		numerator = n;
	}

	void setDenominator(int d) {
		denominator = d;
	}

	int getNumerator() const {
		return numerator;
	}

	int getDenominator() const {
		return denominator;
	}

	Fraction(int numerator, int denominator) {
		//parametrized constructor.

		this -> numerator = numerator;
		this -> denominator = denominator;
	}

	void print() const {
		cout << this -> numerator << " / " << denominator << endl;
	}

	Fraction add(Fraction const &f2) {

		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;

		int num = x * numerator + y * (f2.numerator);

		//numerator = num;
		//denominator = lcm;

		Fraction fnew(num, lcm);
		fnew.simplify(); //by default this

		return fnew;
	}

	Fraction operator+(Fraction const &f2) const {

		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;

		int num = x * numerator + y * (f2.numerator);

		//numerator = num;
		//denominator = lcm;

		Fraction fnew(num, lcm);
		fnew.simplify(); //by default this

		return fnew;
	}

	void multiply(Fraction const &f2) {
		numerator *= f2.numerator;
		denominator *= f2.denominator;

		simplify();
	}

	Fraction operator*(Fraction const &f2) const {
		Fraction fnew1(this->numerator * f2.numerator, this->denominator * f2.denominator);
		fnew1.simplify();
		return fnew1;
	}

	bool operator==(Fraction const &f2) const {

		return (numerator == f2.numerator and denominator == f2.denominator);
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

	//pre-increment

	Fraction& operator++() {
		//add one
		//(num+denom)/denom


		numerator = numerator + denominator;
		simplify();

		return *this;
	}
	//post-increment

	Fraction operator++(int) {
		Fraction Fnew(numerator, denominator);

		numerator = numerator + denominator;
		simplify();
		Fnew.simplify();

		return Fnew;
	}

	//+= operator
	Fraction& operator+=(Fraction const &f2) {
		int lcm = denominator * f2.denominator;
		int x = lcm / denominator;
		int y = lcm / f2.denominator;

		int num = x * numerator + y * (f2.numerator);

		numerator = num;
		denominator = lcm;

		simplify();
		//Fraction fnew(num, lcm);
		//fnew.simplify(); //by default this

		return *this;
	}
};
