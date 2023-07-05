#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size(); // number of element

        if (n == 1) return stones[0];

        priority_queue<int> pq; 
        for (auto e : stones) pq.push(e);
        
        while (pq.size() >= 2) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            cout << first << "," << second << "\n";
            int diff = second -first;
            if (diff != 0) pq.push(diff);
        }
        int rst = pq.empty() ? 0 : pq.top();
        return rst;

    }
};