#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        // Hash map of chracter and its frequency
        unordered_map<char, int> charFreq; 
        int left = 0, right = 0, ans = 0; 

        // itrate to the end
        while (right < s.length()) {   
            auto curChar = s[right];
            charFreq[curChar]++;

            int curLength = right - left + 1; // current window size
            if (charFreq.size() == curLength) ans = max(ans, right - left + 1);
            
            else if (charFreq.size() < curLength) {  
                // Shrink the window from the left side by incrementing the left pointer
                while (true) { 
                    if (charFreq.size() >= curLength) break;
                    charFreq[s[left]]--;  // move the pointer to the right 
                   // remove the character from the hash map
                    if (charFreq[s[left]] == 0) charFreq.erase(s[left]);
                    left++; // Move the left pointer to the right
                }
            }
            right++; // Move the right pointer to the right
        }
        return ans; // Return the length of the longest substring
    }
};