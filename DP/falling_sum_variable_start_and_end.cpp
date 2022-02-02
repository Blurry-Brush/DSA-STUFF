int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(j < 0 || j >= matrix[0].size()){
        return -1e8;
    }
    if(i == 0){
        return matrix[0][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = matrix[i][j] + f(i-1,j,matrix,dp);
    int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);
    
    return dp[i][j] = max(up,max(ld,rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    
//     vector<vector<int>> dp(n,vector<int> (m,-1));
//     int ans = -1e8;
//     for(int j = 0; j < m;j++){
//         ans = max(ans,f(n-1,j,matrix,dp));
//     }
//     return ans;
    
    //tabulation
    int dp[n][m];
    for(int j = 0; j < m;j++){
        dp[0][j] = matrix[0][j];
    }
    
    for(int i = 1; i < n;i++){
        for(int j = 0; j < m;j++){
            
            int ld = -1e8,rd = -1e8;
            int up = matrix[i][j] + dp[i-1][j];
            if(j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];
    		if(j+1 < m) rd = matrix[i][j] + dp[i-1][j+1];
            
             dp[i][j] = max(up,max(ld,rd));
        }
    }
    
    int maxi = -1e8;
    for(int j = 0; j < m;j++){
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
    
    
    //space opmtimization
    
    vector<int> prev(m,0);
    for(int j = 0; j < m;j++){
        prev[j] = matrix[0][j];
    }
    
    for(int i = 1; i < n;i++){
        vector<int> cur(m,0);
        for(int j = 0; j < m;j++){
            
            int ld = -1e8,rd = -1e8;
            int up = matrix[i][j] + prev[j];
            if(j-1 >= 0) ld = matrix[i][j] + prev[j-1];
    		if(j+1 < m) rd = matrix[i][j] + prev[j+1];
            
             cur[j] = max(up,max(ld,rd));
        }
        prev = cur;
    }
    
    int maxi = -1e8;
    for(int j = 0; j < m;j++){
        maxi = max(maxi,prev[j]);
    }
    return maxi;
  
    
}
