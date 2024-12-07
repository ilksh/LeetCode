#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int endTime = 0;
        double sum = 0.0;

        for (auto customer: customers) {
            int startTime = customer[0];
            int waitingTime = customer[1];

            if (startTime < endTime) sum += (endTime - startTime);
            
            else endTime = startTime;
        
            endTime += waitingTime;
            sum += waitingTime;
        }

        int n = customers.size();
        double rst = sum / n;
        return rst;
    }
};