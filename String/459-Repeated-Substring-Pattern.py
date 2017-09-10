
#
#
# 459. Repeated Substring Pattern
#
#


class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # 两种解法都是从存在构造子串入手，即合题意的情况，进而得出该种输入串应满足的特征
        
        # 解法1：
        # Basic idea:
        # First char of input string is first char of repeated substring
        # Last char of input string is last char of repeated substring
        # Let S1 = S + S (where S in input string)
        # Remove 1 and last char of S1. Let this be S2
        # If S exists in S2 then return true else false
        # Let i be index in S2 where S starts then repeated substring length i + 1 and repeated substring S[0: i+1]
        return s in (2 * s)[1:-1]    # 叠加后，去首尾，若仍存在输入串，则满足存在构造子串
        
        # 解法2
        # The length of the repeating substring must be a divisor of the length of the input string
        # Search for all possible divisor of str.length, starting for length/2
        # If i is a divisor of length, repeat the substring from 0 to i the number of times i is contained in s.length
        # If the repeated substring is equals to the input str return true
        length = len(s)
        for i in range(length/2,0,-1):  # 构造子串的个数必为输入串除数，从len/2递减试探s[:i]*(len/i)是否等于s
            if length % i == 0 and s[:i] * (length / i) == s:
                return True
        return False