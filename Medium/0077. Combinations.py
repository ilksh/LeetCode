from ast import List
from itertools import combinations
import itertools

class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = [i + 1 for i in range(n)]
        combis = list(combinations(nums, k))
        ans = []
        for combi in combis:
            ans.append(list(combi))
        return ans
        