#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // ** Approach  **
        // The goal is to divide the two arrays such that the left half has all smaller elements
        // and the right half has all larger elements, even if they are from different arrays.
        // For example, if we divide like this: 7, || 12, 14, 15 and 1, 2, 3, 4, || 9, 11,
        // we need to find the largest element on the left side and the smallest on the right side.
        
        // Setting up the sizes of the arrays and the total size
        int size1 = nums1.size();
        int size2 = nums2.size();
        int totalSize = size1 + size2;
        
        // Ensuring that the first array is the shorter one for simplicity
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        // The partition size is determined to equally divide the combined array
        int half = (totalSize + 1) / 2;
        
        // Handling cases where one of the arrays is empty
        if (size1 == 0) {
            return size2 % 2 == 0 ? (nums2[size2 / 2] + nums2[size2 / 2 - 1]) / 2.0 : nums2[size2 / 2];
        }
        
        if (size2 == 0) {
            return size1 % 2 == 0 ? (nums1[size1 / 2] + nums1[size1 / 2 - 1]) / 2.0 : nums1[size1 / 2];
        }
        
        // Binary search to find the correct partition
        int start = 0, end = size1, cut1, cut2;
        int leftMax1, rightMin1, leftMax2, rightMin2;
        
        while (start <= end) {   
            // Finding partition points in both arrays
            cut1 = (start + end) / 2;
            cut2 = half - cut1;
            
            // Identifying the boundary elements around the cut
            leftMax1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            leftMax2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            rightMin1 = cut1 == size1 ? INT_MAX : nums1[cut1];
            rightMin2 = cut2 == size2 ? INT_MAX : nums2[cut2];
            
            // Checking if we have found the correct partition
            if (leftMax1 <= rightMin2 && leftMax2 <= rightMin1) {
                // Computing the median based on the total size being odd or even
                if (totalSize % 2 == 0) {
                    return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;
                } else {
                    return max(leftMax1, leftMax2);
                }
            }
            // Adjusting the search range
            else if (leftMax1 > rightMin2) {
                end = cut1 - 1;
            }
            else {
                start = cut1 + 1;
            }
        }
             
        // If no partition is found, return 0 (this should not happen if inputs are valid)
        return 0.0;
    }
};
