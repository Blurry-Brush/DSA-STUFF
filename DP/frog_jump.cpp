//memoization code
int f(int n,vector<int> &height,vector<int>&dp){
    if(n == 0){
        return 0;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    int right = 2147483647;
    int left = f(n-1,height,dp) + abs(height[n] - height[n-1]);
    if(n > 1){
      right = f(n-2,height,dp) + abs(height[n] - height[n-2]);     
    }
    
    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{	
    vector<int> dp(n+1,-1);
    //convereted into 0 based indexing
    return f(n-1,heights,dp);
    // Write your code here.
}

//tabulation 
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    for(int i = 1; i < n;i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        
        dp[i] = min(left,right);
    }
    return dp[n-1]
}

//space optimization
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    
    int prev = 0;
    int prev2 = 0;
    
    for(int i = 1; i < n;i++){
        int left = prev + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i > 1){
            right = prev2 + abs(heights[i]-heights[i-2]);
        }
		int curi = min(left,right);  
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
