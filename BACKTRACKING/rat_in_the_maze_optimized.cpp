#include <bits/stdc++.h>

#define fo(i,n) for(ll i = 0;i<n;i++)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ull unsigned long long


using namespace std;
void solve(int i, int j , vector<vector<int>> &a, int n, vector<string> &ans , string move, vector<vector<int>> &vis) {
    if (i  == n - 1 and j == n - 1) {
        ans.push_back(move);
        return;
    }
    //following lexiographically order.
    //down
    if (i + 1 < n and !vis[i + 1][j] and a[i + 1][j] == 1) {
        vis[i + 1][j] == 1;
        solve(i + 1, j, a, n, ans, move + 'D' , vis);
        //backtracking step, unmarking when coming back.
        vis[i + 1][j] == 0;
    }
    //left
    if (j - 1 >= 0 and !vis[i][j - 1] and a[i][j - 1] == 1) {
        vis[i][j - 1] == 1;
        solve(i, j - 1, a, n, ans, move + 'L' , vis);
        //backtracking step, unmarking when coming back.
        vis[i][j - 1] == 0;
    }
    //right
    if (j + 1 < n and !vis[i][j + 1] and a[i][j + 1] == 1) {
        vis[i][j + 1] == 1;
        solve(i, j + 1, a, n, ans, move + 'R' , vis);
        //backtracking step, unmarking when coming back.
        vis[i][j + 1] == 0;
    }
    //up
    if (i - 1 >= 0  and !vis[i - 1][j] and a[i - 1][j] == 1) {
        vis[i - 1][j] == 1;
        solve(i - 1, j, a, n, ans, move + 'U' , vis);
        //backtracking step, unmarking when coming back.
        vis[i - 1][j] == 0;
    }

}


vector<string> findPath(vector<vector<int>> &m , int n) {

    
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int> (n, 0));

    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, "", vis);
    return ans;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
    return 0;

}
