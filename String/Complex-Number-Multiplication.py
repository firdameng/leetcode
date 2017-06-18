class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a_x,a_y = tuple(map(lambda x : int(x), a[:-1].split('+')))
        b_x,b_y = tuple(map(lambda x : int(x), b[:-1].split('+')))
        
        return '{0}+{1}i'.format(str(a_x*b_x - a_y*b_y),str(a_x*b_y + a_y*b_x))