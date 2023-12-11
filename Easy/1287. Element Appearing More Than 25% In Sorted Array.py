from ast import List

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        freq = {}
        n = len(arr)
        for elem in arr:
            if elem in arr:
                if elem in freq.keys():
                    freq[elem] = freq[elem] + 1

                else:
                    freq[elem] = 1
                
                if freq[elem] > 0.25 * n: return elem