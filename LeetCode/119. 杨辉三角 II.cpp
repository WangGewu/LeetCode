
//ps：倒着来最简单
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result(rowIndex+1,1);
        if(rowIndex+1<=2)return result;
        for(int i=1;i<=rowIndex+1;i++)
        {
            int temp1=result[0];
            for(int j=1;j<i-1;j++)
            {
                int temp2=result[j];
                result[j]=result[j]+temp1;  
                temp1=temp2;
            }          
        }
        return result;
    }
};
