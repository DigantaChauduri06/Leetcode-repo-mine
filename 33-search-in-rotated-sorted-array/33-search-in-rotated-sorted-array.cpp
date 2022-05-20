class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = breakingPoint(nums);
        if (pivot == -1) {
            return binary_search(nums, target, 0,nums.size());
        }
        if (nums[pivot] == target) return pivot;
        int ls = binary_search(nums, target, 0, pivot); 
        return ls == -1 ? binary_search(nums, target, pivot+1, nums.size() - 1) : ls;
    }
private:
    int binary_search(vector<int>& nums, int k, int si, int ei) {
        while (si <= ei) {
            int m = si + (ei - si) / 2;
            if (nums[m] == k) return m;
            else if (nums[m] < k) si = m + 1;
            else ei = m - 1;
        }
        return -1;
    }
    int breakingPoint(vector<int> &nums) {
        int si = 0, ei = nums.size() - 1;
        int pos = -1;
        while (si <= ei) {
            int m = si + (ei - si) / 2;
            if (nums[m] <= nums.front() && nums[m] <= nums.back()) {
                pos = m;
                ei = m - 1;
            } else {
                si = m + 1;
            }
        }
        return pos;
    }
};