#include <bits/stdc++.h>

using namespace std;

vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> ans;
    // your code goes here
    int startcol = n - 1;
    int endcol = 0;
    int curcol = n - 1;

    while (curcol >= endcol)
    {
        int startrow = 0;
        int endrow = m - 1;

        if ((startcol - curcol) % 2 != 0)
        {
            startrow = m - 1;
            endrow = 0;
            for (int row = startrow; row >= endrow; row--)
            {
                ans.push_back(arr[row][curcol]);
            }
        }
        else
        {

            for (int row = startrow; row <= endrow; row++)
            {
                ans.push_back(arr[row][curcol]);
            }
        }

        curcol--;
    }

    return ans;
}
int main()
{

    vector<int> arr = { {} } vector<int> ans = WavePrint(m, n, arr);

    return 0;
}