#include <vector> 
//shift the index 1 right.
int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i == 0 or j == 0) return 0;
            
        
        if(dp[i][j] != -1) return dp[i][j];
            
            if(s1[i-1] == s2[j-1]){
                return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
            }
            return dp[i][j] = max(f(i-1,j,s1,s2,dp) , f(i,j-1,s1,s2,dp));
    }
int lcs(string s, string t)
{
	//Write your code here
    //tabulation
     int n = s.size(), m = t.size();
     vector<vector<int>> dp(s.size() +1, vector<int>(t.size()+1,-1));
    
    for(int j = 0; j <= m;j++){
		dp[0][j] = 0;
    }
    for(int i = 0; i <= n;i++){
		dp[i][0] = 0;
    }
    
    for(int i = 1; i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i-1] == t[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
            
    return dp[n][m];
    //space-optimization
  int n = s.size(), m = t.size();
     vector<int> prev(m+1,0) , cur(m+1,0);
    
    for(int j = 0; j <= m;j++){
		prev[j] = 0;
    }

    
    for(int i = 1; i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i-1] == t[j-1]){
				cur[j] = 1 + prev[j-1];
            }
            else{
				cur[j] = max(prev[j],cur[j-1]);
            }
        }
        
        prev = cur;
    }
            
    return prev[m];
}
