class Solution {
public:
    int numberOfSteps(int num) {
        long long steps = 0;
        while (num > 0) {
            if (num&1) {
                num--;
            } else {
                num = num >> 1;
            }
            steps++;
        }
        return steps;
    }
};