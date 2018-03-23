class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length();
        if (len>haystack.length())
            return -1;
        for (int i = 0; i<haystack.length() - len + 1; i++)
            if (haystack.substr(i, len) == needle)
                return i;
        return -1;
    }
};