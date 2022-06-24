class Solution {
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp.assign(n+1, -1);
        return fun(n);
    }
private:
    int fun(int n) {
        if (n == 0) 
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (dp[n] != -1) 
            return dp[n];
        return dp[n] =  fun(n-1) + fun(n-2);
    }
};