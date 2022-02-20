#include <vector>
long f(int ind,int target,vector<vector<long>> &dp, int *coins){
	if(ind == 0){
        if(target%coins[0] == 0) return 1;
        else return 0;
    }
    
    if(dp[ind][target] != -1) return dp[ind][target];
    long notpick = 0 + f(ind-1,target,dp,coins);
    long pick = 0;
    if(coins[ind] <= target) pick = f(ind,target-coins[ind],dp,coins);
    
    return dp[ind][target] = pick + notpick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    //tabulation
    for(int tar = 0; tar <= value;tar++){
        if(tar%denominations[0] == 0){
            dp[0][tar] = 1;
        }
        else{
            dp[0][tar] = 0;
        }
    }
    
    for(int ind = 1; ind < n;ind++){
        for(int target = 0;target <= value;target++){
            long notpick = 0 + dp[ind-1][target];
    		long pick = 0;
    	if(denominations[ind] <= target) pick = dp[ind][target-denominations[ind]];
    
        dp[ind][target] = pick + notpick;
        }
    }
    return dp[n-1][value];
    //return f(n-1,value,dp,denominations);
}
