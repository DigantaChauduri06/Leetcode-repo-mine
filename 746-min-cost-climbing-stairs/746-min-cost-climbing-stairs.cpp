class Solution {
    int n;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = size(cost);
        return fun(cost);
    }
private:
    int fun(vector<int> &cost) {
        if (n == 0) return 0;
        if (n <= 2) return n == 1 ? cost[0] : min(cost[0], cost[1]);
        int prev1 = cost[1], prev2 = cost[0];
        for (int j = 2;j < n;j++) {
            int cur = min(prev1, prev2) + cost[j];
            prev2 = prev1;
            prev1 = cur;
        }
        return min(prev1, prev2);
    }
};
/*
        if (n == 0) return 0;
        if (n <= 2) return n == 1 ? cost[0] : min(cost[0], cost[1]);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int j = 2;j < n;j++) {
            dp[j] = min(dp[j-1], dp[j-2]) + cost[j];
        } 
        return min(dp[n-2], dp[n-1]);


        if (i == n - 1 || i == n - 2) return cost[i];
        int one = fun(cost, i+1);
        int two = fun(cost, i+2);
        return min(one, two) + cost[i];

*/