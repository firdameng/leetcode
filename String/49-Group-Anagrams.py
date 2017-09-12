
#
#  49. Group Anagrams
#


# other 遍历列表中字符串，如果排序后的字符串在字典中，
# 则追加到key对应的value中，否则新增key
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        smap=dict()
    
        for s in strs:
            key=''.join(sorted(s))
            if smap.get(key)==None:
                smap[key]=[s]
            else:
                smap[key].append(s)

        return smap.values()
        
        
# me  总体思想是一致的，但有点脱裤子放屁
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sorted_strs = map(lambda str : ''.join(sorted(str)),strs)
        judge_dict = {}
        # 这里用该函数的做法其实是思路不够简化的原因，两步可做一步
        for i,str in enumerate(sorted_strs):    
            if str in judge_dict:
                judge_dict[str].append(strs[i])
            else:
                judge_dict[str] = [strs[i]]
        return map(sorted,judge_dict.values())

# me 精简版        
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = collections.defaultdict(list)
        map(lambda s : d[''.join(sorted(s))].append(s), strs)
        return map(sorted,d.values())
        