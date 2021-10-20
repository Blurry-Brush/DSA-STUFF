#include <bits/stdc++.h>
using namespace std;

int subsequence(string input, string output[]) {
	if (input.empty()) {
		output[0] += "";
		return 1;
	}
	string smallString = input.substr(1);

	int smallOutput = subsequence(smallString, output);

	for (int i = 0; i < smallOutput; i++) {
		output[i + smallOutput] = input[0] + output[i];
	}

	return 2 * smallOutput; //in copying the size doubles.
}
int main()
{

	string input;
	cin >> input;
	string* output = new string[1000];

	int count = subsequence(input, output);

	for (int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}
	return 0;
}


