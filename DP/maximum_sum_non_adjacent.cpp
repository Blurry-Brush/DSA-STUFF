int f(int index,vector<int> &nums,vector<int>&dp){
    if(index == 0){
		return nums[0];	
    }
    if(index < 1){
        return 0;
    }
    
    if(dp[index] != -1){
        return dp[index];
    }
    
    int pick = nums[index] + f(index-2,nums,dp);
    int notpick = f(index-1,nums,dp);
    return dp[index] = max(pick,notpick);
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
   	vector<int> dp(n,0);
    
    int prev,prev2;
    prev = nums[0];
    prev2 = 0;
    
    for(int i = 1; i < n;i++){
        int pik = nums[i] + prev2;
        int notpik = prev;
        int curi = max(pik,notpik);
        
        prev2 = prev;
        prev = curi;
        //dp[i] = max(pik,notpik);
    }
    return prev;
}
