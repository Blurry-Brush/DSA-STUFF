#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,n) for(int i = 0; i < n;i++)

using namespace std;

int count(int n){
	if(n == 0){
		return 0;
	}

	return 1 + count(n/10); // our work
}
int main() {

	int n;
	cin >> n;
	cout << count(n) << endl;


/* input is 456
	 1 + count(45)
	 1 + count(4)
	 1 + count(0) reached base case
	 */
	return 0;
}
