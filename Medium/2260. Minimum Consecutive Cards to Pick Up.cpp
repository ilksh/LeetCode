#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int INF = 1e9;
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastIndex;
        int n = cards.size();
        int minDistance = INF;
        bool found = false;

        for (int i = 0; i < n; ++i) {
            if (lastIndex.find(cards[i]) != lastIndex.end()) {
                // Found a duplicate card, calculate distance
                minDistance = min(minDistance, i - lastIndex[cards[i]] + 1);
                found = true;
            }
            // Update the last seen index of the current card
            lastIndex[cards[i]] = i;
        }

        if (!found) return -1;
        return minDistance;
    }
};
