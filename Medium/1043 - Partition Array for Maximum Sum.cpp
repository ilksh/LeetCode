#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    int cache[(int)5e2 + 5]; 
public:
    int solve(vector<int>& arr, int cur, int n, int k) {
        if(cur >= n) return 0; 

        int& ret = cache[cur];  
        if(ret != -1) return ret; 

        ret = arr[cur] + solve(arr, cur+1, n, k);
        int mx = arr[cur];

        for(int i=1; i<k; ++i) {
            if(cur+i == n) break;
        
            mx = max(mx, arr[cur+i]);
            ret = max(ret, mx*(i+1) + solve(arr, cur+i+1, n, k));
        }

    return ret;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(cache, -1, sizeof(cache));
        return solve(arr, 0, arr.size(), k);
    }
};