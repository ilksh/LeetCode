#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        vector<int> ansVector;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                ansVector.push_back(nums[i]);
                cnt++;
            }
        }
        nums.clear();
        nums = ansVector;
        return cnt;        
    }
};