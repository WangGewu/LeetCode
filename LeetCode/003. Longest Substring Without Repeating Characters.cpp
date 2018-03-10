class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int frontmax=1;
        int front=0;
        int hash[265];
        for(int i=0;i<256;i++)
            hash[i]=0;
        for(int i=0;i<s.size();i++)
        {
            frontmax--;
            if(i!=0)
                hash[s[i-1]]=0;
            for(int j=front;j<s.size();j++)
            {
                if(hash[s[j]]==0)
                {
                    frontmax++;
                    if(frontmax>max)
                        max=frontmax;
                    hash[s[j]]=1;
                }  
                else
                {
                    front=j;
                    break;
                }
            }
        }
        return max;
    }
};
