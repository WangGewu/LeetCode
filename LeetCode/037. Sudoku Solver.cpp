class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i<9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        board[i][j] = k;
                        if (isValidSudoku(board) && solve(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;//回溯
                }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>a(9, vector<int>(9, 0));//行
        vector<vector<int>>b(9, vector<int>(9, 0));//列
        vector<vector<int>>c(9, vector<int>(9, 0));//九宫格
        for (int i = 0; i<9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;//计算当前i,j处于哪一个九宫格
                    if (a[i][num] || b[j][num] || c[k][num])
                        return false;
                    a[i][num] = 1; b[j][num] = 1; c[k][num] = 1;
                }
            }
        return true;
    }
};


//2刷（超时）
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int flag=0;
        solve(board,0,flag);
    }
    void solve(vector<vector<char>>& board,int position,int& flag)
    {
        if(position==81)
        {
            flag=1;
            return;
        }
        if(board[position/9][position%9]!='.')
            solve(board,position+1,flag);
        else
        {
            for(int i=0;i<9;i++)
            {
                char value='0'+i+1;
                board[position/9][position%9]=value;
                if(isValidSudoku(board))
                {
                    solve(board,position+1,flag);
                    if(flag==1)
                        return;
                }
                board[position/9][position%9]='.';
            }
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>row(9,vector<int>(9,0));
        vector<vector<int>>column(9,vector<int>(9,0));
        vector<vector<int>>box(9,vector<int>(9,0));
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'0'-1;
                    //第几个九宫格
                    int k=i/3+3*(j/3);
                    if(row[i][num]||column[j][num]||box[k][num])
                        return false;
                    row[i][num]=column[j][num]=box[k][num]=1;
                }
            }
        return true;
    }
};
