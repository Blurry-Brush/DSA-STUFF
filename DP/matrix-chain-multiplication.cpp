int f(int i,int j,vector<int>& arr, vector<vector<int>> &dp){
	if(i == j) return 0;
    
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = 1e8;
    for(int k = i ; k <= j-1;k++){
		int ans = arr[i-1] * arr[k] * arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        mini = min(mini,ans);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
	int dp[N][N];
    
    for(int i = 1; i < N;i++){
        dp[i][i] = 0;
    }
    
    for(int i = N-1; i >= 1;i--){
		for(int j = i+1; j < N;j++){
            //i+1 for j always greater than or equal to i
			 int mini = 1e9;
            for(int k = i ; k <= j-1;k++){
                int ans = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini,ans);
            }
           	dp[i][j] = mini;
        }
    }
    // Write your code here.
    return dp[1][N-1];
}
