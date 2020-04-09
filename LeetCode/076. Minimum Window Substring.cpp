双指针

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>flag(256, 0);
        int min = INT_MAX;
        int begin = 0, end = 0, head = 0, cnt = t.size();//cnt统计t中剩余未找到的字母数，head记录首位置
        for (int i = 0; i < t.size(); i++)
            flag[t[i]]++;
        while (end < s.size())
        {
            if (flag[s[end]] > 0)//找到一个t中一个字母
                cnt--;
            flag[s[end]]--;
            end++;
            while (cnt == 0)
            {
                if (end - begin< min)
                {
                    min = end - begin;
                    head = begin;
                }
                if (flag[s[begin]] == 0)//begin为t中的字母,此时除t中字母外的其他字母数都是负的
                    cnt++;
                flag[s[begin]]++;
                begin++;
            }
        }
        return min == INT_MAX ? "" : s.substr(head, min);
    }
};
//2
class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        int min_length=s.length()+1;
        map<char,int>h;
        for(int i=0;i<t.length();i++)//记录t中字母的频次
            h[t[i]]++;
        int left=0,right=0,cnt=t.length();//cnt用来标记s是否包含了t
        while(right<s.length())//移动右指针
        {
            if(t.find(s[right])!=t.npos)//right在t中
            {
                if(h[s[right]]>0)
                    cnt--;
                h[s[right]]--;
            }
            while(cnt==0)//移动左指针
            {
                if((right-left+1)<min_length)
                {
                    result=s.substr(left,right-left+1);
                    min_length=right-left+1;
                }
                if(t.find(s[left])!=t.npos)
                {
                    if(h[s[left]]>=0)
                        cnt++;
                    h[s[left]]++;
                }
                left++;
            }
            right++;
        }
        return result;
    }
};
