#include<bits/stdc++.h>

using namespace std;


/*
 * nums = [2, 3, -2, 4]
 * Initialization: maxProduct = 2, minProduct = 2, result = 2
 * i = 1 (nums[1] = 3):
 *      maxProduct = max(3, 2*3) = 6
 *      minProduct = min(3, 2*3) = 3
 *      result = max(2, 6) = 6
 * 
 * i = 2 (nums[2] = -2):
 *      Swap maxProduct and minProduct because nums[2] is negative
 *      maxProduct = max(-2, 3*(-2)) = -2
 *      minProduct = min(-2, 6*(-2)) = -12
 *      result = max(6, -2) = 6
 * 
 * i = 3 (nums[3] = 4):
 *      maxProduct = max(4, -2*4) = 4  
 *      minProduct = min(4, -12*4) = -48
 *      result = max(6, 4) = 6
 */

int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxProduct = nums[0];
    int minProduct = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // If the current element is negative, swap max and min
        if (nums[i] < 0) {
            swap(maxProduct, minProduct);
        }

        // Memoization step: update the maxProduct and minProduct
        maxProduct = max(nums[i], maxProduct * nums[i]);
        minProduct = min(nums[i], minProduct * nums[i]);

        // Update the result with the current maximum product
        result = max(result, maxProduct);
    }

    return result;
}