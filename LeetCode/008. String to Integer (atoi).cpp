class Solution {
public:
    int myAtoi(string str) {
        string result_str;
        int flag=1;
        int i,j;
        long x=0;
        for(i=0;i<str.length();i++)
        {
            if(!isspace(str[i]))
            {
                if(str[i]=='+')
                   flag=1;
                else if(str[i]=='-')
                   flag=-1;
                else if(isdigit(str[i]))
                    result_str+=str[i];
                else
                    return 0;
                break;
            }
        }
        for (j=i+1;j<str.length();j++)
        {
            if(isdigit(str[j]))
            {
                result_str+=str[j];
            }
            else
               break;
        }
        for (i=0;i<result_str.length();i++)
        {
            x = x * 10 + result_str[i] - '0';
            if (x >= 2147483648) {
				if (flag == 1)return INT_MAX;
				else return INT_MIN;
			}
        }
        if(flag==-1)
            x=-x;
        return x;
    }
};
