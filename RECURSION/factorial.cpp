#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}

	int smallOutput = factorial(n - 1);
	int output = n * smallOutput;
	return output;
}

int main() {

	int n;
	cin >> n;
	cout << factorial(n) << endl;

	return 0;
}
