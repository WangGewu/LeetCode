class Solution {
public:
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
