/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const mp = new Map();
    let i = 0, j = 0;
    let cur = 0, mx = 0;
    while (i < s.length) {
        if (!mp.has(s[i])) {
            mp.set(s[i]);
            cur = i - j + 1;
            i++;
            mx = Math.max(cur, mx);
            
        } else {
            mp.delete(s[j]);
            j++;
        }
    }
    return mx;
    
};