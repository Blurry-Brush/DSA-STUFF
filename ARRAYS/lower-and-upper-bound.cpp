#include <bits/stdc++.h>

#define fo(i,n) for(ll i = 0;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ull unsigned long long
using namespace std;

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;

    while (n != 0)
    {
        remainder = n % 2;
//       cout << "Step " << step++ << ": " << n << "/2, Remainder = " << remainder << ", Quotient = " << n/2 << endl;
        n /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

long long binarytodecimal(string s) {
    reverse(s.begin(), s.end());
    long long ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            ans += pow(2, i);
        }
    }

    return ans;
}

string shiftmine(string s) {
    string temp;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        temp += s[i];
    }
    temp += s[0];


    return temp;
}

string shift(string s, int n) {
    int i;
    char temp;
    for (i = 0; i < n - 1; i++) {
        temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;

    }
    return s;
}
const int N = 1e3 + 10;
int ar[N][N];           // zeroth row and column is zero by default
long long prefix[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


//lower bound (right)
// minimum element greater than or equal to target

    int l = -1;
    int r = n;

    while (l + 1 < r ) {
        int mid = (l + r) / 2;

        if (v[mid] < target ) {
            l = mid;
        }
        else {
            r = mid;
        }

    }
    cout << r + 1 << endl;


//upper bound(left)
// macimum element less than or equal to target

    int l = -1;
    int r = n;

    while (l + 1 < r) {
        int mid = (l + r) / 2;

        if (v[mid] <= target) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l + 1 << endl;

//fast search
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int k;
    cin >> k;
    while (k--) {

        int c, d;
        cin >> c >> d;


        auto it1  = lower_bound(v.begin(), v.end(), c); //right
        auto it2 = upper_bound(v.begin(), v.end(), d); //left

        int p = it1 - v.begin();
        int q = it2 - v.begin();

        //cout << q - p  << endl;
        cout << p << " " << q << endl;
    }



    return 0;
}
