class Solution {
public:
    string intToRoman(int num) {
        string Roman[4][10]{
            { "","I","II","III","IV","V","VI","VII","VIII","IX", },
            { "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" },
            { "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" },
            { "","M","MM","MMM" }
        };
        string value;
        value.append(Roman[3][num / 1000 % 10]);
        value.append(Roman[2][num / 100 % 10]);
        value.append(Roman[1][num / 10 % 10]);
        value.append(Roman[0][num % 10]);
        return value;
    }
};
