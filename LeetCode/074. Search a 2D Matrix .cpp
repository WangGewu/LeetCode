class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag_row = false;
        int flag_col = false;
        for (int i = 0; i<matrix[0].size(); i++)//��һ��
            if (matrix[0][i] == 0)
            {
                flag_row = true;
                break;
            }
        for (int i = 0; i<matrix.size(); i++)//��һ��
            if (matrix[i][0] == 0)
            {
                flag_col = true;
                break;
            }
        for (int i = 1; i<matrix.size(); i++)
            for (int j = 1; j<matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for (int i = 1; i<matrix[0].size(); i++) //����
        {
            if (matrix[0][i] == 0)
                for (int j = 1; j<matrix.size(); j++)
                    matrix[j][i] = 0;
        }
        for (int i = 1; i<matrix.size(); i++)//����
        {
            if (matrix[i][0] == 0)
                for (int j = 1; j<matrix[0].size(); j++)
                    matrix[i][j] = 0;
        }
        if (flag_row)//��һ��
            for (int i = 0; i<matrix[0].size(); i++)
                matrix[0][i] = 0;
        if (flag_col)//��һ��
            for (int i = 0; i<matrix.size(); i++)
                matrix[i][0] = 0;
    }
};