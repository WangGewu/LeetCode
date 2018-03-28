class Solution {
public:
    string countAndSay(int n) {
        string front;
        string result("1");
        int i, j;
        for (i = 1; i < n; i++)
        {
            front = result;
            result = "";
            int num = 1;
            for (j = 1; j < front.length(); j++)
            {
                if (front[j] == front[j - 1])
                    num++;
                else
                {
                    result += num + '0';
                    result += front[j - 1];
                    num = 1;
                }
            }
            result += num + '0'; result += front[j - 1];
        }
        return result;
    }
};