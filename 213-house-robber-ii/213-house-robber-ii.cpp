class Solution {
    vector<int> dp1, dp2;
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        dp1.assign(n+1, -1);
        dp2.assign(n+1, -1);
        return max(fun(nums, 0, n-2, dp1), fun(nums, 1,n-1, dp2));
    }
private:
    int fun(vector<int>& nums, int si, int ei, vector<int> &dp) {
        if (si > ei) return 0;
        if (dp[si] != -1) 
            return dp[si];
        return dp[si] = max(nums[si]+fun(nums, si+2, ei, dp), fun(nums, si+1, ei, dp));
    }
};