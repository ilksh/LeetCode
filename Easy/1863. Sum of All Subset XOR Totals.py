from ast import List
from itertools import combinations
import itertools

def sum_xor(combis):
    total_sum = 0
    for combi in combis:
        num_one = combi[0]
        calc_result = 0
        for i in range(1, len(combi)):
            num_two = combi[i]
            calc_result = num_one ^ num_two
            num_one = calc_result
        total_sum += calc_result
            
    return total_sum
    
class Solution(object):
    def subsetXORSum(self, nums):
        s = sum(nums)
        
        for length in range(2, len(nums) + 1):
            combis = list(combinations(nums, length))
            print(combis)
            calc = sum_xor(combis)
            print(calc)
            s += calc
        return s

