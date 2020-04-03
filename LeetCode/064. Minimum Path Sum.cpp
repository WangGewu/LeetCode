class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>minDist(m, vector<int>(n, 0));
        for (int i = 0; i<m; i++)
            for (int j = 0; j < n; j++)
            {
                minDist[i][j] = grid[i][j];
                if (i != 0 && j != 0)
                    minDist[i][j] += minDist[i - 1][j] < minDist[i][j - 1] ? minDist[i - 1][j] : minDist[i][j - 1];

                else if (i == 0 && j != 0)
                    minDist[i][j] += minDist[i][j - 1];
                else if (i != 0 && j == 0)
                    minDist[i][j] += minDist[i - 1][j];
            }
        return minDist[m - 1][n - 1];
    }
};
//2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>result(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                    result[i][j]=grid[i][j];
                else if(i==0)
                    result[i][j]=grid[i][j]+result[i][j-1];
                else if(j==0)
                    result[i][j]=grid[i][j]+result[i-1][j];
                else
                    result[i][j]=grid[i][j]+min(result[i-1][j],result[i][j-1]);
            }
        return result[n-1][m-1];
    }
};
