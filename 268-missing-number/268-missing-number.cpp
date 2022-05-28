class Solution {
using ll = long long;
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int original = (n *(n + 1)) / 2;
        ll sum = 0;
        for (auto &num : nums) {
            sum += num;
        }
        return original - sum;
    }
};