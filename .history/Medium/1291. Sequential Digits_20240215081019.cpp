#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int MAX_N = 1e9 + 1;
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;
        
        for (int i = 1; i <= 9; ++i) q.push(i);
        
        
        while (!q.empty()) {
            int current = q.front(); q.pop();
            
            if (low < current && current <= high) result.push_back(current);
            
            if (current > high) continue;
            
            int lastDigit = current % 10;
            if (lastDigit < 9) {
                int next = current * 10 + (lastDigit + 1);
                q.push(next);
            }
        }
        
        return result;
    }
};