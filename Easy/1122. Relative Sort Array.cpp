#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int swapIdx = 0;
        int n = arr1.size();
        int m = arr2.size();

        for (int i = 0; i< n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (arr1[i] == arr2[j]) swap(arr1[swapIdx++], arr1[i]);
            }

        }
    
        sort(arr1.begin()+swapIdx, arr1.end());
        return arr1;
    }
};