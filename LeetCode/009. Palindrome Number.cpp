class Solution {
public:
    bool isPalindrome(int x) {
        string number=to_string(x);
        string number2=number;
        reverse(number.begin(),number.end());
        if(number==number2)
            return true;
        else
            return false;
    }
};
