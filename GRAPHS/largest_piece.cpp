// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int n;
    int m;
    //Function to find unit area of the largest region of 1s.
  
   
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
         n = grid.size();
         m = grid[0].size();
        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        int result = INT_MIN;
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m;j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    int count = 1;
                    dfs(grid,i,j,visited,count);
                    
                    result = max(result,count,m);
                }
            }
        }
    
    return result;
    }
    
     bool isSafe(vector<vector<int>>& grid,int row,int col,bool visited[][m]){
        return (row >= 0) && (row < n) && (col >= 0) && (col < m) and (grid[row][col] == 1 && !visited[row][col]);
    }
    
    void dfs(vector<vector<int>>& grid,int row,int col,bool visited[][m],int &count){
         static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
         static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            
         visited[row][col] = true;
         
         for(int i = 0; i < 8;i++){
             if(isSafe(grid,row+rowNbr[i],col+colNbr[i],visited[][col])){
                 count++;
                 
                 dfs(grid,row+rowNbr[i],col+colNbr[i],visited[][col],visited);
             }
         }
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
