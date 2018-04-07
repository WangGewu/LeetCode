class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int sum = 0;
        for (int i = 0; i<matrix.size(); i++)
        {
            sum += matrix[i].size();
        }
        if (sum == 0)
            return res;
        int posiX = 0, posiY = 0;
        int top = 0, left = 0 - 1, right = matrix[0].size(), bottom = matrix.size();
        while (1)
        {
            for (; posiX < right; posiX++)//toRight
                res.push_back(matrix[posiY][posiX]);
            if (res.size() == sum)
                break;
            right--;
            posiX--;
            posiY++;
            for (; posiY < bottom; posiY++)//toBottom
                res.push_back(matrix[posiY][posiX]);
            if (res.size() == sum)
                break;
            bottom--;
            posiY--;
            posiX--;
            for (; posiX > left; posiX--)//toLeft
                res.push_back(matrix[posiY][posiX]);
            if (res.size() == sum)
                break;
            left++;
            posiX++;
            posiY--;
            for (; posiY > top; posiY--)//toTop
                res.push_back(matrix[posiY][posiX]);
            if (res.size() == sum)
                break;
            top++;
            posiY++;
            posiX++;
        }
        return res;
    }
};