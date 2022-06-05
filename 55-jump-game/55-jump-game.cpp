class Solution {
    vector<int> dp;
public:
    bool canJump(vector<int>& nums, int i = 0) {
        dp.assign(size(nums)+1, -1);
        return func(nums, i);
    }
private:
    bool func(vector<int> &nums, int i) {
        if (i >= size(nums) - 1) return true;
        int curJump = nums[i];
        if (dp[i] != -1) return dp[i];
        if (curJump == 0) return dp[i] = false;
        for (int j = 1;j <= curJump;j++) {
            int jump = i+j;
            if (jump > size(nums) -1) return dp[i] = false;
            if (func(nums, jump)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
};