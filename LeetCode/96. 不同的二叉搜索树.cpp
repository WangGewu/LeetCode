//dp
class Solution {
public:
    int numTrees(int n) {
        vector<int>result(n+1,0);
        if(n==0||n==1)return 1;
        result[0]=1;result[1]=1;
        for(int i=2;i<=n;i++)
            for(int j=0;j<=i-1;j++)
                result[i]+=result[j]*result[i-1-j];
        return result[n];
    }
};
//递归超时
class Solution {
public:
    int numTrees(int n) {
        if(n==0||n==1)
            return 1;
        int result=0;
        for(int i=0;i<=n-1;i++)
            result+=numTrees(i)*numTrees(n-i-1);
        return result;
    }
};