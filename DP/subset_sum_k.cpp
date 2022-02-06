bool f(int ind,int target,vector<int>&arr,vector<vector<int>> &dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool notpick = f(ind-1,target,arr,dp);
    bool pick = false;
    if(target >= arr[ind]){
        pick = f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target] = pick or notpick;
    
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
  //tabulation
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    //k belongs to 0 to target so k+1 terms
//    return f(n-1,k,arr,dp);
    
    for(int i = 0; i < n;i++){
       dp[i][0] = true;
    }
    if(arr[0] <= k) dp[0][arr[0]] = true;
    for(int i = 1; i < n;i++){
        for(int target = 1; target <= k;target++){
            bool notpick = dp[i-1][target];
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            dp[i][target] = notpick or pick;
        }    
    }
    
    return dp[n-1][k];
  
  
  
  
  //space optimization
	vector<bool> prev(k+1,0), cur(k+1,0);
    prev[0] = cur[0] = true;
    //k belongs to 0 to target so k+1 terms
//    return f(n-1,k,arr,dp);
    
   	
    if(arr[0] <= k) prev[arr[0]] = true;
    for(int i = 1; i < n;i++){
        for(int target = 1; target <= k;target++){
            bool notpick = prev[target];
            bool pick = false;
            if(arr[i] <= target) pick = prev[target-arr[i]];
            cur[target] = notpick or pick;
        }    
        prev = cur;
    }
    
    return prev[k];
    
    
}
