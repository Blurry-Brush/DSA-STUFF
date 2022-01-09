#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {

	int s = 0;
	int e = x;
	long long int ans = -1;
	while (s <= e) {
		long long int mid = (s + e) / 2;

		if (mid * mid == x) {
			//perfect square
			return mid;
		}
		else if (mid * mid > x) {
			e = mid - 1;
		}
		else {
			ans = mid;
			s = mid + 1;
		}
	}
	return ans;

}

double morePrecision(int n, int precision, int tempans) {
	double factor = 1;
	double ans = tempans;

	for (int i = 0; i < precision; i++) {
		factor = factor / 10;

		for (double j = tempans; j * j < n; j += factor) {
			//updating answer each time
			ans = j;
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int tempans = mySqrt(n);
	cout << morePrecision(n, 3, tempans) << endl;
	return 0;
}


