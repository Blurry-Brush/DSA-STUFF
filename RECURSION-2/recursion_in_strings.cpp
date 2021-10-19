#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;

int length(char s[]) {
	if (s[0] == '\0') {
		return 0;
	}
	int smallans = length(s + 1);
	return 1 + smallans;
}

void removeX(char s[]) {
	if (s[0] == '\0') {
		return;
	}

	removeX(s + 1);

	if (s[0] == 'x') {
		int i = 1;
		for (; s[i] != '\0' ; i++) {
			s[i - 1] = s[i];
		}
		s[i - 1] = s[i];

	}
}
int main() {

	char str [200];
	cin >> str;
	removeX(str);
	cout << str << endl;
	return 0;
}
