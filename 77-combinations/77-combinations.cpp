class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        for (int i = 1;i <= n;i++) {
            nums.push_back(i);
        }
        vector<int> temp;
        fun(nums, ans, temp,0, k);
        return ans;
    }
private:
    void fun(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp,int i, int k) {
        if (i== size(nums)) {
            if (size(temp) == k) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[i]);
        fun(nums, ans, temp, i+1, k);
        temp.pop_back();
        fun(nums, ans, temp, i+1, k);
    }
};