class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int pivot = breakingPoint(nums);
        if (pivot == -1) {
            return binary_search(nums, target, 0, nums.size() - 1);
        }
        if (nums[pivot] == target) return pivot;
        int left = binary_search(nums, target, 0, pivot - 1);
        return (left == -1) ? binary_search(nums, target, pivot + 1, nums.size() - 1) : left;
    }
private:
    int binary_search(vector<int> &nums, int k, int i, int j) {
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (nums[m] == k) return m;
            if (nums[m] > k) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return -1;
    }
    int breakingPoint(vector<int> &nums) {
        int pivot = -1;
        int f = nums.front(), l = nums.back();
        int i = 0, j = nums.size() - 1;
        if (nums.size() >= 2 && l < nums[nums.size() - 2]) return nums.size() - 1;
        if (f <= l) return 0;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if ((m != 0 && m != nums.size() - 1) && (nums[m] < nums[m - 1] && nums[m] < nums[m+1])) return m;
            if (nums[m] > f && nums[m] < l) {
                return -1;
            }
            if (nums[m] > f && nums[m] > l) {
                i = m + 1;
            } else {
                j = m;
            }
        }
        return -1;
        
    }
};