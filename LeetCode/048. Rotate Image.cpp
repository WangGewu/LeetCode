class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //��ת��ת��
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = i + 1; j < matrix[0].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
    }
};