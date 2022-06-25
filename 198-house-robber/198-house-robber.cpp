class Solution {
    int n;
    vector<int> dp;
public:
    int rob(vector<int>& nums) {
        n = size(nums);
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        dp.assign(n+1,-1);
        return fun(nums);      
    }
private:
    int fun(vector<int> &nums) {
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 1;i < n;i++) {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[n];
    }
};

/*
        if (i >= n) 
            return 0;
        if (cache[i] != -1) 
            return cache[i];
        return cache[i] = max(fun(nums, i+1), nums[i]+fun(nums, i+2));


*/

