int f(int ind,int T,vector<int>&nums,vector<vector<int>> &dp){
    if(ind == 0){
        if(T%nums[0] == 0) return T/nums[0];
         return 1e9;
    }
    if(dp[ind][T] != -1) return dp[ind][T];
    
    int notpick = 0 + f(ind-1,T,nums,dp);
    int pick = INT_MAX;
    if(nums[ind] <= T) pick = 1 + f(ind,T-nums[ind],nums,dp);
    
    return dp[ind][T] = min(pick,notpick);
}
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    //vector<vector<int>> dp(n,vector<int>(x+1,0));
    vector<int> prev(x+1,0) , cur(x+1,0);
    
    
    for(int target = 0; target <= x;target++){
        if(target%nums[0] == 0){
            prev[target] = target/nums[0];
        }
        else{
            prev[target] = 1e9;
        }
    }
    
    for(int ind = 1;ind < n;ind++){
        for(int tar = 0; tar <= x;tar++){
             int notpick = 0 + prev[tar];
    		 int pick = INT_MAX;
    		 if(nums[ind] <= tar) pick = 1 + cur[tar-nums[ind]];
    
     		cur[tar] = min(pick,notpick);
        }
        prev = cur;
    }
    int ans =  prev[x];
     if(ans >= 1e9) return -1;
    return ans;
}
