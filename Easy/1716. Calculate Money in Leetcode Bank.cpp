class Solution {
public:
    int totalMoney(int n) {
      int total = 0, currentDaySavings = 1, week = 1;

      for (int day = 1; day <= n; day++) {
          total += currentDaySavings;

          // Increment the day's savings and reset it if a new week starts
          currentDaySavings++;
          if (day % 7 == 0) {
              week++;
              currentDaySavings = week;
          }
      }

      return total;
    }
};