/*二分*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=m*n;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(matrix[mid/n][mid%n]<target)
                left=mid+1;
            else if(matrix[mid/n][mid%n]>target)
                right=mid;
            else  
                return true;
        }
        return false;
    }
};
//2 更快
public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix.length == 0)
            return false;
        int row = 0, col = matrix[0].length-1;
        while(row < matrix.length && col >= 0){
            if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
            else
                return true;
        }
        return false;
    };
