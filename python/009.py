class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x=str(x)
        if len(x)%2==0:
            if x[0:len(x)/2]!=(x[len(x)/2:])[::-1]:
                return False
        else:
            if x[0:len(x)/2]!=(x[len(x)/2+1:])[::-1]:
                return False
        return True