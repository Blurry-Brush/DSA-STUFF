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

const int N = 1e3 + 10;
int ar[N][N];           // zeroth row and column is zero by default
long long prefix[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin  >> t;

    while (t--) {

        int n, q;
        cin >> n >> q;
        int a[n + 10];

        int forward[n + 10];
        int backward[n + 10];

        forward[0] = backward[n + 1] = 0;
        // gcd of any no with 0 is same number.

        for (int i = 1; i <= n; i++) {
            cin >> a[i]; //a b c d e f g h
        }
        for (int i = 1; i <= n; i++) {
            forward[i] = __gcd(forward[i - 1], a[i]);
        }

        //forward == a ab abc abcd abcde abcdef abcdefg abcdefgh
        for (int i = n; i >= 1; i--) {
            backward[i] = __gcd(backward[i + 1] , a[i]);
        }
        //backward ==    abcdefgh bcdefgh cdefgh defgh efgh fgh gh h

        while (q--) {
            int l, r;
            cin >> l >> r;

            cout << __gcd(forward[l - 1] , backward[r + 1]) << endl;
        }
    }
    return 0;


}
