int f(int ind,int n,vector<int> &val,vector<vector<int>>&dp){
    if(ind == 0){
        return n*val[0];
    }
    if(n == 0) return 0;
    
    if(dp[ind][n] != -1) return dp[ind][n];
    
    int nottake = 0 + f(ind-1,n,val,dp);
    int rodlength = ind+1;
    int take = -1e8;
    if(rodlength <= n){
         take = val[ind] + f(ind,n - rodlength,val,dp);
    }
    return dp[ind][n] = max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
 	//vector<vector<int>> dp(n,vector<int>(n+1,0));
    vector<int> prev(n+1,0);
    for(int N = 0; N <= n;N++){
        prev[N] = N * price[0];
    }
    
    for(int ind = 1; ind < n;ind++){
        for(int N = 0; N <= n;N++){
			int notTake = prev[N];
            int take = INT_MIN;
            int rodLength = ind+1;
            if(N >= rodLength){
				take = price[ind] + prev[N - rodLength];
            }
            
            prev[N] = max(take,notTake);
        }
    }
    return prev[n];
}
