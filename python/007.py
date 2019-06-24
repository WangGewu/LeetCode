class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = str(x)
        x=x[::-1]
        if x[-1]=='-':
            x='-'+x
            res=int(x[0:-1])
        else:
            res=int(x)
        if -2**31<res<2**31-1:
            return res
        return 0