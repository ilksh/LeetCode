#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for (int i = 0; i < n; ++i) {
            string cur = "";
            //  if i is divisible by 3 and 5
            if ((i + 1) % 15 == 0) cur = "FizzBuzz";
            // if i is divisible by 3
            else if ((i + 1) % 3 == 0) cur = "Fizz";
            //  if i is divisible by 5
            else if ((i + 1) % 5 == 0) cur = "Buzz";
            // if none of the above conditions are true.
            else cur = to_string(i + 1);
            
            ans.push_back(cur);
        }
        return ans;
    }
};