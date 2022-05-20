class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        return breakingPoint(nums);
    }
private:
    int breakingPoint(vector<int> &nums) {
        int si = 0, ei = nums.size() - 1;
        while (si < ei) {
            int m = si + (ei - si) / 2;
            if (nums[m] < nums[m+1]) {
                si = m +1;
            } else {
                ei = m;
            }
        }
        return si;
    }
};