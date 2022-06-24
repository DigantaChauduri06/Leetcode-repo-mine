class Solution {
    int n;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = size(cost);
        vector<int> dp1(n+1);
        return fun(cost, dp1);
    }
private:
    int fun(vector<int> &cost, vector<int> &dp) {
        if (n == 0) return 0;
        if (n <= 2) return n == 1 ? cost[0] : min(cost[0], cost[1]);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int j = 2;j < n;j++) {
            dp[j] = min(dp[j-1], dp[j-2]) + cost[j];
        } 
        return min(dp[n-2], dp[n-1]);
    }
};
/*
        if (i == n - 1 || i == n - 2) return cost[i];
        int one = fun(cost, i+1);
        int two = fun(cost, i+2);
        return min(one, two) + cost[i];

*/