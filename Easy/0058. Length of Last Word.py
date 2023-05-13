class Solution(object):
    def lengthOfLastWord(self, s):
        new_s = s.split()
        print(new_s)
        ln = len(new_s)
        return len(new_s[ln - 1])