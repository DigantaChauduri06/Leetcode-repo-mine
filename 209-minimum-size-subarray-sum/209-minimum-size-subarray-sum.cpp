class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size() - 1;
        int cur = 0;
        int mn = INT_MAX;
        while (i <= n) {
            cur += nums[i++];
            while (cur >= k) {
                mn = min(mn, (i - j));
                cur -= nums[j++];
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
};