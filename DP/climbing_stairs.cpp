class Solution {
public:
    int climbStairs(int n) {
      
      //tabulation
        vector<int> dp(n+1);
            dp[0] = 1;
            dp[1] = 1;
            
            for(int i = 2; i <= n;i++){
                    dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
          //space optmization  
                int prev2 = 1;
                int prev = 1;
            
            for(int i = 2; i <= n;i++){
                    int cur = prev2 + prev;
                    prev2 = prev;
                    prev = cur;
            }
            return prev;
    }
};
