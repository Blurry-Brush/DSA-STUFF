int f(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
    //out of bounds first
    if(j1 < 0 or j1 >= c or j2 < 0 or j2 >= c){
		return -1e8;
    }
    //destination
    if(i == r-1){
        if(j1 == j2){
            //same cell
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }
    
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }
    int maxi = 0;
    //dj1 is for alice and dj2 is for bob(simultaneosly)//
    //9 combos
    for(int dj1 = -1; dj1 <= 1;dj1++){
        for(int dj2 = -1; dj2 <= 1;dj2++){
            if(j1 == j2){
                maxi = max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,r,c,grid,dp));
            }
            else{
                maxi = max(maxi,grid[i][j1] + grid[i][j2] +f(i+1,j1+dj1,j2+dj2,r,c,grid,dp));
            }
        }
    } 
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    //int dp[r][c][c]
  
      vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,0)));
  
  
    vector<vector<int>> front(c,vector<int>(c,0));
    vector<vector<int>> cur(c,vector<int>(c,0));
    
    for(int j1 = 0; j1 < c;j1++){
        for(int j2 = 0;j2 < c;j2++){
            if(j1 == j2){
                front[j1][j2] = grid[r-1][j1];
            }
            else{
                front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }
    }
    
    for(int i = r-2;i >= 0;i--){
        for(int j1 = 0;j1 < c;j1++){
			for(int j2 = 0; j2 < c;j2++){
                //copy recurrence
                int maxi = -1e8;
                
                for(int dj1 = -1;dj1 <= 1;dj1++){
                    for(int dj2 = -1;dj2 <= 1;dj2++){
						int value = 0;
                        
                        if(j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        
                        if(j1+dj1 >= 0 and j1+dj1 < c and j2+dj2 >= 0 and j2+dj2 < c) 
                            value += front[j1+dj1][j2+dj2];
                        else
                            value += -1e8;
                        
                        maxi = max(maxi,value);
                    }
                }
               cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    return front[0][c-1];
    //return f(0,0,c-1,r,c,grid,dp);
}
