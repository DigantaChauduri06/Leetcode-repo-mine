class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(begin(nums), end(nums));
        fun(nums, ans, temp);
        return ans;
    }
private:
        void fun(vector<int> &nums,vector<vector<int>> &ans, vector<int> &arr, int i = 0) {
        if (i == nums.size()) {
            ans.push_back(arr);
            return;
        }
        // pick
        arr.push_back(nums[i]);
        fun(nums, ans, arr, i+1);
        arr.pop_back();
        // not - pick
        // remove duplicate
        while ((i+1) < nums.size() && nums[i] == nums[i+1]) i++;
        fun(nums, ans, arr, i+1);
    }
};