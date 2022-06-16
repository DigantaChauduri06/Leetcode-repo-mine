/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const mp = new Map();
    for (let i = 0;i < nums.length;i++) {
        let rem = target - nums[i];
        if (mp.has(rem)) {
            return [i, mp.get(rem)];
        }
        mp.set(nums[i], i);
    }
    return [-1,-1];
};