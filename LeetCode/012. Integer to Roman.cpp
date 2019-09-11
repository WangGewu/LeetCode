class Solution {
public:
    string intToRoman(int num) {
        int nums[13]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string c[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string s;
        for(int i=0;i<13;i++)
        {   
            int t=num/nums[i];
            for(int j=0;j<t;j++)
                s+=c[i];
            num=num%nums[i];
        }
        return s;
    }
};
