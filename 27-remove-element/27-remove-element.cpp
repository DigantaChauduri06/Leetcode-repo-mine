class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int ele = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] != val) {
                swap(nums[cur++], nums[i]);
            } else ele++;
        }
        return nums.size() - ele;
    }
};