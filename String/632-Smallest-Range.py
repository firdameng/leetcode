# Heap elements can be tuples. 
# This is useful for assigning comparison values (such as task priorities) 
# alongside the main record being tracked
# 使用数据结构（小顶堆）来记录有序元素序列
class Solution(object):
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        A = nums
        pq = [(row[0], i, 0) for i, row in enumerate(A)]    # 含puple元素的列表
        heapq.heapify(pq)                                   # 将此列表转换为一个堆

        ans = -1e9, 1e9
        right = max(row[0] for row in A)
        while pq:
            left, i, j = heapq.heappop(pq)              # 弹出一个i行元素，
            if right - left < ans[1] - ans[0]:
                ans = left, right
            if j + 1 == len(A[i]):                      # 如果弹出后，已到该行末尾，表示寻找最小范围结束
                return ans
            v = A[i][j+1]
            right = max(right, v)                       # 记录堆中最大值
            heapq.heappush(pq, (v, i, j+1))             # 进去一个i行元素，保证了小顶堆包含各行的一个元素
        