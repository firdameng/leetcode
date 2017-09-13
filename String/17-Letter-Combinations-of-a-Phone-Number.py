
#
# 17. Letter Combinations of a Phone Number
#
#


# other reduce(lambda x,y:x+y,l) ,x是累积变量，y是来自迭代器中的更新变量
# 比如(abc,def,tuv)acc : [a,b,c] -> [ad,ae,af,bd,be,bf,.....]->[adt,adu...]
class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        if '' == digits: return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, ['']) # acc初始值
        
# me 递归的方法，其实也就是reduce的番外篇
class Solution(object):

    def cycle(self,  i, digits):
        global result
        global str
        i += 1
        if i > len(digits) - 1:
            result.append(str)
            return
        for c in letter_table[int(digits[i]) - 2]:
            str += c
            self.cycle(i,digits)
            str = str[:i]
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        global letter_table 
        letter_table = [
                "abc","def","ghi",
                "jkl","mno","pqrs",
                "tuv","wxyz"
                ]
        global result 
        result = []

        global str 
        str = ""
        if len(digits) == 0:
            return []
        self.cycle(-1,digits)
        return result
                