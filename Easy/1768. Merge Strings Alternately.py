class Solution(object):
    def mergeAlternately(self, word1, word2):
        len1 = len(word1)
        len2 = len(word2)
        is_word1_longer = True if (len1 >= len2) else False
        ans = ""
        if is_word1_longer:
            for i in range(len2): ans = ans + (word1[i] + word2[i])
            for j in range(len2, len1): ans = ans + word1[j]
        else:
            for i in range(len1): ans = ans + (word1[i] + word2[i])
            for j in range(len1, len2): ans = ans + word2[j]
        return ans