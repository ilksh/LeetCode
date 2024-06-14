#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i; 
        int left = (i << 1) + 1; 
        int right = (i << 1) + 2; 

       
        if (left < n && arr[left] > arr[largest]) largest = left;

        if (right < n && arr[right] > arr[largest]) largest = right;

        // If largest is not root
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for (int i = (n >> 1) - 1; i >= 0; --i) heapify(nums, n, i);
        for (int i = n - 1; i >= 0; --i) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        
    }
};