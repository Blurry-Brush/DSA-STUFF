int lcs(string &str1, string &str2){
	//	Write your code here.
    //tabulation direct
    int n = str1.size();
    int m = str2.size();
    
    int dp[n+1][m+1];
    
    for(int i = 0; i < n;i++){
		dp[i][0] = 0;
    }
    for(int j = 0; j < m;j++){
        dp[0][j] = 0;
    }
    
    int ans = 0;
    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m;j++){
            if(str1[i-1] == str2[j-1]){
             	dp[i][j] = 1 + dp[i-1][j-1];   
            }   
            else{
				dp[i][j] = 0;
            }
            
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
