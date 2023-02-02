class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for (int i = 0;i < nums.size();i++) {
            int remaining = target - nums[i];
            if (mpp.find(remaining) != mpp.end()) return {i, mpp[remaining]};
            mpp[nums[i]] = i; 
        }
        return {-1,-1};
    }
};