#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int sz = v.size();
        for(int i = sz - 1; i >= 0; --i){
            // current position is the rear
            if(i == sz-1) v[i]++;

            // current become 9 to 10 > increment the prev digit
            if(v[i] == 10){
                v[i] = 0;
                
                if(i != 0) v[i-1]++;
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};