class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>a(9, vector<int>(9, 0));//行
        vector<vector<int>>b(9, vector<int>(9, 0));//列
        vector<vector<int>>c(9, vector<int>(9, 0));//九宫格
        for (int i = 0; i<9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
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