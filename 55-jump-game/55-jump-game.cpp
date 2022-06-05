class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = size(nums) - 1;
        for (int i = size(nums)-2;i >= 0;i--) {
            if ((nums[i] + i) >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};