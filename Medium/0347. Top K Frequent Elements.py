from ast import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic  = {} # num, freq

        for num in nums:
            if num not in dic.keys(): # if the elem is not in key
                dic[num] = 1    # create a key with a value of 1
            else: #  num is already exist
                dic[num] += 1
        
        # sort the dictionary by value in descending order
        sorted_list = sorted(dic.items(), key = lambda x : -x[1])
        ans = []
        idx = 0
        while idx < k : # select most kth elements
            ans.append(sorted_list[idx][0])
            idx += 1
           
        # return the answer
        return ans