class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        fun(nums, ans, 0);
        return ans;
    }
private:
    void fun(vector<int> &nums, vector<vector<int>> &ans, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx;i < nums.size();i++) {
            swap(nums[i], nums[idx]);
            fun(nums, ans, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};