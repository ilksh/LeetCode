class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(" ")
        words = [word for word in words if len(word) != 0] # delete all white spaces
        words = words[::-1] # reverse the list 
        
        ans = ""
        for word in words:
            ans += word
            ans += " "
        
        return ans[:len(ans) - 1] 