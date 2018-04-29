/*¶þ·Ö*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix[0].size();
        int n = matrix.size();
        int l = 0, r = m*n;//×ó±ÕÓÒ¿ª
        while (l < r)
        {
            if (target < matrix[l / m][l%m] || matrix[(r - 1) / m][(r - 1) % m] < target)
                return false;
            int mid = (l + r) / 2;
            if (target < matrix[mid / m][mid%m])
                r = mid;
            else if (matrix[mid / m][mid%m] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};