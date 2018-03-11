class Solution {
public:
	string longestPalindrome(string s) {
		string result;
		int cnt = 0, max = 0;
		int i, j;
		for (i = 0; i < s.size(); i++)
		{
			//第一种情况（bb）
			cnt = 0;
			for (j = 0; (i + j) < s.size() && (i - j) >= 0; j++)
			{
				if (s[i - j] == s[i + 1 + j])
					cnt += 2;
				else
					break;
			}
			if (cnt > max)
			{
				max = cnt;
				result.assign(s.begin() + i - j + 1, s.begin() + i + j + 1);
			}
			//第二种情况（bab）
			cnt = 1;
			for (j = 1; (i + j) < s.size() && (i - j) >= 0; j++)
			{
				if (s[i - j] == s[i + j])
					cnt += 2;
				else
					break;
			}
			if (cnt > max)
			{
				max = cnt;
				result.assign(s.begin() + i - j + 1, s.begin() + i + j);
			}
		}
		return result;
	}
};