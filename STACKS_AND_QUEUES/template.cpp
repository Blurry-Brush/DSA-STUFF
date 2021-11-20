#include <bits/stdc++.h>

using namespace std;

template <typename T, typename V>


//t is the temporary variable.

class Pair {
	T x;
	V y;

public:
	void setX(T x) {
		this->x = x;
	}
	void setY(V y) {
		this->y = y;
	}

	T getX() {
		return this->x;
	}
	V getY() {
		return this->y;
	}

};

int main() {

	Pair<Pair<int, int>, int> p;
	p.setY(10);

	Pair<int, int> p2;
	p2.setX(5);
	p2.setY(16);

	p.setX(p2);

	cout << p.getX().getX() << " " << p.getX().getY() << " " << p.getY() << endl;
	// Pair<int, double> p1;

	// p1.setX(10);
	// p1.setY(20.6767);

	// cout << p1.getX() << " " << p1.getY() << endl;
	return 0;
}
