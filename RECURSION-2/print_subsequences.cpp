#include <bits/stdc++.h>
using namespace std;

void print_subs(string input, string output) {
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	print_subs(input.substr(1) , output); //include in output,
	print_subs(input.substr(1) , output + input[0]); //not include in the output.
}


int main()
{

	string input;
	cin >> input;
	string s;
	print_subs(input, s);

	return 0;
}


