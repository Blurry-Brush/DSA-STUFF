class Solution {
public:
        
      //hashing the occupied positions and trick.
        
        void help(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &lowerdiagonal,vector<int> &upperdiagonal, int n){
                if(col == n){
                        ans.push_back(board);
                        return;
                }        
                
                for(int row = 0; row < n; row++){
                        if(leftrow[row] == 0 and lowerdiagonal[row+col] == 0 and upperdiagonal[n-1 + (col - row)] == 0){
                                leftrow[row] = 1;
                                lowerdiagonal[row+col] = 1;
                                upperdiagonal[n-1 + (col - row)] = 1;
                                board[row][col] = 'Q';
                                
                                help(col+1,board,ans,leftrow,lowerdiagonal,upperdiagonal,n);
                                
                                //backtracking step.
                                 leftrow[row] = 0;
                                lowerdiagonal[row+col] = 0;
                                upperdiagonal[n-1 + (col - row)] = 0;
                                board[row][col] = '.';
                        }
                }
                
        }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
            for(int i =0; i < n; i++){
                    board[i] = s;
            }
            
            vector<int> leftrow(n,0);
            vector<int> lowerdiagonal(2*n - 1, 0);
            vector<int> upperdiagonal(2*n - 1, 0);
            
            
            help(0,board,ans,leftrow,lowerdiagonal,upperdiagonal,n);
            return ans;

    }
};
