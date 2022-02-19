int f(int ind,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
    if(ind == 0){
        if(wt[0] <= W) return val[0];
         return 0;
    }
    
    if(dp[ind][W] != -1) return dp[ind][W];
    
    int notTake = 0 + f(ind-1,W,wt,val,dp);
    int take = INT_MIN;
    if(wt[ind] <= W) take = val[ind] + f(ind-1,W-wt[ind],wt,val,dp);
    
    return dp[ind][W] = max(take,notTake);
}
int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
   // return f(n-1,maxWeight,weight,value,dp);
	
    //space optimization with single array only
    vector<int> prev(maxWeight+1,0);
    
    for(int w = wt[0]; w <= maxWeight;w++){
        prev[w] = val[0];
    }
    
    for(int ind = 1; ind < n;ind ++){
        for(int W = maxWeight; W >=0 ;W--){
            int notTake = 0 + prev[W];
    		int take = INT_MIN;
    		if(wt[ind] <= W) take = val[ind] + prev[W - wt[ind]];
    		prev[W] = max(take,notTake);
        }
    }
    return prev[maxWeight];
   
    
    
}
