
# other code
class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 子串定由01,10,1100,0011，不会出现00110这种，
        #所以只会有连续的0或1左右组合而成
        # 1.先拆分原串连续00,111
        # 2.按照原串中的顺序,交叉比较子串长，最小子串长即为改组有效子串数
        # 例如：'0001111' min(3,4) = 3 ,(01,0011,000111)
        s = map(len, s.replace('01', '0 1').replace('10', '1 0').split()) 
        return sum(min(a, b) for a, b in zip(s, s[1:]))

'''
c++版本 和python版相同思想
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> rec;
        int count = 1;
        for(int i=1, n=s.size(); i<=n; ++i){
            if(s[i] == s[i-1]){
                ++count;
            }else{
                rec.push_back(count);
                count = 1;
            }
        }
        int res = 0;
        for(int i=1, n=rec.size(); i<n; ++i){
            res += min(rec[i-1], rec[i]);
        }
        return res;
    }
};
'''