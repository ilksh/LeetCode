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

class Solution {
public:
        // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        // If the input string is empty, return 0
        if (s.empty()) {
            return 0;
        }

        unordered_map<char, int> charFreq; // Create a hash map to store the frequency of characters
        int leftPtr = 0, rightPtr = 0, longestSubstringLength = 0; 

        // While the right pointer is less than the length of the string
        while (rightPtr < s.length()) {   
            // Increment the frequency of the character at the right pointer and move the pointer to the right
            charFreq[s[rightPtr]]++;

            // If the size of the hash map is equal to the window size
            if (charFreq.size() == rightPtr - leftPtr + 1) {  
                // Update the length of the longest substring
                longestSubstringLength = max(longestSubstringLength, rightPtr - leftPtr + 1);
            }
            // If the size of the hash map is less than the window size
            else if (charFreq.size() < rightPtr - leftPtr + 1) {  
                // Shrink the window from the left side by incrementing the left pointer
                while (charFreq.size() < rightPtr - leftPtr + 1) { 
                    // Decrement the frequency of the character at the left pointer and move the pointer to the right
                    charFreq[s[leftPtr]]--;   
                    // If the frequency becomes zero, remove the character from the hash map
                    if (charFreq[s[leftPtr]] == 0) {  
                        charFreq.erase(s[leftPtr]);
                    }
                    leftPtr++; // Move the left pointer to the right
                }
            }
            rightPtr++; // Move the right pointer to the right
        }
        return longestSubstringLength; // Return the length of the longest substring
    }

};