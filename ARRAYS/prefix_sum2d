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
int ar[N][N];
long long prefix[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//1 based indexing,instead of zero.
    //insert zero on extra layer
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ar[i][j];
            prefix[i][j] = ar[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    int q;
    cin >> q;
//a,b top left c,d bottom right
// find the sum of the rectangle enclosed by them
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1] << endl;
    }
    return 0;
}
