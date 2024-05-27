from ast import List
from itertools import combinations, permutations
import itertools

def tuple_to_string(t):
    string = ""
    for elem in t:
        string += str(elem)
    return string

class Solution(object):
    def getPermutation(self, n, k):
        nums = [i + 1 for i in range(n)]
        permus = list(permutations(nums, r=None))
        return  tuple_to_string(permus[k - 1])