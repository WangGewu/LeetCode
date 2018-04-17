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
    /*递归会超时
    void Go(int posi_X,int posi_Y,int m,int n,int &cntPath)
    {

    if(posi_X==m-1&&posi_Y==n-1)
    {
    cntPath++;
    return;
    }
    if(posi_X<m-1)
    Go(posi_X+1,posi_Y,m,n,cntPath);
    if(posi_Y<n-1)
    Go(posi_X,posi_Y+1,m,n,cntPath);
    }
    */
};