class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        result = 0
        for cs in s:
            result ^= ord(cs)
        for ct in t:
            result ^= ord(ct)
        return chr(result)
