class Solution(object):
    def isPalindrome(self, x):
        if x < 0 :
            return False
        
        elif x == 0:
            return True
        
        x = str(x)
        temp = x[::-1]

        if x == temp:
            return True
        
        else:
            return False
        