class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>res(m, vector<int>(n, 1));
        for (int i = 0; i<m; i++)
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    res[i][j] = 0;
                    continue;
                }
                if (i != 0 && j != 0)//中间
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
                else if (i == 0 && j != 0)//第一行
                    res[i][j] = res[i][j - 1];
                else if (i != 0 && j == 0)//第一列
                    res[i][j] = res[i - 1][j];
            }
        return res[m - 1][n - 1];
    }
};
//2
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<long>>result(n,vector<long>(m,0));//int会溢出
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {   
                if(i==0&&j==0)
                {
                    result[i][j]=(obstacleGrid[i][j]==1)?0:1;
                    continue;
                }   
                if(obstacleGrid[i][j]==1)//有障碍
                    result[i][j]=0;
                else if(i==0)//第一行
                    result[i][j]=result[i][j-1];
                else if(j==0)//第一列
                    result[i][j]=result[i-1][j];
                else //中间
                    result[i][j]=result[i-1][j]+result[i][j-1];
            }
        return result[n-1][m-1];
    }
};
