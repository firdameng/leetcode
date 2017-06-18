class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        length = len(nums)
        if length == 1:
            return str(nums[0])
        elif length == 2:
            return str(nums[0]) + '/' + str(nums[1])
        else:
            return str(nums[0]) + '/(' + '/'.join(map(lambda x : str(x), nums[1:])) + ')'