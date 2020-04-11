class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>flag(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i<board.size(); i++)
            for (int j = 0; j<board[0].size(); j++)
            {
                if (solve(board, flag, word, i, j, 0))
                    return true;
            }
        return false;
    }
    bool solve(vector<vector<char>>& board, vector<vector<int>>& flag, string word, int i, int j, int index)
    {
        if (index == word.length() - 1)
            return board[i][j] == word[index];
        if (board[i][j] != word[index])
            return false;
        flag[i][j] = 1;
        if (i>0 && flag[i - 1][j] == 0 && solve(board, flag, word, i - 1, j, index + 1))//ио
            return true;
        if (i<board.size() - 1 && flag[i + 1][j] == 0 && solve(board, flag, word, i + 1, j, index + 1))//об
            return true;
        if (j>0 && flag[i][j - 1] == 0 && solve(board, flag, word, i, j - 1, index + 1))//вС
            return true;
        if (j<board[0].size() - 1 && flag[i][j + 1] == 0 && solve(board, flag, word, i, j + 1, index + 1))//ср
            return true;
        flag[i][j] = 0;
        return false;
    }
};