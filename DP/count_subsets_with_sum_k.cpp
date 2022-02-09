int f(int ind,int sum,vector<int>&num,vector<vector<int>>&dp){
   
    if(ind == 0){
        if(sum == 0 and num[0] == 0) return 2;
        if(sum == 0 or num[0] == sum) return 1;
        return 0;
    }
    
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int notpick = f(ind-1,sum,num,dp);
    int pick = 0;
    if(num[ind] <= sum) pick = f(ind-1,sum - num[ind],num,dp);
	
    return dp[ind][sum] = notpick + pick;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);
    
    
    for(int i = 0; i < n;i++){
        dp[i][0] = 1;
    }
    if(num[0] <= tar) dp[0][num[0]] = 1;
    
    for(int ind = 1; ind < n;ind++){
        for(int sum = 1; sum <= tar;sum++){
                int notpick = dp[ind-1][sum];
    			int pick = 0;
    			if(num[ind] <= sum) pick = dp[ind-1][sum - num[ind]];
	
    			dp[ind][sum] = notpick + pick;
        }
    }
    //return dp[n-1][tar];
}
