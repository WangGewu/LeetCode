class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int p = a.length() - 1;
        int q = b.length() - 1;
        int add1, add2;
        int flag = 0;//标志进位
        while (p >= 0 && q >= 0)
        {
            add1 = a[p] - '0';
            add2 = b[q] - '0';
            res += (add1 + add2 + flag) % 2 + '0';
            flag = (add1 + add2 + flag) / 2;
            p--; q--;
        }
        while (p >= 0)
        {
            add1 = a[p] - '0';
            res += (add1 + flag) % 2 + '0';
            flag = (add1 + flag) / 2;
            p--;
        }
        while (q >= 0)
        {
            add2 = b[q] - '0';
            res += (add2 + flag) % 2 + '0';
            flag = (add2 + flag) / 2;
            q--;
        }
        if (flag)
            res += flag + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
//2
class Solution {
public:
    string addBinary(string a, string b) {
        int p_a=a.length()-1,p_b=b.length()-1;
        string result;
        int flag=0;
        while(p_a>=0&&p_b>=0)
        {
            int num_a=a[p_a]-'0',num_b=b[p_b]-'0';
            result+=(num_a+num_b+flag)%2+'0';
            flag=(num_a+num_b+flag)/2;
            p_a--;p_b--;
        }
        while(p_a>=0)
        {
            int num_a=a[p_a]-'0';
            result+=((num_a+flag)%2)+'0';
            flag=(num_a+flag)/2;
            p_a--;
        }
        while(p_b>=0)
        {
            int num_b=b[p_b]-'0';
            result+=((num_b+flag)%2)+'0';
            flag=(num_b+flag)/2;
            p_b--;
        }
        if(flag)
            result+='1';
        reverse(result.begin(), result.end());
        return result;
    }
};
