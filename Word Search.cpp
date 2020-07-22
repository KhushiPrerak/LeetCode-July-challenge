class Solution {
public:
    
    int a[4][2] ={{0,1},{0,-1},{-1,0},{1,0}};
    
    bool helper(vector<vector<char>> board, int i, int j, string word, vector<vector<bool>>&vis){
        if(word.length()==0) return true;
        
        for(int k=0;k<4;k++){
            int ni = i+a[k][0];
            int nj = j+a[k][1];
            
            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size() && !vis[ni][nj]) {
                if(board[ni][nj] == word[0]){
                    vis[ni][nj] = true;
                    if(helper(board, ni,nj, word.substr(1),vis))
                        return true;
                    vis[ni][nj]=false;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && !vis[i][j]) {
                    vis[i][j] = true;
                    if(helper(board,i,j,word.substr(1),vis)) 
                        return true;
                    vis[i][j] = false;
                }
            }
        }
        
        return false;
        
    }
};
