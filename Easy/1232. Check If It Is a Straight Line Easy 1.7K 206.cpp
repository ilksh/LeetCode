#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size(); // number of coordinate
        if (n == 2) return true; // if there is only two points

        int x_0 = coordinates[0][0];
        int x_1 = coordinates[1][0];
        int y_0 = coordinates[0][1];
        int y_1 = coordinates[1][1];
        int slope;

        if (y_1 - y_0 == 0)  slope = -1;         // if the delta y is zero, the slope is zero, let this case as -1
        else if (x_1 - x_0 == 0) slope = -2;    // if the delta x is zero, the angle of slope is 90, let this case as -2
        else slope = (y_1 - y_0) / (x_1 - x_0) ; // generally, calculate the slope
    
        for (int i = 2; i < n ; ++i) {
            int dy = (coordinates[i][1] - coordinates[i - 1][1]); // current delta y
            int dx = (coordinates[i][0] - coordinates[i - 1][0]); // current delta x
            int curSlope; // current slope 
            if (dy  == 0 ) curSlope = -1; // if the delta y is zero, the slope is zero, let this case as -1
            else if (dx == 0) curSlope = -2;  // if the delta x is zero, the angle of slope is 90, let this case as -2
            else curSlope = dy / dx; // generally, calculate the slope (delat x / delta y)

            // there are two different slopes = three coordinates cannot be connected with line
            if (slope != curSlope) return false;
        }

        return true;
    }
};