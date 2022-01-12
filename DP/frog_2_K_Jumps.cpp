#include <bits/stdc++.h>

using namespace std;

int frog(int n,int k,vector<int> &heights,vector<int> &dp){
    if(n == 0){
        return 0;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    //do stuff
    int ans = INT_MAX;
    for(int i = 1;i <= k;i++){
        if(n-i >= 0){
        int left = frog(n-i,k,heights,dp) + abs(heights[n] - heights[n-i]);
        ans = min(ans,left);
    }
    }
    return dp[n] = ans;   
}

int frog_tabulation(int n,int k,vector<int>&height,vector<int>&dp){
    dp[0] = 0;

    for(int i=1; i < n;i++){
        int ans = INT_MAX;

        for(int j = 1; j <= k;j++){
            if(i-j >=0){
                int left = dp[i-j] + abs(height[i] - height[i-j]);
                ans = min(left,ans); 
            }
        }
        dp[i] = ans;
    }
    return dp[n-1];
}
int main(){
    int n,k;
    cin >> n >> k;

    vector<int> heights(n);
    vector<int> dp(n+1,-1);
    for(int i = 0; i < n;i++){
        cin >> heights[i];
    }
    cout << frog(n-1,k,heights,dp) << endl;

    cout << frog_tabulation(n,k,heights,dp) << endl;
    return 0;
}
