/*
 ���統ǰ������n������֪��ÿ����ͬ����ʼԪ�ض�Ӧ(n-1)!��permutation��
 Ҳ����(n-1)!��permutation��ỻһ����ʼԪ�ء���ˣ�ֻҪ��ǰ��k����(n-1)!ȡ�࣬
 �õ������־��ǵ�ǰʣ�������index��
 ��˾Ϳ��Եõ���Ӧ��Ԫ�ء�
 ��˵���ֱ��������û��Ԫ�ؽ�����
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        string res;
        vector<char>dight;
        vector<int>sum(n + 1, 1);//����׳�
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