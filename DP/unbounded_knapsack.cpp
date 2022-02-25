int f(int ind,int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp){
    if(ind == 0){
		return (w/wt[0])*val[0];
    }
    
    if(dp[ind][w] != -1) return dp[ind][w];
    int notpick = 0 + f(ind-1,w,val,wt,dp);
    int pick = -1e8;
    if(wt[ind] <= w) pick = val[ind] + f(ind,w-wt[ind],val,wt,dp);
    
    return dp[ind][w] = max(notpick,pick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    //vector<vector<int>> dp(n,vector<int> (w+1,0));
	vector<int> prev(w+1,0);
    for(int wt = 0; wt <= w;wt++){
        prev[wt] = (wt/weight[0])*profit[0];
    }
    
    for(int ind = 1;ind < n;ind++){
        for(int wt = 0; wt <= w; wt++){
             int notpick = 0 + prev[wt];
    		 int pick = 0;
    if(weight[ind] <= wt) pick = profit[ind] + prev[wt - weight[ind]];
    
        prev[wt] = max(notpick,pick);
        }
    }
    return prev[w];
    //return f(n-1,w,profit,weight,dp);
}
