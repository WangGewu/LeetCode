class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string result;
        int cnt;
        for(int i=0;i<numRows;i++)
        {
            cnt=0;
            //处理中间行
            for(int j=i;j<s.length();)
            {
                result+=s[j];
                if(i==0||i==numRows-1)
                    j+=2*numRows-2;
                else
                {
                    if(cnt%2==0)
                        j=j+2*numRows-2-2*i;
                    else
                        j+=2*i;
                    cnt++;
                }
            }
        }
        return result;
    }
};
