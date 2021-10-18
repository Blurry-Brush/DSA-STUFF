#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;


bool palindrome(char arr[], int size) {

	if (size == 1) {
		return true;
	}
	if (size == 0) {
		return false;
	}

	bool smallans = palindrome(arr + 1, size - 2);
	return smallans and arr[0] == arr[size - 1];
}

int main() {

	char arr[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};
	char arr2[] = {'a'};
	char arr3[] = {'a', 'b', 'c'};

	cout << palindrome(arr3, 3);
	
	return 0;
}
