#include <bits/stdc++.h>

#define fo(i, n) for (int i = 0; i < n; i++)
#define rep(n, m) for (int i = n; i <= m; i++)
#define all(v) v.begin(), v.end()
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define os(st) unordered_set<int> st;

using namespace std;

pair<int, int> staircaseSearch(int arr[][4], int n, int m, int key) {

    //return pair {-1,-1} if the element is not present.
    if (key < arr[0][0] || key > arr[n - 1][m - 1]) {
        return { -1, -1};

    }

    //else

    int i = 0;
    int j = m - 1;

    while (i <= n - 1 and j >= 0) {
        if (arr[i][j] == key) {
            return {i, j};
        }
        else if (arr[i][j] > key) {
            j--;
        }
        else {
            i++;
        }
    }


    return { -1, -1};
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // printf("%.9f\n" , ans)


    int arr[][4] = { {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    int key = 33;
    int cur = arr[0][3];

    int n = 4;
    int m = 4;

    pair<int, int> cords = staircaseSearch(arr, n, m, 50);

    cout << cords.ff << " " << cords.ss << endl;
    return 0;
}
