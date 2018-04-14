class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n, vector<int>(n, 0));
        int cnt = 1;
        int posiX = 0, posiY = 0;
        int top = 0, left = 0 - 1, right = n, bottom = n;
        while (1)
        {
            for (; posiX < right; posiX++)//toleft
                res[posiY][posiX] = cnt++;
            if (cnt - 1 == n*n)
                break;
            right--;
            posiX--;
            posiY++;
            for (; posiY < bottom; posiY++)//tobottom
                res[posiY][posiX] = cnt++;
            if (cnt - 1 == n*n)
                break;
            bottom--;
            posiY--;
            posiX--;
            for (; posiX > left; posiX--)//toleft
                res[posiY][posiX] = cnt++;
            if (cnt - 1 == n*n)
                break;
            left++;
            posiX++;
            posiY--;
            for (; posiY > top; posiY--)//totop
                res[posiY][posiX] = cnt++;
            if (cnt - 1 == n*n)
                break;
            top++;
            posiY++;
            posiX++;
        }
        return res;
    }
};