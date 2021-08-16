#include <bits/stdc++.h>

using namespace std;

void print2d(int arr[][100], int n, int m)
{
    //providing rows is optional but columns must be provided,

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void spiralPrint(int arr[][10], int n, int m)
{

    int startrow = 0;
    int endrow = n - 1;
    int startcol = 0;
    int endcol = m - 1;

    while (startrow <= endrow and startcol <= endcol)
    {
        //startrow
        for (int col = startrow; col <= endcol; col++)
        {
            cout << arr[startrow][col] << " ";
        }

        //endcol

        for (int row = startrow + 1; row <= endrow; row++)
        {
            cout << arr[row][endcol] << " ";
        }

        //endrow

        for (int col = endcol - 1; col >= startcol; col--)
        {

            if (startrow == endrow)
            {
                break;
            }
            cout << arr[endrow][col] << " ";
        }

        //startcol

        for (int row = endrow - 1; row >= startrow + 1; row--)
        {

            if (startcol == endcol)
            {
                break;
            }
            cout << arr[row][startcol] << " ";
        }

        startrow++;
        endcol--;
        endrow--;
        startcol++;
    }
}
int main()
{

    //int arr[100][100];

    //int n, m;
    // cin >> n >> m;

    //    print2d(arr, n, m);

    char numbers[][100] = {
        "one", //each string is a row of chars.
        "two",
        "three",
    };

    //cout << numbers[2] << endl;

    int arr[][10] = {
        {1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};

    int n = 4;
    int m = 4;

    spiralPrint(arr, n, m);

    return 0;
}