class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        sort(begin(nums), end(nums));
        fun(nums, st, temp);
        return vector<vector<int>>(st.begin(), st.end());
    }
private:
        void fun(vector<int> &nums,set<vector<int>> &ans, vector<int> &arr, int i = 0) {
        if (i == nums.size()) {
            // sort(begin(arr),end(arr));
            ans.insert(arr);
            return;
        }
        // pick
        arr.push_back(nums[i]);
        fun(nums, ans, arr, i+1);
        arr.pop_back();
        // not - pick
        fun(nums, ans, arr, i+1);
    }
};