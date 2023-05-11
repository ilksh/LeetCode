class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)  # Length of the haystack string
        m = len(needle)    # Length of the needle string
        
        # Iterate over all possible starting positions in the haystack
        for i in range(n - m + 1):
            # Check if the substring starting at position i matches the needle
            if haystack[i:i+m] == needle:
                return i  # Return the starting position if there's a match
        
        # If no match was found, return -1
        return -1
