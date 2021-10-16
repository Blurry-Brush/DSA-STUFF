#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;

int fib(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}

	int smalloutput1 = fib(n - 1);
	int smalloutput2 = fib(n - 2);

	return smalloutput1 + smalloutput2;
}

int main() {
	cout << fib(3) << endl;
	return 0;
}
