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
        int prev1 = 0, prev2 = nums[0];
        int cur = prev2;
        for (int i = 1;i < n;i++) {
            // dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
            cur = max(cur, prev1 + nums[i]);
            prev1 = prev2;
            prev2 = cur;
        }
        return cur;
    }
};

/*
        if (i >= n) 
            return 0;
        if (cache[i] != -1) 
            return cache[i];
        return cache[i] = max(fun(nums, i+1), nums[i]+fun(nums, i+2));


*/

