class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length()==0)
            return res;
        string s[9]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string element;
        generate(element,0,digits,s,res);
        return res;
    }
    void generate(string result,int index,string &digits,string s[9],vector<string>&res)
    {
        if(index==digits.length())
        {
            res.push_back(result);
            return;
        }
        int num=digits[index]-'0'-2;
        int len=s[num].length();
        for(int i=0;i<len;i++)
        {
            string temp=result+s[num][i];
            generate(temp,index+1,digits,s,res);
        }
    }
};
