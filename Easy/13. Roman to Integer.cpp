#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> valueMap = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result = 0;
        // Update the previous value for the edge cases
        // ex) I can be placed before V (5) and X (10) to make 4 and 9. 
        int prevValue = 0; 

        // iterate the input to calculate the value
        for (auto c : s) { 
            int curValue = valueMap[c]; // get the current value
            result += curValue;         // add the current value
            if (curValue > prevValue) { // handle the edge case
                result -= 2 * prevValue;
            }
            prevValue = curValue;       // update the previous value
        }
        return result;
    }
};
