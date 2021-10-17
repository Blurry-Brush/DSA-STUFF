#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;

void print(int n) {
	if (n == 1) {
		cout << n << " ";
		return;
	}

	print(n - 1);
	cout << n << " ";
}
int main() {

	print(3);

	return 0;
}
