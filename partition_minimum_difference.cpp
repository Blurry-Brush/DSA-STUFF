int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalsum = 0;
   	for(int i = 0; i < n;i++){
        totalsum += arr[i];
    }
    
   
      vector<vector<bool>> dp(n,vector<bool>(totalsum+1,false));
    for(int i = 0; i < n;i++){
       dp[i][0] = true;
    }
    if(arr[0] <= totalsum) dp[0][arr[0]] = true;
    for(int i = 1; i < n;i++){
        for(int target = 1; target <= totalsum;target++){
            bool notpick = dp[i-1][target];
            bool pick = false;
            if(arr[i] <= target) pick = dp[i-1][target-arr[i]];
            
            dp[i][target] = notpick or pick;
        }    
    }
    
    int mini = 1e9;
    for(int s1 = 0; s1 <= totalsum/2;s1++){
        if(dp[n-1][s1] == true){
            mini = min(mini,abs((totalsum - s1) - s1));
        }
    }
    return mini;
    
    
}
