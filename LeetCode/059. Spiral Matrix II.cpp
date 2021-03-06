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

//2
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>result(n,vector<int>(n,0));
        int iter=(n+1)/2;
        int num=1;
        for(int i=0;i<iter;i++) //轮次
        {
            int start_x=i,start_y=i;
            int left=i,top=i,right=n-1-i,bottem=n-1-i;
            int current_x=start_x,current_y=start_y;
            while(1)
            {
                result[current_y][current_x]=num++;
                if(num>n*n||(current_x==start_x&&current_y==start_y+1)) //终止条件
                    break;
                if(current_y==top&&current_x!=right)
                    current_x++;
                else if(current_y==bottem&&current_x!=left)
                    current_x--;
                else if(current_x==right&&current_y!=bottem)
                    current_y++;
                else if(current_x==left&&current_y!=top)
                    current_y--;
            }
        }
        return result;
    }
};
