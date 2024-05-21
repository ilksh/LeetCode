from ast import List
from itertools import combinations
import itertools

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        ans.append([])
        for elem in nums:
            ans.append([elem])
        for length in range(2, len(nums) + 1):
            combis = list(combinations(nums, length))
            for combi in combis:
                ans.append(list(combi))
        print(ans)
        return ans