class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int min = 0;//记录vector中值最小的元素，下一次递归从比min大的数开始
        vector<vector<int>> result;
        vector<int>element;
        solve(result, element, n, k, min);
        return result;
    }
    void solve(vector<vector<int>>&res, vector<int>&element, int n, int k, int &min)
    {
        if (element.size() == k)
        {
            res.push_back(element);
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i <= min)continue;
            element.push_back(i);
            min = i;
            solve(res, element, n, k, min);
            element.pop_back();
            min = element[element.size() - 1];
        }
    }
};

//2
//C(m,n)=C(m-1,n)+C(m-1,n-1)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>element;
        if(k==1)
            for(int i=1;i<=n;i++)
                result.push_back(vector<int>(1,i));
        else if(k==n)
        {
            vector<int>element;
            for(int i=1;i<=n;i++)
                element.push_back(i);
            result.push_back(element);
        }
        else
        {
            vector<vector<int>>result1=combine(n-1,k);
            vector<vector<int>>result2=combine(n-1,k-1);
            for(int i=0;i<result2.size();i++)
                result2[i].push_back(n);
            result.insert(result.end(),result1.begin(),result1.end());
            result.insert(result.end(),result2.begin(),result2.end());
        }
        return result;
    }
};
