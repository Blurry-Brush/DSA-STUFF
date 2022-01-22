int large = (int)(1e9);
int f(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i == 0 and j == 0){
        return grid[i][j];
    }
    if(i < 0 or j < 0){
        return large;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);
    
    return dp[i][j] = min(left,up);
}


int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int row = grid.size();
    int col = grid[0].size();
    
    //vector<vector<int>> dp(row,vector<int>(col,-1));
    
    //return f(row-1,col-1,grid,dp);
    int dp[row][col];
    vector<int> prev(col,0);
    
    for(int i = 0; i < row;i++){
        vector<int> cur(col,0);
        
        for(int j = 0;j < col;j++){
            if(i == 0 and j == 0){
                cur[j] = grid[i][j];
            }
            else{
                int up = grid[i][j];
                int left = grid[i][j];
                
                if(i > 0) up += prev[j];
                else up += 1e9;
                
                if(j > 0) left += cur[j-1];
                else left += 1e9;
                
                cur[j] = min(up,left);
            }
        }
        prev = cur;
    }
    return prev[col-1];
}
