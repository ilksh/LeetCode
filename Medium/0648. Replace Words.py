def isRoot(root, word):
    if len(root) > len(word):
        return False
    if root == word[:len(root)]:
        return True
    return False

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        # Sort the dictionary by the length of the elements in ascending order
        dictionary.sort(key=len)
        
        splited_sentence = sentence.split(" ")
        ans = []
        for word in splited_sentence:
            find = False
            for root in dictionary:
                if isRoot(root, word):
                    find = True
                    ans.append(root)
                    break
                    
            if not find:
                ans.append(word)
                
        output = ans[0]
        for word in ans[1:]:
            output += " "
            output += word
        return output
