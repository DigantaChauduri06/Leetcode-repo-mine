class Solution {
    int ans;
public:
    int subsetXORSum(vector<int>& nums) {
        this->ans = 0;
        vector<int> temp;
        fun(nums, temp);
        return ans;
    }
private:
    int xorSum(vector<int> &nums) {
        int x = 0;
        for (auto &n : nums) {
            x = n ^ x;
        }
        return x;
    }
    void fun(vector<int> &nums, vector<int> &temp, int i = 0) {
        if (i == nums.size()) {
            ans += xorSum(temp);
            return;
        }
        //pick
        temp.push_back(nums[i]);
        fun(nums, temp, i+1);
        temp.pop_back();
        //not-pick
        fun(nums, temp, i+1);
    }
};