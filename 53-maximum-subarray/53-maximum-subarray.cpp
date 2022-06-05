class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ei = 0;
        int cur = 0, mx = INT_MIN;
        while (ei < size(nums)) {
            cur += nums[ei++];
            mx = max({cur, mx});
            if (cur < 0) {
                cur = 0;
            }
        }
        return mx;
    }
};