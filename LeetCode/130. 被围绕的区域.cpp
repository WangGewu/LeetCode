class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0||board[0].size()==0)return;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)//判断边界
                {
                    if(board[i][j]=='O')
                        dfs(i,j,board);
                }
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='#')
                    board[i][j]='O';
            }
    }
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]=='#'||board[i][j]=='X')return;
        board[i][j]='#';
        dfs(i+1,j,board);
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
    }
};