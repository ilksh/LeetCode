from typing import List

class Solution:
    """
    Optimization of previous approach
    Left Product =  [df   , 0    , 0 ~ 1, 0 ~ 2]
    Right Product = [3 ~ 1, 3 ~ 2, 3    , df   ]
    ans[0] = left[0] * right[0] but do not make list
    Use reverse iteration
    """
    
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n
        
        # Calculate left products
        left_product = 1
        for i in range(n):
            answer[i] = left_product
            left_product *= nums[i]
        
        # Calculate right products and multiply with left products
        right_product = 1
        for i in range(n - 1, -1, -1):
            answer[i] *= right_product
            right_product *= nums[i]

        return answer

    """
    This function (approach) exceeds the memory limitation
    Modifying Prefix sum Algorithm requires more memory if it is multiplication
    Need optimization of current algorithm
    """
    def memory_exceed_function(self, nums: List[int]) -> List[int]:
        n = len(nums) 
        
        # let p[a][b] be the accumulation of product from index a to b 
        p = [[0 for _ in range(n)] for _ in range(n)] 
        
        for i in range(n):
            p[i][i] = nums[i]
            for j in range(i + 1, n):
                rst = 1
                for idx in range(i, j + 1): 
                    rst *= nums[idx]
                p[i][j] = rst

        ans = []
        for i in range(n):
            first = 1 if i - 1 < 0 else p[0][i - 1]
            second = 1 if i + 1 >= n else p[i + 1][n - 1]
            ans.append(first * second)

        return ans
