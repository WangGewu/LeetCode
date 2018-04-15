/*
 比如当前长度是n，我们知道每个相同的起始元素对应(n-1)!个permutation，
 也就是(n-1)!个permutation后会换一个起始元素。因此，只要当前的k进行(n-1)!取余，
 得到的数字就是当前剩余数组的index，
 如此就可以得到对应的元素。
 如此递推直到数组中没有元素结束。
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string res;
        vector<char>dight;
        vector<int>sum(n + 1, 1);//计算阶乘
        for (int i = 1; i <= n; i++)
        {
            dight.push_back(i + '0');
            sum[i] = sum[i - 1] * i;
        }
        int len = n;
        while (len)
        {
            int index = k / sum[len - 1];
            k = k%sum[len - 1];
            res = res + dight[index];
            dight.erase(dight.begin() + index);
            len--;
        }
        return res;
    }
};