class Solution {
    int n;
    vector<int> cache;
public:
    int rob(vector<int>& nums) {
        n = size(nums);
        cache.assign(n+1, -1);
        return fun(nums, 0);      
    }
private:
    int fun(vector<int> &nums, int i) {
        if (i >= n) 
            return 0;
        if (cache[i] != -1) 
            return cache[i];
        return cache[i] = max(fun(nums, i+1), nums[i]+fun(nums, i+2));
    }
};

//[2,1,1,2]

