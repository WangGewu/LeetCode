#include<vector>
using namespace std;
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
                    return false;//����
                }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>a(9, vector<int>(9, 0));//��
        vector<vector<int>>b(9, vector<int>(9, 0));//��
        vector<vector<int>>c(9, vector<int>(9, 0));//�Ź���
        for (int i = 0; i<9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;//���㵱ǰi,j������һ���Ź���
                    if (a[i][num] || b[j][num] || c[k][num])
                        return false;
                    a[i][num] = 1; b[j][num] = 1; c[k][num] = 1;
                }
            }
        return true;
    }
};