#include<bits/stdc++.h>

using namespace std;

class Solution {
private: 
    queue<int> circle;
    queue<int> answer;
public:
    int findTheWinner(int n, int k) {
        for(int i=1; i<=n; i++) circle.push(i);
        while(answer.size() < n)
        {
            for(int i=0 ; i < k-1; ++i)
            {
                int cur = circle.front(); circle.pop();
                circle.push(cur);
            }
            int dead = circle.front(); circle.pop();
            answer.push(dead);
        }
        int ans = 0;
        while(answer.size() >0)
        {
            int temp = answer.front(); answer.pop();
            if(answer.size() == 0) ans = temp;
        }
        return ans;
    }
};
