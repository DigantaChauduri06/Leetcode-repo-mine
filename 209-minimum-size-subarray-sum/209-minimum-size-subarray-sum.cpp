class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        unordered_map<int, int> mpp;
        int cur = 0;
        int i = 0;
        int mn = INT_MAX;
        int n = nums.size();
        while (i < n) {
            cur += nums[i];
            if (cur == k) {
                mn = min(mn, (i + 1));
            }
            if (nums[i] == k) return 1;
            int rem = (cur - k);
            if (mpp.find(rem) != mpp.end()) {
                int idx = mpp[rem];
                mn = min(mn, (i - idx));
            }
            if (cur > k) {
                int j = 0;
                int curj = cur;
                while (j < n && (curj) > k) {
                    mn = min(mn, (i - j + 1));
                    curj -= nums[j++];
                }
            }
            mpp[cur] = i;
            i++;
        }
        return (mn == INT_MAX) ? 0 : mn;
    }
};