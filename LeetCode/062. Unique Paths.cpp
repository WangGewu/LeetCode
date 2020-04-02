/*动态规划*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>res(m, vector<int>(n, 1));
        //到达第一行、第一列的点的路径数为1
        for (int i = 1; i<m; i++)
            for (int j = 1; j<n; j++)
                res[i][j] = res[i - 1][j] + res[i][j - 1];
        return res[m - 1][n - 1];
    }
 //2递归
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>result(n,vector<int>(m,0));   
        int count=solve(result,0,0,m,n);
        return count;
    }
    int solve(vector<vector<int>>&result, int x, int y, int m, int n)
    {
        if (x == m - 1 && y == n - 1)
            result[y][x] = 1;
        else if (x == m - 1)
            result[y][x] = (result[y+1][x]!=0)?result[y+1][x]:solve(result, x, y+1, m, n);
        else if (y == n - 1)
            result[y][x] = (result[y][x+1]!=0)?result[y][x+1]:solve(result, x+1, y, m, n);
        else
            result[y][x] = ((result[y+1][x]!=0)?result[y+1][x]:solve(result, x, y+1, m, n)) + ((result[y][x+1]!=0)?result[y][x+1]:solve(result, x+1, y, m, n));
        return result[y][x];
    }
};
