#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;


int sum(int a[] , int size) {
	if (size == 1) {
		return a[0];
	}

	int smaller = sum(a + 1, size - 1);

	return a[0] + smaller;
}

int sum2(int a[] , int n) {
	if (n < 0) return 0;

	return a[n] + sum2(a , n - 1);
}
int main() {

	
	return 0;
}
